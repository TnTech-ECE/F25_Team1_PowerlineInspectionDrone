#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "hardware/pio.h"
#include "ff.h"
#include "tf_card.h"

#include "sd_logger.h"

// Static file objects
static FATFS fs;
static FIL fil;
//static FRESULT fr; // Result code
//static UINT bw; // Bytes written
static bool initialized = false;

bool sd_logger_init(int day, int month, int year)
{
    FRESULT fr;

    pico_fatfs_spi_config_t config = {
        spi1,
        100 * KHZ,
        10 * MHZ,
        12, // MISO
        13, // CS
        10, // SCK
        11, // MOSI
        true
    };

    bool native_spi = pico_fatfs_set_config(&config);
    if (!native_spi) {
        pico_fatfs_config_spi_pio(pio0, 0);
    }

    fr = f_mount(&fs, "", 1);
    if (fr != FR_OK) {
        printf("SD mount failed: %d\n", fr);
        return false;
    }

    printf("SD mounted\n");


    int full_year = year + 2000;

    char filename[32];
    snprintf(filename, sizeof(filename),
             "%04d-%02d-%02d.txt",
             full_year, month, day);

    fr = f_open(&fil, filename, FA_OPEN_APPEND | FA_WRITE);
    if (fr != FR_OK) {
        printf("File open failed: %d\n", fr);
        return false;
    }

    printf("Logging to file: %s\n", filename);

    initialized = true;
    return true;
}

void sd_log_arm_event(const char *event_str,
                      int hour, int min, int sec, int am_pm,
                      int day, int month, int year,
                      double lat, double lon)
{
    if (!initialized) return;

    char line[128];
    UINT bw;

    int full_year = year + 2000;

    int len = snprintf(line, sizeof(line),
        "Arm moved to %s at Time: %02d:%02d:%02d %s | Date: %02d/%02d/%04d\r\n"
        "GPS Lat: %.6f | Lon: %.6f\r\n\r\n",
        event_str,
        hour, min, sec,
        am_pm ? "PM" : "AM",
        month, day, full_year,
        lat, lon
    );

    FRESULT fr = f_write(&fil, line, len, &bw);

    if (fr != FR_OK || bw != (UINT)len) {
        printf("SD write failed: %d\n", fr);
    } else {
        printf("Logged to SD\n");
    }

    f_sync(&fil);
}

void sd_log_thermal_event(const char *event_str,
                          int hour, int min, int sec, int am_pm,
                          int day, int month, int year,
                          double lat, double lon,
                          int cluster_size,
                          float hotspot_strength,
                          float score)
{
    if (!initialized) return;

    char line[192];
    UINT bw;

    int full_year = year + 2000;

    int len = snprintf(line, sizeof(line),
        "Thermal event: %s at Time: %02d:%02d:%02d %s | Date: %02d/%02d/%04d\r\n"
        "GPS Lat: %.6f | Lon: %.6f\r\n"
        "Cluster Size: %d | Hotspot Strength: %.2f | Score: %.2f\r\n\r\n",
        event_str,
        hour, min, sec,
        am_pm ? "PM" : "AM",
        day, month, full_year,
        lat, lon,
        cluster_size,
        hotspot_strength,
        score
    );

    FRESULT fr = f_write(&fil, line, len, &bw);

    if (fr != FR_OK || bw != (UINT)len)
    {
        printf("SD thermal write failed: %d\n", fr);
    }
    else
    {
        printf("Thermal event logged to SD\n");
    }

    f_sync(&fil);
}