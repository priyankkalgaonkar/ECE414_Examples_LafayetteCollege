#include "pico/stdlib.h"
#include "led_out.h"
#include "timer.h"

#define LED3_PERIOD 400

static enum LED3_States { LED3_SMStart, LED3_L0, LED3_L1, LED3_L2 } LED3_State;

void tickFct_LED3()
{
    switch (LED3_State) {          // state transitions
        case LED3_SMStart:
            LED3_State = LED3_L0;
            break;
        case LED3_L0:
            LED3_State = LED3_L1;
            break;
        case LED3_L1:
            LED3_State = LED3_L2;
            break;
        case LED3_L2:
            LED3_State = LED3_L0;
            break;
    }
    
    switch (LED3_State) {   // state actions - no output needed for LED3_SMStart        
        case LED3_L0:
            led_out_write(0b001);
            break;
        case LED3_L1:
            led_out_write(0b010);
            break;
        case LED3_L2:
            led_out_write(0b100);
            break;
    }
}

int main() {
    uint32_t ta1, ta2;
    LED3_State = LED3_SMStart;
    led_out_init();  
    ta1 = timer_read();
    while (1) {
        ta2 = timer_read();
        if (timer_elapsed_ms(ta1, ta2) > LED3_PERIOD) {
            tickFct_LED3();
            ta1 = ta2;
        }
         
    }   
}
