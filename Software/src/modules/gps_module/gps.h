/*
 * gps.h
 *
 *  Created on: March 30, 2026
 *      Author: Daniel Attih
 */

#ifndef GPS_H_
#define GPS_H_

#include <stdbool.h>
#include <stddef.h>

#define UART_ID uart1
#define BAUD_RATE 9600

#define UART_TX_PIN 4 //  PICO TX: gps RX goes to the pico's TX
#define UART_RX_PIN 5 // PICO RX: gps TX goes to the pico's RX

bool parse_gprmc(char *sentence, char *time_str, char *status, char *lat, char *lat_dir, char *lon, char *lon_dir);
double nmea_to_decimal(char *coord, char *direction);
void gps_initialize(void);

// Helper functions
void gps_update(void);
bool gps_get_latest_fix(double *lat_dec, double *lon_dec, char *time_str, size_t time_str_size);

#endif /* GPS_H_ */