/*
 * zTimer - Equivalent timer to ZyBook timer using interrupt service routine
 * ECE 414 Lafayette College
 * July, 2023
 */

#ifndef ZTIMER_H
#define ZTIMER_H

#include <pico/stdlib.h>

// initialize timer to set a flag every given period
void zTimerSet(uint32_t period);

// enable the timer and turn on the interrupt
void zTimerOn();

// read and return the timer flag value
// SIDE EFFECT: clear the flag
uint8_t zTimerReadFlag();


#endif	/* ZTIMER_H */
