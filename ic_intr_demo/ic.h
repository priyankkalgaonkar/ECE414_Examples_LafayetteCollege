/* 
 * ic - simple interrupt-drive input capture for R
 *
 *
 * Interrupt-driven input capture for Raspberry Pi Pico
 *

 */

#include "pico/stdio.h"

// specify GPIO pin used for input capture
// NOTE: GPIO13 is Pico Pin 17
#define IC_PIN 13

// specify minimum RPM below which ic_getrpm() returns 0 RPM
// this is used as a timeout value
#define MIN_RPM 50
// number of microseconds when MIN_RPM period is reached
#define MIN_RPM_TIMEOUT_US (60*1000000) / MIN_RPM

#define NO_CAPTURE_READY 0xffffffff

    // Configure Interrupt on IC_PIN
    void ic_init();   
    
    // return the period measured by timer in us
    uint32_t ic_getperiod();
    
    // return the estimated RPM of the input capture
    // if called more before another capture edge arrives, return 0
    
    uint32_t ic_ticks2rpm(uint32_t ticks);
    
    uint32_t ic_getrpm();
