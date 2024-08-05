/*
 * sw_in - module to read two switches
 * Author: nestorj
 * 
 * Reference implementation of sw_in module
 */

#ifndef SW_IN_H
#define SW_IN_H

#include "sw_in.h"
#include "pico/stdlib.h"

#define SW1_PIN 16
#define SW2_PIN 17

void sw_in_init();

bool sw_in_read1();

bool sw_in_read2();

#endif

