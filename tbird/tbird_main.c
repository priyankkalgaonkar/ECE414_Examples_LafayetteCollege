/* 
 * tbird: Thunderbird Taillight FSM Example
 * ECE 414 - J. Nestor
 *
 * Created on September 9, 2021, 1:47 PM
 * Ported to Pico on August 17, 2023
 */

#include "pico/stdlib.h"
#include "timer.h"
#include "sw_in.h"
#include "led_out.h"
#include "tbird_fsm.h"

int main() {
    uint32_t ta1, ta2;
    const uint32_t TBIRD_PD_MS = 200;
    InitFSM_tbird();
    sw_in_init();
    led_out_init();
    ta1 = timer_read();
    while (1) {
        ta2 = timer_read();
        if (timer_elapsed_ms(ta1, ta2) > TBIRD_PD_MS) {
            TickFct_tbird();
            ta1 = ta2;
        }    
    }
}
