#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/i2c.h"

#include "FreeRTOS.h"
#include "task.h"

#include "DS3231.h"
#include "mg90s.h"
#include "gps.h"
#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"
#include "sd_logger.h"
#include "thermal_detection.h"

/*********** DEFINES FOR TASK 1. ARM CONTROL******************/
#define SWITCH_GPIO             28

#define NO_CMD                  0
#define RETRACT_CMD             1
#define EXTEND_CMD              2

#define SWITCH_POLL_DELAY_MS    20
#define SWITCH_HOLD_TIME_MS     1000
#define SERVO_MOVE_TIME_MS      1000

#define SERVO_RETRACT_US        500 // 0 degrees
#define SERVO_EXTEND_US         1500 // 90 degrees
#define SERVO_MAX_US            2500 // 180 degrees

/*********** DEFINES FOR TASK 2. THERMAL DETECTION******************/
#define REQUIRED_GOOD_FRAMES    3
#define REQUIRED_BAD_FRAMES     3
#define LARGE_THRESHOLD         15.0f

// -------------------- Task Prototypes --------------------
void vArmControlTask(void *pvParameters);
void vThermalDetectionTask(void *pvParameters);

// -------------------- Global/Shared Objects --------------------
MG90S_Servo servo = {
    .gpio = 22,   // GPIO pin for PWM output
};

int main()
{
    stdio_init_all();
    sleep_ms(15000); // Wait for the terminal to be ready for debugging

    // RTC initialization
    DS3231_Init();
    DS3231_SetTime(3, 05, 30, 2);
    DS3231_SetDate(04, 15, 26);

    // Servo initialization
    MG90S_Initialize(&servo);

    // GPS initialization
    gps_initialize();

    // Thermal camera initialization
    MLX90640_I2CInit();

    // Slide switch initialization
    gpio_init(SWITCH_GPIO);
    gpio_set_dir(SWITCH_GPIO, GPIO_IN);

    DS3231_ReadDate();
    if (!sd_logger_init(day, month, year))
    {
        printf("SD logger init failed\n");
    } else{
        printf("SD logger initialized\n");
    }

    // -------------------- Create Tasks --------------------
    xTaskCreate(
        vArmControlTask,         // Task function
        "ArmControlTask",        // Task name
        256,                     // Stack depth
        NULL,                    // Task parameters
        1,                       // Task priority
        NULL                     // Task handle
    );

    xTaskCreate(
        vThermalDetectionTask,   // Task function
        "ThermalDetectionTask",  // Task name
        4096,                    // Stack depth
        NULL,                    // Task parameters
        1,                       // Task priority
        NULL                     // Task handle
    );

    // Start scheduler
    vTaskStartScheduler();

    // Should never get here
    while (true)
    {}
}

