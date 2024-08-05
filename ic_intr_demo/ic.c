/* 
 * ic - simple interrupt-drive input capture for Raspberry Pi Pico
 * ECE 414 July 2023
 * J. Nestor
 *
 */

#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include <math.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "timer.h"
#include "ic.h"


    static volatile uint32_t capture, last_capture, capture_period;
    static volatile bool capture_flag;

    // IC Interrupt service routine - called when a rising
    // edge occurs on IC_PIN
    void ic_callback(uint gpio, uint32_t event_mask)  {
        capture = time_us_32();
        capture_period = capture - last_capture;
        last_capture = capture;
        capture_flag = true;
    }
    
    // Configure Interrupt on IC_PIN
    void ic_init() {
        gpio_init(IC_PIN);  // is this necessary?  Hunter doesn't do this
        gpio_set_irq_enabled_with_callback(IC_PIN, GPIO_IRQ_EDGE_RISE, true, &ic_callback );
        capture = 0;
        last_capture = 0;
        capture_period = NO_CAPTURE_READY;
        capture_flag = false;
    }    
    
    // return the measured period in us assuming
    // it has been updated since last call
    // if not, return NO_CAPTURE_READY
    uint32_t ic_getperiod() {
        if (capture_flag) {
            capture_flag = false;
            return capture_period;
        } else {
            return NO_CAPTURE_READY;
        }
    }
    
    static const uint32_t USPERSEC = 1000000;
    static const float USPERSEC_F = 1.0e6;
    static uint32_t ic_rpm;

    // return the estimated RPM of the input capture
    // if called more before another capture edge arrives, return 0
    
    uint32_t ic_ticks2rpm(uint32_t ticks) {
        if (ticks == 0xffffffff) return 0;
        else {
            ic_rpm = ((USPERSEC * 60) + ticks/2) / ticks;
            // equivalent  calculation using floats - no appreciable difference
            //ic_rpm = round(((float)USPERSEC_F * 60.0) / (float)ticks);
            return ic_rpm;
        }
    }
    
    // return the estimated RPM of the input capture
    // if called more before another capture edge arrives,
    // keep track of the time elapsed since the last
    // capture using the system timer.  If we have no
    // capture for MIN_RPM_TIMEOUT_US, then return 0
    // as we assume the fan is not turning.  Otherwise
    // return NO_CAPTURE_READY 

    uint32_t ic_getrpm(){
        uint32_t current_time;
         uint32_t period = ic_getperiod();
         if (period == NO_CAPTURE_READY) {
            current_time = time_us_32();
            if ((current_time - last_capture) > MIN_RPM_TIMEOUT_US) {
                return 0;
            } else {
                return NO_CAPTURE_READY;
            }
         } else {
            return( ic_ticks2rpm(period));
         }
    }