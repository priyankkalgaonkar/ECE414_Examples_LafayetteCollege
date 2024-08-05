/* 
 * File:   debounce_sw1.c
 * Author: nestorj
 *
 * Debounce a switch read by the sw_in module
 */

#include "stdio.h"
#include "pico/stdlib.h"
#include "debounce_sw1.h"
#include "sw_in.h"

// flag indicating button pressed and debounced
// cleared when read by debounce1_pressed()
static bool btn_pressed;  

// state variable

static enum DB_States {NOPUSH, MAYBEPUSH, PUSHED, MAYBENOPUSH} DB_State;

void debounce_sw1_init() {
    DB_State = NOPUSH;
    btn_pressed = false;
}

void debounce_sw1_tick() {
    bool btn = sw_in_read1();
    switch(DB_State) {
        case NOPUSH:
            if (btn) DB_State = MAYBEPUSH;
            else DB_State = NOPUSH;
            break;
        case MAYBEPUSH:
            if (btn) {
                btn_pressed = true;
                DB_State = PUSHED;
            }
            else DB_State = NOPUSH;
            break;
        case PUSHED:
            if (btn) DB_State = PUSHED;
            else DB_State = MAYBENOPUSH;
            break;
        case MAYBENOPUSH:
            if (btn) DB_State = PUSHED;
            else DB_State = NOPUSH;
            break;
        default:
            DB_State = NOPUSH;
            break;
    }

    // note: no other state actions required, 
    // so we don't need a 2nd switch statement
    
}

// return TRUE the first time the function is called after the button has 
// been pressed.  Return FALSE until the button is released and pressed again
bool debounce_sw1_pressed() {
    if (btn_pressed) {
        btn_pressed = false; 
        return true;
    } else return false;
}



