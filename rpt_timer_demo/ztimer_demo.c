/* 
 * ztimer_demo 
 * John Nestor, Lafayette College
 * September, 2023
 *
 * This module provides a simple demonstration of the
 * ztimer module.
 *
 */

#include "stdio.h"
#include "pico/stdlib.h"
#include "ztimer.h"

int main() {
    uint8_t seconds = 0;
    stdio_init_all();
    printf("zTimer demo program\n");
    zTimerSet(1000);
    zTimerOn();

    while (1) {
        if (zTimerReadFlag()) {
            seconds++;
            printf("%d\n", seconds);
        } 
    }
}