/*
 * mg90s.c
 *
 *  Created on: March 1, 2026
 *      Author: Daniel Attih
 */

 #include "mg90s.h"
 #include <stddef.h>

/* ---- internal helpers ---- */

static uint16_t clamp_u16(uint16_t v, uint16_t lo, uint16_t hi)
{
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

static int16_t clamp_i16(int16_t v, int16_t lo, int16_t hi)
{
  if (v < lo) return lo;
  if (v > hi) return hi;
  return v;
}

/*
 * Convert angle to microseconds.
 */
static uint16_t angle_to_us(const MG90S_Servo* s, int16_t deg)
{
    // Map deg [0..max_deg] -> us [min_us..max_us] with rounding.
    uint32_t span = (uint32_t)(s -> max_us - s -> min_us);
    uint32_t num  = (uint32_t)deg * span;
    uint32_t den  = (uint32_t)s -> max_deg;
    uint32_t us   = (uint32_t)s -> min_us + (num + den / 2u) / den; // Round to nearest microsecond
    return (uint16_t)us;
}

/*
 * Convert pulse width (us) to PWM level (ticks) for current wrap/period.
 * Level (CCR on STM32) is the value to set for the duty cycle, and it should be in the range [0..wrap].
 * level range: [0..wrap]
 */
static inline uint16_t us_to_level(const MG90S_Servo* s, uint16_t pulse_us)
{
  // level = pulse_us / period_us * (wrap + 1)
  // Use 32-bit for safety.
  uint32_t level = ((uint32_t)pulse_us * (uint32_t)(s->wrap + 1u)) / (uint32_t)MG90S_PERIOD_US;
  if (level > s->wrap) level = s->wrap;
  return (uint16_t)level;
}

/*
 * Configure PWM on the given GPIO at 50 Hz.
 *
 * PWM freq = clk_sys / clkdiv / (wrap + 1)
 * We choose a wrap, then compute clkdiv.
 */
static void pwm_configure_50hz(MG90S_Servo* s)
{
  // Put GPIO into PWM function
  gpio_set_function(s->gpio, GPIO_FUNC_PWM);

  // Determine slice and channel
  s->slice   = (uint8_t)pwm_gpio_to_slice_num(s->gpio);
  s->channel = (uint8_t)pwm_gpio_to_channel(s->gpio);

  // Choose wrap. 20000 gives 1 count ~= 1us if clk is 1MHz, but we’ll compute clkdiv.
  // 19999 is a nice match for 20,000us period.
  s->wrap = 19999u;

  // Compute clock divider:
  // clkdiv = clk_sys / (freq * (wrap + 1))
  // clk_sys is typically 125 MHz on Pico.
  uint32_t clk_sys_hz = clock_get_hz(clk_sys);
  float div = (float)clk_sys_hz / ((float)MG90S_SERVO_HZ * (float)(s->wrap + 1u));

  // Pico PWM clkdiv valid range is roughly 1.0 to 256.0
  if (div < 1.0f)   div = 1.0f;
  if (div > 256.0f) div = 256.0f;

  pwm_config cfg = pwm_get_default_config();
  pwm_config_set_clkdiv(&cfg, div);
  pwm_config_set_wrap(&cfg, s->wrap);

  pwm_init(s->slice, &cfg, true);
}

/* ---- public API ---- */
void MG90S_Initialize(MG90S_Servo* s)
{
    if (s == NULL) return;

    // Set defaults
    s->min_us     = MG90S_DEFAULT_MIN_US;
    s->max_us     = MG90S_DEFAULT_MAX_US;
    s->neutral_us = MG90S_DEFAULT_NEUTRAL_US;
    s->max_deg    = MG90S_DEFAULT_MAX_DEG;

    pwm_configure_50hz(s);

    s->last_us        = s->neutral_us;
    s->initialized    = true;

    // Center the servo
    //MG90S_SetAngle(s, s->neutral_us);
    MG90S_SetPulseWidthUs(s, s -> min_us); // Start at min position (0 degrees)
}

void MG90S_SetPulseWidthUs(MG90S_Servo* s, uint16_t pulse_us)
{
    if (s == NULL || !s->initialized) return;

    pulse_us = clamp_u16(pulse_us, s->min_us, s->max_us);
    s->last_us = pulse_us;

    uint32_t level = us_to_level(s, pulse_us);

    // Clamp to wrap value just in case (safety)
    if (level > s->wrap) level = s->wrap;

    // Set duty cycle.
    pwm_set_chan_level(s->slice, s->channel, level);
}

// Convenience function to set angle directly.
void MG90S_SetAngle(MG90S_Servo* s, int16_t degrees)
{
    if (s == NULL || !s->initialized) return;

    degrees = clamp_i16(degrees, 0, (int16_t)s->max_deg);

    uint16_t us = angle_to_us(s, degrees);
    MG90S_SetPulseWidthUs(s, us);
}