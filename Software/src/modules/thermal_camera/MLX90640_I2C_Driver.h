#ifndef MLX90640_I2C_DRIVER_H
#define MLX90640_I2C_DRIVER_H

#include <stdint.h>
#include "hardware/i2c.h"
#include "MLX90640_API.h"

// I2C defines
#define I2C_ADDR 0x33

#define I2C1_PORT i2c1
#define I2C1_SDA 26
#define I2C1_SCL 27

void MLX90640_I2CInit(void);

int MLX90640_I2CRead(uint8_t slaveAddr, uint16_t startAddress, uint16_t nWords, uint16_t *data);

int MLX90640_I2CWrite(uint8_t slaveAddr, uint16_t writeAddress, uint16_t data);

void MLX90640_Delay(int time_ms);

int MLX90640_I2CGeneralReset();

#endif /* MLX90640_I2C_DRIVER_H */
