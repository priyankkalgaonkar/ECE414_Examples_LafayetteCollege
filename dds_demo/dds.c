/*
 * File: dds.c
 * Author: John Nestor (Derived from example code by Van Hunter Adams)
 * August 2023
 * 
 * Direct Digital Synthesis to produce a sine wave via the DAC4822
 *  
 */

#include <math.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "dds.h"
#include "dac4822.h"

//DDS parameters
#define two32 4294967296.0 // 2^32 
#define Fs 40000 // sample rate of output
// the DDS units:
volatile unsigned int phase_accum_main;
volatile unsigned int phase_incr_main = (800.0*two32)/Fs ;//

// DDS sine table
#define sine_table_size 256
static int sin_table[sine_table_size] ;

static uint32_t dac_freq;  // frequency at which DAC outputs from table

// Timer ISR
// This callback
bool repeating_timer_callback(struct repeating_timer *t) {
    // DDS phase and sine table lookup
    phase_accum_main += phase_incr_main  ;
    write_dac4822 ((sin_table[phase_accum_main>>24] + 2048) & 0xffff);
    return true;
}


// turn on DDS at the specified frequency by setting
// the phase increment
void dds_play(float freq_hz) {
    if (freq_hz == 0.0) {
        phase_incr_main = 0;  // set output level to baseline
        phase_accum_main = 0;
    } else {
        phase_incr_main = (freq_hz*two32)/Fs;
    }    
}


void generateTable(void){
    // === build the sine lookup table =======
    // scaled to produce values between 0 and 4096
    int ii;
    for (ii = 0; ii < sine_table_size; ii++){
         sin_table[ii] = (int)(2047*sin((float)ii*6.283/(float)sine_table_size));
    }
}

    // Create a repeating timer that calls repeating_timer_callback.
    // If the delay is >0 then this is the delay between the previous callback ending and the next starting.
    // If the delay is negative then the next call to the callback will be exactly x us after the
    // start of the call to the last callback
struct repeating_timer timer;

void dds_init()
{
    generateTable();
    init_dac4822();
    // Negative delay so means we will call repeating_timer_callback, and call it again
    // 25us (40kHz) later regardless of how long the callback took to execute
    add_repeating_timer_us(-25, repeating_timer_callback, NULL, &timer);
}


// turn off DDS by disabling timer interrupt
void dds_off() {
    cancel_repeating_timer(&timer);
}
