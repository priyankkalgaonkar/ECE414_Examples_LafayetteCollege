/* 
 * File:   tbird_fsm.c
 * Author: nestorj
 *
 * Created on September 9, 2021, 1:49 PM
 * Ported to Pico on August 17, 2023
 */

#include "pico/stdlib.h"
#include "sw_in.h"
#include "led_out.h"
#include "tbird_fsm.h"

static enum Tbird_States { 
    TB_SMSTART, TB_IDLE, TB_R1, TB_R2, TB_R3, TB_L1, TB_L2, TB_L3, TB_HAZ 
} TB_State;

void InitFSM_tbird() {
    TB_State = TB_SMSTART;
    led_out_write(0b000000);
}

void TickFct_tbird() {
    bool lb, rb;
    lb = sw_in_read1();        
    rb = sw_in_read2();
    switch (TB_State) {          // transitions
        case TB_SMSTART:         // Initial transition
            TB_State = TB_IDLE;
            break;
        case TB_IDLE:
            if (lb && !rb) TB_State = TB_L1;
            else if (!lb && rb) TB_State = TB_R1;
            else if (lb && rb) TB_State = TB_HAZ;
            else TB_State = TB_IDLE;
            break;
        case TB_L1: 
            TB_State = TB_L2;
            break;
        case TB_L2: 
            TB_State = TB_L3;
            break;
        case TB_L3: 
            TB_State = TB_IDLE;
            break;
        case TB_R1:
            TB_State = TB_R2;
            break;
        case TB_R2: 
            TB_State = TB_R3;
            break;
        case TB_R3: 
            TB_State = TB_IDLE;
            break;
        case TB_HAZ:
            TB_State = TB_IDLE;
            break;
        default:
            TB_State = TB_IDLE;
            break;
    } // transitions
    
    switch (TB_State) {    // State actions
        case TB_IDLE:
            led_out_write(0b000000);
            break;
        case TB_L1:
            led_out_write(0b000100);
            break;
        case TB_L2:
            led_out_write(0b000110);
            break;
        case TB_L3:
            led_out_write(0b000111);
            break;
        case TB_R1:
            led_out_write(0b001000);
            break;
        case TB_R2:
            led_out_write(0b011000);
            break;
        case TB_R3:
            led_out_write(0b111000);
            break;
        case TB_HAZ:
            led_out_write(0b111111);
            break;
        default:
            led_out_write(0b000000);
            break;
    }
}
    