// -------------------- Task Definitions --------------------
void vArmControlTask(void *pvParameters)
{

    // Command flag to track pending commands
    uint8_t cmd_flag = NO_CMD;

    // Variables to track switch state for debouncing
    bool prev_state;
    bool curr_state;
    bool confirm_state;

    // GPS data variables
    double lat = 0.0;
    double lon = 0.0;
    char gps_time[16] = {0};

    // Read initial confirmed switch state
    prev_state = gpio_get(SWITCH_GPIO);

    for (;;)
    {
        // Update GPS data
        gps_update();

        // Only look for a new command if none is pending
        if (cmd_flag == NO_CMD)
        {
            // Read current switch state
            curr_state = gpio_get(SWITCH_GPIO);

            // Candidate change detected.
            if (curr_state != prev_state)
            {
                printf("\r\nSwitch change detected, confirming...\r\n");
                // Hold-time confirmation
                vTaskDelay(pdMS_TO_TICKS(SWITCH_HOLD_TIME_MS));

                // read switch again to confirm stable state
                confirm_state = gpio_get(SWITCH_GPIO);

                // Accept only if switch stayed in the new state
                if (confirm_state == curr_state)
                {
                    printf("Switch confirmed stable\r\n");

                    if (confirm_state == true)
                    {
                        cmd_flag = EXTEND_CMD;
                    }
                    else
                    {
                        cmd_flag = RETRACT_CMD;
                    }

                    // Update only after confirmed stable state
                    prev_state = confirm_state;
                }
                else
                {
                    printf("Switch confirmation failed\r\n");

                    cmd_flag = NO_CMD;
                }
            }
        }

        // Execute confirmed command fully before checking switch again
        switch (cmd_flag)
        {
            case EXTEND_CMD:
                printf("CMD: EXTEND detected\r\n");

                MG90S_SetPulseWidthUs(&servo, SERVO_EXTEND_US);

                // Give servo time to move
                vTaskDelay(pdMS_TO_TICKS(SERVO_MOVE_TIME_MS));

                // Read RTC time and date for logging
                DS3231_ReadTime();
                DS3231_ReadDate();

                printf("Arm moved to 90 degrees at Time: %02d:%02d:%02d %s | Date: %02d/%02d/%02d\r\n", hours, minutes, seconds, am_pm ? "PM" : "AM", year+2000, month, day);

                // Get latest GPS fix for logging
                if (gps_get_latest_fix(&lat, &lon, gps_time, sizeof(gps_time)))
                {
                    printf("GPS Lat: %.6f | Lon: %.6f\r\n", lat, lon);
                }
                else
                {
                    lat = 0.0;
                    lon = 0.0;
                    printf("GPS fix not available\r\n");
                }

                // SD log
                sd_log_arm_event("Arm Extended", hours, minutes, seconds, am_pm, day, month, year, lat, lon);

                cmd_flag = NO_CMD;
                break;

            case RETRACT_CMD:
                printf("CMD: RETRACT detected\r\n");

                MG90S_SetPulseWidthUs(&servo, SERVO_RETRACT_US);

                // Give servo time to move
                vTaskDelay(pdMS_TO_TICKS(SERVO_MOVE_TIME_MS));
                
                // Read RTC time and date for logging
                DS3231_ReadTime();
                DS3231_ReadDate();

                printf("Arm moved to 0 degrees at Time: %02d:%02d:%02d %s | Date: %02d/%02d/%02d\r\n", hours, minutes, seconds, am_pm ? "PM" : "AM", year+2000, month, day);

                // Get latest GPS fix for logging
                if (gps_get_latest_fix(&lat, &lon, gps_time, sizeof(gps_time)))
                {
                    printf("GPS Lat: %.6f | Lon: %.6f\r\n", lat, lon);
                }
                else
                {
                    printf("GPS fix not available\r\n");
                }

                // SD log
                sd_log_arm_event("Arm Retracted", hours, minutes, seconds, am_pm, day, month, year, lat, lon);

                cmd_flag = NO_CMD;
                break;

            case NO_CMD:
            default:
                break;
        }

        vTaskDelay(pdMS_TO_TICKS(SWITCH_POLL_DELAY_MS));
    }
}


