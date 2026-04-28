/*
 * mg90s.h
 *
 *  Created on: March 1, 2026
 *      Author: Daniel Attih
 */

#ifndef MG90S_H_
#define MG90S_H_

#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include <stdint.h>
#include <stdbool.h>

/*
  MG90S defaults:
  - 50 Hz (20 ms period)
  - pulse width range ~900–2100 us
  - neutral ~1500 us
  - travel often ~120 deg for that range (varies by unit)
*/

// Servo refresh frequency (standard servos use 50Hz)
#define MG90S_SERVO_HZ            50u
#define MG90S_PERIOD_US           (1000000u / MG90S_SERVO_HZ)  // 20000 us

#define MG90S_DEFAULT_MIN_US         500u
#define MG90S_DEFAULT_MAX_US         2500u
#define MG90S_DEFAULT_NEUTRAL_US     1500u
#define MG90S_DEFAULT_MAX_DEG        180u

typedef struct
{
  // Configuration
  uint16_t min_us;
  uint16_t max_us;
  uint16_t neutral_us;
  uint8_t  max_deg;

  // Pico PWM configuration
  uint8_t  gpio;        // GPIO pin used for PWM output (e.g., 16)
  uint8_t  slice;       // PWM slice number (0..7) eqivalent to TIMx on STM32 (TIM3)
  uint8_t  channel;     // PWM_CHAN_A or PWM_CHAN_B
  uint16_t wrap;        // PWM TOP value (wrap) equivalent to ARR

  // State
  uint16_t last_us;
  bool initialized;

} MG90S_Servo;

/*
 * Initialize the servo driver (configures PWM on s->gpio and centers servo).
 */
void MG90S_Initialize(MG90S_Servo* s); // Initialize the motor

/*
 * Set servo angle in degrees. Clamped to [0..max_deg].
 */
void MG90S_SetAngle(MG90S_Servo* s, int16_t degrees);

/**
 * Set raw pulse width in microseconds. Clamped to [min_us..max_us].
 */
void MG90S_SetPulseWidthUs(MG90S_Servo* s, uint16_t pulse_us);

#endif /* MG90S_H_ */