/*
 * Simple Timer Module
 * Read & calculate elapsed time with 32-bit timestamps
 * Note that the hardware_time module provides similar
 * functions using 64-bit timestamps
 *
 * ECE 414 - Lafayette College
 * J. Nestor July 2023
 */

#ifndef TIMER_H
#define TIMER_H

#include "pico/stdlib.h"
#include "hardware/timer.h"

uint32_t timer_read();

uint32_t timer_elapsed_us(uint32_t t1, uint32_t t2);

uint32_t timer_elapsed_ms(uint32_t t1, uint32_t t2);

#endif