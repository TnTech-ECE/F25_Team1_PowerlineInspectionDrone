/*
 * thermal_detection.c
 *
 *  Created on: April 13, 2026
 *      Author: Daniel Attih
 */

#include <stdio.h>
#include "pico/stdlib.h"

#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"
#include "thermal_detection.h"

#define I2C_ADDR 0x33

static uint16_t eeprom[832];
static paramsMLX90640 params;
static bool initialized = false;

bool thermal_read_full_frame(float *full_temp)
{
    static uint16_t frame[834];
    static float temp[768];

    // One-time initialization
    if (!initialized)
    {
        if (MLX90640_I2CRead(I2C_ADDR, 0x2400, 832, eeprom) != 0)
        {
            printf("EEPROM read failed\n");
            return false;
        }

        if (MLX90640_ExtractParameters(eeprom, &params) != 0)
        {
            printf("Parameter extraction failed\n");
            return false;
        }

        initialized = true;
        printf("Thermal camera initialized\n");
    }

    // Clear full frame
    for (int i = 0; i < 768; i++)
    {
        full_temp[i] = -999.0f;
    }

    // Read two subpages
    for (int pass = 0; pass < 2; pass++)
    {
        int frame_result = MLX90640_GetFrameData(I2C_ADDR, frame);
        if (frame_result < 0)
        {
            printf("Frame read failed\n");
            return false;
        }

        float ta = MLX90640_GetTa(frame, &params);
        float tr = ta - 8.0f;
        float emissivity = 0.95f;

        for (int i = 0; i < 768; i++)
        {
            temp[i] = -999.0f;
        }

        MLX90640_CalculateTo(frame, &params, emissivity, tr, temp);

        // Merge into full frame
        for (int i = 0; i < 768; i++)
        {
            if (temp[i] > -500.0f)
            {
                full_temp[i] = temp[i];
            }
        }
    }

    return true;
} 

float thermal_compute_frame_average(float *full_temp)
{
    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < 768; i++)
    {
        if (full_temp[i] > -500.0f)
        {
            sum += full_temp[i];
            count++;
        }
    }

    if (count == 0)
    {
        return 0.0f;
    }

    return sum / count;
}

bool thermal_is_hot_pixel(float temp, float frame_avg, float threshold)
{
    if (temp <= -500.0f)
    {
        return false;
    }

    return (temp > (frame_avg + threshold));
}

bool thermal_find_best_cluster(float *full_temp,
                               float frame_avg,
                               float threshold,
                               int *best_cluster_size,
                               float *best_cluster_max_temp)
{
    static bool visited[768];
    static int stack[768];

    // clear visited array
    for (int i = 0; i < 768; i++)
    {
        visited[i] = false;
    }

    *best_cluster_size = 0;
    *best_cluster_max_temp = -999.0f;

    float best_score = -1.0f;

    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 32; col++)
        {
            int idx = row * 32 + col;

            if (thermal_is_hot_pixel(full_temp[idx], frame_avg, threshold) && !visited[idx])
            {
                int stack[768];
                int top = -1;

                int cluster_size = 0;
                float cluster_max_temp = full_temp[idx];

                stack[++top] = idx;
                visited[idx] = true;

                while (top >= 0)
                {
                    int current_idx = stack[top--];
                    int current_row = current_idx / 32;
                    int current_col = current_idx % 32;

                    cluster_size++;

                    if (full_temp[current_idx] > cluster_max_temp)
                    {
                        cluster_max_temp = full_temp[current_idx];
                    }

                    for (int dr = -1; dr <= 1; dr++)
                    {
                        for (int dc = -1; dc <= 1; dc++)
                        {
                            if (dr == 0 && dc == 0)
                            {
                                continue;
                            }

                            int neighbor_row = current_row + dr;
                            int neighbor_col = current_col + dc;

                            if (neighbor_row < 0 || neighbor_row >= 24 ||
                                neighbor_col < 0 || neighbor_col >= 32)
                            {
                                continue;
                            }

                            int neighbor_idx = neighbor_row * 32 + neighbor_col;

                            if (!visited[neighbor_idx] &&
                                thermal_is_hot_pixel(full_temp[neighbor_idx], frame_avg, threshold))
                            {
                                visited[neighbor_idx] = true;
                                stack[++top] = neighbor_idx;
                            }
                        }
                    }
                }

                if (cluster_size >= 3)
                {
                    float hotspot_strength = cluster_max_temp - frame_avg;
                    float score = hotspot_strength + cluster_size;

                    if (score > best_score)
                    {
                        best_score = score;
                        *best_cluster_size = cluster_size;
                        *best_cluster_max_temp = cluster_max_temp;
                    }
                }
            }
        }
    }

    return (*best_cluster_size >= 3);
}