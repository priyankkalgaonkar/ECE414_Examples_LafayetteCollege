/* 
 * File:   sw_in.h
 * Author: nestorj
 *
 * Module to initialize and use two GPIO inputs
 * as switches with internall pullup
 */

#ifndef SW_IN_H
#define SW_IN_H

#include "pico/stdlib.h"

// use symbolic constants to make it easy to change pin assignment
#define SW1_PIN 16
#define SW2_PIN 17

void sw_in_init();

bool sw_in_read1();

bool sw_in_read2();

#endif