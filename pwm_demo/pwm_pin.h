/*
 * pwm24 - configure a single GPIO pin as a 
 * PWM output and provide a function to change 
 * the duty cycle
 *
 * ECE 414 - Lafayette College
 * J. Nestor - July 2023
 * 
 * */

#include "pico/stdlib.h"

// For now, use GPIO14 (Pico Pin 19)
#define PWM_PIN 14

// Initialize pin 24 as a basic PWM output
void pwm_pin_init(uint16_t level);

// Set the level where output changes from 1 to 0
void pwm_pin_set_level(uint16_t level);

