/*
 * led_out - module  to write an 8-bit value to pins 
 * GPIO9-GPIO2
 * 
 * ECE 414 - Lafayette College
 * J. Nestor July 2023 
 */

#ifndef LED_OUT_H
#define LED_OUT_H

#include "pico/stdlib.h"

void led_out_init();

void led_out_write(uint8_t val);

#endif