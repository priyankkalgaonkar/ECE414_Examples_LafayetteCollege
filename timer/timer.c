/*
 * Simple Timer Module
 * Read & calculate elapsed time with 32-bit timestamps
 * Note that the hardware_time module provides similar
 * functions using 64-bit timestamps
 * 
 * Caution: Rollover on 32-bit time measurementswill occur 
 * once every 2^32 microseconds (11.93 hours).  We handle one
 * rollover with the code provided, but if the time between
 * measurements exceeds twice this amount (23.8 hours) then
 * the calculation will be incorrect.  For measurements of
 * this duration, consider using the real-time clock instead
 *
 * ECE 414 - Lafayette College
 * J. Nestor July 2023
 */

#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "timer.h"
#include "pico/stdlib.h"
#include "stdint.h"

uint32_t timer_read() {
    return time_us_32();
}

// return the elapsed time in us between two 32-bit timestamps
// note the need to deal with rollovers
uint32_t timer_elapsed_us(uint32_t t1, uint32_t t2) {
    if (t2 > t1) return t2 - t1;
    else return UINT32_MAX - t1 + t2 + 1;
}

// return the elapsed time in use betwen two 32-bit timestamps
uint32_t timer_elapsed_ms(uint32_t t1, uint32_t t2) {
    return timer_elapsed_us(t1, t2) / 1000;
}