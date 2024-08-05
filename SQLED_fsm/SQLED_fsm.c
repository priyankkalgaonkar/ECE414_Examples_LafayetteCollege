/*
 * SQLED_fsm - ZyBook example ported to run on Pico
 * J. Nestor August 17, 2023
 */

#include "pico/stdlib.h"
#include "led_out.h"
#include "timer.h"

#define SQLED_PERIOD 300

static enum SQLED_States 
    {SQLED_SMStart, SQLED_Init, SQLED_NextLed } SQLED_State;

static uint8_t outval;

void tickFct_SQLED()
{
    switch (SQLED_State) {
        case SQLED_SMStart:
            SQLED_State = SQLED_Init;
            break;
        case SQLED_Init:
            SQLED_State = SQLED_NextLed;
            break;
        case SQLED_NextLed:
            SQLED_State = SQLED_NextLed;
            break;
        default:
            SQLED_State = SQLED_NextLed;
            break;
    }
    
    switch (SQLED_State) {           
        case SQLED_Init:
            outval = 0x01;
            led_out_write(outval);
            break;
        case SQLED_NextLed:
            if (outval == 0x80) outval = 0x01;
            else outval = outval << 1;
            led_out_write(outval);
            break;
        default:
            outval = 0x01;
            led_out_write(outval);
    }
}


int main() {
    uint32_t ta1, ta2;
    SQLED_State = SQLED_SMStart;
    led_out_init();  
    ta1 = timer_read();
    while (1) {
        ta2 = timer_read();
        if (timer_elapsed_ms(ta1, ta2) > SQLED_PERIOD) {
            tickFct_SQLED();
            ta1 = ta2;
        }
         
    }   
}