void vThermalDetectionTask(void *pvParameters)
{
    printf("Thermal task started\r\n");

    static float full_temp[768];
    int frame_count = 0;

    bool anomaly_active = false;

    int good_frame_count = 0;
    int bad_frame_count = 0;

    int current_cluster_size = 0;
    float current_cluster_max_temp = 0.0f;
    float current_hotspot_strength = 0.0f;
    float current_score = 0.0f;

    float best_score = -1.0f;
    float best_hotspot_strength = 0.0f;
    int best_cluster_size = 0;

    double lat = 0.0;
    double lon = 0.0;
    char gps_time[16] = {0};

    for (;;)
    {
        gps_update();

        if (thermal_read_full_frame(full_temp))
        {
            printf("Thermal frame read successfully\r\n");

            float min_temp = 1000.0f;
            float max_temp = -1000.0f;

            for (int i = 0; i < 768; i++)
            {
                if (full_temp[i] > -500.0f)
                {
                    if (full_temp[i] < min_temp) min_temp = full_temp[i];
                    if (full_temp[i] > max_temp) max_temp = full_temp[i];
                }
            }

            float center = full_temp[12 * 32 + 16];
            float frame_avg = thermal_compute_frame_average(full_temp);

            bool cluster_found = thermal_find_best_cluster(
                full_temp,
                frame_avg,
                LARGE_THRESHOLD,
                &current_cluster_size,
                &current_cluster_max_temp
            );

            printf("Thermal Frame %d | Min: %.2f | Max: %.2f | Avg: %.2f | Center: %.2f\r\n", frame_count++, min_temp, max_temp, frame_avg, center);

            if (!anomaly_active)
            {
                // -------- SEARCH MODE  (searching for anomalies) --------
                if (cluster_found)
                {
                    good_frame_count++;

                    printf("Candidate hot cluster found | Good frames: %d\r\n", good_frame_count);

                    if (good_frame_count >= REQUIRED_GOOD_FRAMES)
                    {
                        anomaly_active = true;
                        bad_frame_count = 0;

                        current_hotspot_strength = current_cluster_max_temp - frame_avg;
                        current_score = current_hotspot_strength + current_cluster_size;

                        best_score = current_score;
                        best_hotspot_strength = current_hotspot_strength;
                        best_cluster_size = current_cluster_size;

                        printf("Anomaly tracking started | Best Size: %d | Best Strength: %.2f | Best Score: %.2f\r\n", best_cluster_size, best_hotspot_strength, best_score);
                    }
                }
                else
                {
                    good_frame_count = 0;
                    printf("No valid hot cluster found\r\n");
                }
            }
            else
            {
                // -------- TRACKING MODE (tracking detected anomalies) --------
                if (cluster_found)
                {
                    bad_frame_count = 0;

                    current_hotspot_strength = current_cluster_max_temp - frame_avg;
                    current_score = current_hotspot_strength + current_cluster_size;

                    printf("Tracking anomaly | Current Size: %d | Current Strength: %.2f | Current Score: %.2f\r\n",current_cluster_size, current_hotspot_strength, current_score);

                    if (current_score > best_score)
                    {
                        best_score = current_score;
                        best_hotspot_strength = current_hotspot_strength;
                        best_cluster_size = current_cluster_size;

                        printf("Best observation updated | Best Size: %d | Best Strength: %.2f | Best Score: %.2f\r\n", best_cluster_size, best_hotspot_strength, best_score);
                    }
                }
                else
                {
                    bad_frame_count++;

                    printf("Tracking lost for this frame | Bad frames: %d\r\n", bad_frame_count);

                    if (bad_frame_count >= REQUIRED_BAD_FRAMES)
                    {
                        DS3231_ReadTime();
                        DS3231_ReadDate();

                        printf("Anomaly track ended | Final Best Size: %d | Final Best Strength: %.2f | Final Best Score: %.2f\r\n", best_cluster_size, best_hotspot_strength, best_score);

                        printf("Thermal event at Time: %02d:%02d:%02d %s | Date: %02d/%02d/%04d\r\n", hours, minutes, seconds, am_pm ? "PM" : "AM", month, day, year + 2000);

                        if (gps_get_latest_fix(&lat, &lon, gps_time, sizeof(gps_time)))
                        {
                            printf("GPS Lat: %.6f | Lon: %.6f\r\n", lat, lon);
                        }
                        else
                        {
                            lat = 0.0;
                            lon = 0.0;
                            printf("GPS fix not available\r\n");
                        }

                        sd_log_thermal_event("Anomaly Found", hours, minutes, seconds, am_pm, day, month, year, lat, lon, best_cluster_size, best_hotspot_strength, best_score);

                        // Reset tracking state
                        anomaly_active = false;
                        good_frame_count = 0;
                        bad_frame_count = 0;

                        best_score = -1.0f;
                        best_hotspot_strength = 0.0f;
                        best_cluster_size = 0;
                    }
                }
            }
        }

        vTaskDelay(pdMS_TO_TICKS(200));
    }
}