/*
 * thermal_detection.h
 *
 *  Created on: April 13, 2026
 *      Author: Daniel Attih
 */

#ifndef THERMAL_DETECTION_H_
#define THERMAL_DETECTION_H_

#include <stdbool.h>

bool thermal_read_full_frame(float *full_temp);

float thermal_compute_frame_average(float *full_temp);

bool thermal_is_hot_pixel(float temp, float frame_avg, float threshold);

bool thermal_find_best_cluster(float *full_temp,
                               float frame_avg,
                               float threshold,
                               int *best_cluster_size,
                               float *best_cluster_max_temp);

#endif /* THERMAL_DETECTION_H_ */