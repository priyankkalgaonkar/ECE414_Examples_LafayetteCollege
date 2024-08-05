/*
 * File: dds.c
 * Author: John Nestor (Derived from example code by Van Hunter Adams)
 * August 2023
 * 
 * Direct Digital Synthesis to produce a sine and triangle wave via the DAC4822
 *  
 */

#ifndef DDS_H
#define	DDS_H

#include <stdint.h>

void dds_init();

void dds_play(float freq_hz);

void dds_off();

// note frequencies
// source: https://pages.mtu.edu/~suits/notefreqs.html
#define FREQ_OFF 0.0
#define FREQ_C3 130.81
#define FREQ_D3 146.83
#define FREQ_E3 164.81
#define FREQ_F3 174.61
#define FREQ_G3 196.0
#define FREQ_A3 220.0
#define FREQ_B3 246.94
#define FREQ_C4 261.63
#define FREQ_D4 293.66
#define FREQ_E4 329.63
#define FREQ_F4 349.23
#define FREQ_G4 392.0
#define FREQ_A4 440.0
#define FREQ_B4 493.88
#define FREQ_C5 523.25 



#endif	/* DDS_H */

