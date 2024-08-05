/*
 * zTimer - emulates the ZyBook interrupt-driven timer
 * using the Pico SDK's high-level repeating_timer construct
 * 
*/

#include "pico/stdlib.h"
#include "pico/time.h"
#include "zTimer.h"

static uint32_t zTimerPeriod;
volatile static bool zTimerFlag = false;
static bool zTimerRunning = false;

// Timer Callback - essentially this is an ISR
// with the low-level housekeeping (e.g. clearing the IRQ bit)
// already done for us
void zTimerCallback(struct repeating_timer *t)
{
    zTimerFlag = true;
    return zTimerRunning;
}


// initialize timer to set a flag every given period
void zTimerSet(uint32_t pdms) {
    zTimerPeriod = pdms;
}

static struct repeating_timer timer;

void zTimerOn() {
    // Negative delay so means we will call repeating_timer_callback, and call it again
    // 25us (40kHz) later regardless of how long the callback took to execute
    add_repeating_timer_us(-zTimerPeriod, zTimerCallback, NULL, &timer);

    zTimerFlag = false;
    zTimerRunning = true;
}

void zTimerOff() {
    zTimerRunning = false;
    cancel_repeating_timer(&timer);
}

// read and return the timer flag value
// SIDE EFFECT: clear the flag
uint8_t zReadTimerFlag() {
    if (zTimerFlag) {
        zTimerFlag = 0;
        return 1;
    } else return 0; 
}




