/* 
 * File:   ztimer - implementation of the 
 * Author: John Nestor, Lafayette College
 *
 * This module implements a timer matching the functionality of the interrupt-
 * driven timer described in Section 4.5 of the Zybook "Programming Embedded 
 * Systems".  A key difference is that the timer flag is encapsulated in the 
 * module calling ReadTimerFlag returns its value and clears the flag.  This
 * means that we don't have to use a global variable to pass the flag.
 */

#include "stdio.h"
#include "pico/stdlib.h"
#include "stdint.h"
#include "stdbool.h"
#include "ztimer.h"

// declare timer_flag variable as volatile because
// the ISR can change it as well as regular code
static volatile bool timer_flag = false;
static uint32_t timer_period_ms = 1000;
static bool timer_on = false;

// Timer ISR
bool repeating_timer_callback(struct repeating_timer *t)
{
    timer_flag = true;
    return true;
}

// Create a repeating timer that calls repeating_timer_callback.
// If the delay is > 0 then this is the delay between the previous callback ending and the next starting.
// If the delay is negative (see below) then the next call to the callback will be exactly x us after the
// start of the call to the last callback
struct repeating_timer timer;

// start the timer
void zTimerOn()
{
    if (!timer_on)
    {
        // Negative delay so means we will call repeating_timer_callback, and call it again
        // 25us (40kHz) later regardless of how long the callback took to execute
        add_repeating_timer_ms(-timer_period_ms, repeating_timer_callback, NULL, &timer);
    }
}

// set the timer period.  If the timer is already
// running, stop it and restart it.
void zTimerSet(uint32_t period_ms)
{
    if (period_ms != timer_period_ms)
    {
        timer_period_ms = period_ms;
        if (timer_on)
        {
            zTimerOff();
            zTimerOn;
        }
    }
}

// turn off the timer
void zTimerOff() {
    cancel_repeating_timer(&timer);
}

// read and return the timer flag value
// SIDE EFFECT: clear the flag
bool zTimerReadFlag() {
    if (timer_flag) {
        timer_flag = false;
        return true;
    } else {
        return false;
    }
}