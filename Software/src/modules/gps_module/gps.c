/*
 * gps.c
 *
 *  Created on: March 30, 2026
 *      Author: Daniel Attih
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "gps.h"

static char sentence[128];
static int sentence_idx = 0;

static double latest_lat = 0.0;
static double latest_lon = 0.0;
static char latest_time[16] = {0};
static bool latest_fix_valid = false;

bool parse_gprmc(char *sentence, char *time_str, char *status, char *lat, char *lat_dir, char *lon, char *lon_dir)
{
    // Skip leading CR/LF/spaces if present
    while (*sentence == '\r' || *sentence == '\n' || *sentence == ' ')
    {
        sentence++;
    }

    // Accept both GPRMC and GNRMC
    if (strncmp(sentence, "$GPRMC", 6) != 0 && strncmp(sentence, "$GNRMC", 6) != 0)
    {
        return false;
    }

    char *token;
    int field = 0;

    token = strtok(sentence, ",");

    while (token != NULL)
    {
        switch (field)
        {
            case 1:
                strcpy(time_str, token);
                break;
            case 2:
                strcpy(status, token);
                break;
            case 3:
                strcpy(lat, token);
                break;
            case 4:
                strcpy(lat_dir, token);
                break;
            case 5:
                strcpy(lon, token);
                break;
            case 6:
                strcpy(lon_dir, token);
                break;
        }

        token = strtok(NULL, ",");
        field++;
    }

    return true;
}

double nmea_to_decimal(char *coord, char *direction) {
    double raw = atof(coord);

    int degrees = (int)(raw / 100);
    double minutes = raw - (degrees * 100);

    double decimal = degrees + (minutes / 60.0);

    // Apply direction
    if (direction[0] == 'S' || direction[0] == 'W') {
        decimal = -decimal;
    }

    return decimal;
}

void gps_initialize(void){
    // Set up our UART
    uart_init(UART_ID, BAUD_RATE);


    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART); // TX optional.
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    
    uart_set_hw_flow(uart1, false, false);

    // Set format
    uart_set_format(uart1, 8, 1, UART_PARITY_NONE);
}

void gps_update(void)
{
    while (uart_is_readable(UART_ID))
    {
        char c = uart_getc(UART_ID);

        // Ignore carriage return
        if (c == '\r')
        {
            continue;
        }

        if (c == '\n')
        {
            sentence[sentence_idx] = '\0';

            char time_str[16] = {0};
            char status[4] = {0};
            char lat[20] = {0};
            char lat_dir[4] = {0};
            char lon[20] = {0};
            char lon_dir[4] = {0};

            if (parse_gprmc(sentence, time_str, status, lat, lat_dir, lon, lon_dir))
            {
                if (status[0] == 'A')
                {
                    latest_lat = nmea_to_decimal(lat, lat_dir);
                    latest_lon = nmea_to_decimal(lon, lon_dir);

                    snprintf(latest_time, sizeof(latest_time), "%s", time_str);
                    latest_fix_valid = true;

                    //printf("Stored GPS fix: Time %s | Lat %.6f | Lon %.6f\r\n", latest_time, latest_lat, latest_lon);
                }
                else
                {
                    //printf("GPS sentence parsed, but no valid fix yet. Status=%s\r\n", status);
                }
            }

            sentence_idx = 0;
        }
        else
        {
            if (sentence_idx < (int)(sizeof(sentence) - 1))
            {
                sentence[sentence_idx++] = c;
            }
            else
            {
                // Overflow protection
                sentence_idx = 0;
            }
        }
    }
}

bool gps_get_latest_fix(double *lat_dec, double *lon_dec, char *time_str, size_t time_str_size)
{
    if (!latest_fix_valid)
    {
        return false;
    }

    if (lat_dec != NULL)
    {
        *lat_dec = latest_lat;
    }

    if (lon_dec != NULL)
    {
        *lon_dec = latest_lon;
    }

    if (time_str != NULL && time_str_size > 0)
    {
        snprintf(time_str, time_str_size, "%s", latest_time);
    }

    return true;
}