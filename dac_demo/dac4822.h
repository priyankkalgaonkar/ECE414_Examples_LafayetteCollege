/**
 *  ECE 414 - DAC demo using Microchip MPC4822 SPI DAC. 
 *  August 2023
 *  this code adapted from code by Hunter Adams (vha3)
 *  at Cornell based on examples from Raspberry Pi Pico
 * 
 *  This module sets up a single DAC channel and writes
 *  values to it.
 * 
 */

#include <math.h>

void init_dac4822();

void write_dac4822(uint16_t val);
