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

#ifndef ZTIMER_H
#define	ZTIMER_H
#include <inttypes.h>

// set the period of the zTimer, stopping
// and restarting the timer if it is running
void zTimerSet(uint32_t period);

// enable the timer and turn on the interrupt
void zTimerOn();

// turn off the timer
void zTimerOff();

// read and return the timer flag value
// SIDE EFFECT: clear the flag
bool zTimerReadFlag();

#endif	/* ZTIMER_H */

