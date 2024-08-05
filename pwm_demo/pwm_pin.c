/*
 * pwm-pin - configure GPIO24 as a PWM output
 * and provide a function to change the
 * duty cycle
 *
 * ECE 414 - Lafayette College
 * J. Nestor - July 2023
 * 
 * */

#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "pwm_pin.h"

static uint slice_num;

// Initialize pin 25 as a basic PWM output
// By setting the pwm clock divider to divide 125MHz/1.9375
// we will count at 63.23 MHz (15.8ns) 
// By seetting the wrap at 0xfff output waveform will have
// a frequency of 965.65 Hz (1.035ms)
void pwm_pin_init(uint16_t level) {
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    pwm_set_clkdiv(slice_num, 1.9375);  
    pwm_set_wrap(slice_num, 0xffff);
    pwm_set_chan_level(slice_num, PWM_CHAN_A, level);
    pwm_set_enabled(slice_num, true);
}

// Set the level where output changes from 1 to 0
void pwm_pin_set_level(uint16_t level){
    pwm_set_chan_level(slice_num, PWM_CHAN_A, level);
}
