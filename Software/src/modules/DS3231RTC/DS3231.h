/*
 * DS3231.h
 *
 *  Created on: March 3, 2026
 *      Author: Daniel Attih
 */


#ifndef DS3231_H_
#define DS3231_H_

#include <stdint.h>
#include <stdbool.h>
#include "hardware/i2c.h"
#include "hardware/gpio.h"

// I2C defines
#define I2C_PORT i2c0 // I2C0 is the default I2C peripheral on the Pico, using GPIO 0 and 1 for SDA and SCL respectively
#define I2C_SDA 0 // GPIO pin for I2C SDA
#define I2C_SCL 1 // GPIO pin for I2C SCL

// DS3231 7-bit I2C address on Pico SDK
#define DS3231_ADDR (0x68)

// Variables to hold time 
extern volatile uint8_t seconds, minutes, hours;

// Variables to hold date
extern volatile uint8_t day, month, year;

// Variable to hold AM/PM status for 12-hour mode
extern volatile uint8_t am_pm; // 0 = AM, 1 = PM

// Optional init to select which I2C peripheral to use
//void DS3231_Init(i2c_inst_t *i2c, uint sda_gpio, uint scl_gpio, uint32_t baudrate);

void DS3231_Init(void);

/****************************************************/
/*         Conversion for register reading         */ 
/**************************************************/
// Convert decimal to BCD
uint8_t dec_to_bcd(uint8_t dec);

// Convert BCD to decimal
uint8_t bcd_to_dec(uint8_t bcd);

/**************************/
/*         TIME          */ 
/********************** */
// Read time from DS3231
void DS3231_ReadTime(void);

// Set time on DS3231
void DS3231_SetTime(uint8_t h_s, uint8_t m_s, uint8_t s_s, uint8_t am_pm_flag);

/**************************/
/*         DATE          */
/************************/
// Read date from DS3231
void DS3231_ReadDate(void);

// Set date on DS3231
void DS3231_SetDate(uint8_t dy, uint8_t mth, uint8_t yr);

#endif /* INC_DS3231_H_ */