#ifndef SD_LOGGER_H_
#define SD_LOGGER_H_

#include <stdbool.h>

// Initialize SD card and open log file
bool sd_logger_init(int day, int month, int year);

// Log arm event
void sd_log_arm_event(const char *event_str,
                      int hour, int min, int sec, int am_pm,
                      int day, int month, int year,
                      double lat, double lon);

void sd_log_thermal_event(const char *event_str,
                          int hour, int min, int sec, int am_pm,
                          int day, int month, int year,
                          double lat, double lon,
                          int cluster_size,
                          float hotspot_strength,
                          float score);
#endif // SD_LOGGER_H_