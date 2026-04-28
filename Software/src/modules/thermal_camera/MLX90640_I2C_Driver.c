#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "MLX90640_API.h"
#include "MLX90640_I2C_Driver.h"

static int mlx90640_read_words_raw(uint8_t addr, uint16_t start_reg, uint16_t *data, int word_count) {
    uint8_t reg_buf[2];
    reg_buf[0] = (start_reg >> 8) & 0xFF;
    reg_buf[1] = start_reg & 0xFF;

    int ret = i2c_write_blocking(I2C1_PORT, addr, reg_buf, 2, true);
    if (ret < 0) return ret;

    uint8_t rx_buf[word_count * 2];
    ret = i2c_read_blocking(I2C1_PORT, addr, rx_buf, word_count * 2, false);
    if (ret < 0) return ret;

    for (int i = 0; i < word_count; i++) {
        data[i] = ((uint16_t)rx_buf[2 * i] << 8) | rx_buf[2 * i + 1];
    }

    return 0;
}

static int mlx90640_read_words_chunked(uint8_t addr, uint16_t start_reg, uint16_t *data, int total_words) {
    const int chunk_size = 32;
    int offset = 0;

    while (offset < total_words) {
        int words_this_time = chunk_size;
        if (offset + words_this_time > total_words) {
            words_this_time = total_words - offset;
        }

        int ret = mlx90640_read_words_raw(addr, start_reg + offset, &data[offset], words_this_time);
        if (ret < 0) {
            return ret;
        }

        offset += words_this_time;
    }

    return 0;
}

/* Functions expected by mlx90640_api.c */

int MLX90640_I2CRead(uint8_t slaveAddr, uint16_t startAddress, uint16_t nMemAddressRead, uint16_t *data) {
    int ret = mlx90640_read_words_chunked(slaveAddr, startAddress, data, nMemAddressRead);
    return (ret == 0) ? 0 : -1;
}

int MLX90640_I2CWrite(uint8_t slaveAddr, uint16_t writeAddress, uint16_t data) {
    uint8_t buf[4];
    buf[0] = (writeAddress >> 8) & 0xFF;
    buf[1] = writeAddress & 0xFF;
    buf[2] = (data >> 8) & 0xFF;
    buf[3] = data & 0xFF;

    int ret = i2c_write_blocking(I2C1_PORT, slaveAddr, buf, 4, false);
    return (ret < 0) ? -1 : 0;
}

void MLX90640_Delay(int time_ms) {
    sleep_ms(time_ms);
}


int MLX90640_I2CGeneralReset() {
    // Optional: not required for Pico
}

void MLX90640_I2CInit(void) {
    i2c_init(I2C1_PORT, 100 * 1000);
    gpio_set_function(I2C1_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C1_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C1_SDA);
    gpio_pull_up(I2C1_SCL);
}