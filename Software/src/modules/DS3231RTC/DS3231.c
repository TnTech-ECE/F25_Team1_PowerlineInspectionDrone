/*
 * DS3231.c
 *
 *  Created on: March 3, 2026
 *      Author: Daniel Attih
 */

#include "DS3231.h"
#include <string.h>

// ---- module-level I2C context equivalet to the i2c handle on STM32 ----
static i2c_inst_t *ds_i2c = NULL;

volatile uint8_t seconds, minutes, hours;
volatile uint8_t day, month, year;

volatile uint8_t am_pm; // 0 = AM, 1 = PM

// ---- low-level I2C read/write functions ----
static bool ds3231_read_regs(uint8_t start_reg, uint8_t *dst, size_t len)
{
    if (!ds_i2c) return false;

    // Write register address, then read data (repeated start)
    if (i2c_write_blocking(ds_i2c, DS3231_ADDR, &start_reg, 1, true) < 0)
        return false;

    if (i2c_read_blocking(ds_i2c, DS3231_ADDR, dst, len, false) < 0)
        return false;

    return true;
}

static bool ds3231_write_regs(uint8_t start_reg, const uint8_t *src, size_t len)
{
    if (!ds_i2c) return false;

    // Buffer: [reg][data...]
    // len is small (3 bytes in your use), so stack buffer is fine.
    uint8_t buf[1 + 8];
    if (len > 8) return false;

    buf[0] = start_reg;
    memcpy(&buf[1], src, len);

    if (i2c_write_blocking(ds_i2c, DS3231_ADDR, buf, (int)(1 + len), false) < 0)
        return false;

    return true;
}


/****************************************************/
/*         Conversion for register reading         */ 
/**************************************************/ 
//---------------convert binary to decimal----------------------------
uint8_t bcd_to_dec(uint8_t bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

//---------------convert decmial to binary----------------------------
uint8_t dec_to_bcd(uint8_t dec)
{
    return ((dec / 10) << 4) | (dec % 10);
}


/**************************/
/*         INIT           */
/**************************/
/*
void DS3231_Init(i2c_inst_t *i2c, uint sda_gpio, uint scl_gpio, uint32_t baudrate)
{
    ds_i2c = i2c;

    // Configure I2C peripheral + pins
    i2c_init(ds_i2c, baudrate);
    gpio_set_function(sda_gpio, GPIO_FUNC_I2C);
    gpio_set_function(scl_gpio, GPIO_FUNC_I2C);
    gpio_pull_up(sda_gpio);
    gpio_pull_up(scl_gpio);
}
    */

void DS3231_Init(void)
{
    ds_i2c = I2C_PORT;

    // Configure I2C peripheral + pins
    i2c_init(ds_i2c, 400000); // Use a typical I2C baudrate
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);
}

/**************************/
/*         TIME          */ 
/************************/
//-----------------Read time from the DS3231 Module------------------------
void DS3231_ReadTime()
{
	uint8_t data[3]; // buffer to store the read data from the RTC
    if (!ds3231_read_regs(0x00, data, 3)) return; // read seconds, minutes, hours starting at reg 0x00

    // Time Convert BCD to decimal. Mask seconds bit 7 (CH clock halt)
    seconds = bcd_to_dec(data[0] & 0x7F);
    minutes = bcd_to_dec(data[1] & 0x7F);

    if (data[2] & 0x40) {
        // 12-hour mode
        hours = bcd_to_dec(data[2] & 0x1F);
        am_pm = (data[2] & 0x20) ? 1 : 0;
    } else {
        // 24-hour mode
        hours = bcd_to_dec(data[2] & 0x3F);
        am_pm = (hours >= 12) ? 1 : 0;
    }    

    // 24-hour mode: bits 5..0 are hours (bit 6 is 12/24 flag)
    //hours   = bcd_to_dec(data[2] & 0x3F); 
}

//-----------------Set the current time-------------------
void DS3231_SetTime(uint8_t h_s, uint8_t m_s, uint8_t s_s, uint8_t am_pm_flag)
{
    uint8_t data[3];

    data[0] = dec_to_bcd(s_s);
    data[1] = dec_to_bcd(m_s);

    uint8_t h_bcd = dec_to_bcd(h_s);

    h_bcd |= 0x40; // Set 12-hour mode bit

    // Set AM/PM bit based on the flag (bit 5)
    if (am_pm_flag) {
        h_bcd |= 0x20; // Set PM bit
    } else {
        h_bcd &= ~0x20; // Clear PM bit for AM
    }

    data[2] = h_bcd;
    
    //data[2] = dec_to_bcd(h_s);   // 24-hour mode

    (void)ds3231_write_regs(0x00, data, 3); // write seconds, minutes, hours starting at reg 0x00
}


/**************************/
/*         DATE          */
/************************/
//-----------------Read the date from the DS3231 Module-------------------
void DS3231_ReadDate()
{
    uint8_t data[3];

    if (!ds3231_read_regs(0x04, data, 3)) return; // read day, month, year starting at reg 0x04

   // DS3231 registers:
    // 0x04 date (1-31)
    // 0x05 month (1-12, bit7 is century)
    // 0x06 year (00-99)
    day   = bcd_to_dec(data[0] & 0x3F); // Mask day bit 6 (day of week)
    month = bcd_to_dec(data[1] & 0x1F); // Mask month bit 7 (century)
    //year  = (uint8_t)(2000 + bcd_to_dec(data[2]));
    year = bcd_to_dec(data[2]);
}

//-----------------Set the current date-------------------
void DS3231_SetDate(uint8_t dy, uint8_t mth, uint8_t yr)
{
    // NOTE: DS3231 year register is 00–99.
    // If you pass 2026 here by mistake, it will overflow.
    uint8_t data[3];

    data[0] = dec_to_bcd(dy);
    data[1] = dec_to_bcd(mth);
    data[2] = dec_to_bcd(yr);

    (void)ds3231_write_regs(0x04, data, 3); // write day, month, year starting at reg 0x04
}