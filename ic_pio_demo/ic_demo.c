/*
 * ic_demo - demonstration of interrupt-driven input capture
 * and RPM measurement.
 * 
 * ECE 414 - Lafayette College
 * J. Nestor July 2023
 * 
*/

#include "stdio.h"
#include "pico/stdlib.h"
#include "ic.h"
#include "timer.h"

int main() {
    stdio_init_all();
    printf("Demo of PIO-drive Input Capture\n");
    ic_init();
    while (1) {
        uint32_t rpm = ic_getrpm();
        printf("rpm=%u\n", rpm);
        sleep_ms(1000);
    }

    
}