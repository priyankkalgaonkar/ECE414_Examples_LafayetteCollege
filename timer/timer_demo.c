/**
 * Simple timer demo - flash two LEDs at different rates
*/
/*
 * Simple Timer Module Demo
 * Blink 2 GPIO outputs at different rates
 *
 * ECE 414 - Lafayette College
 * J. Nestor July 2023
 */

#include "pico/stdlib.h"
#include "timer.h"
#include "stdint.h"
#include "stdbool.h"

#define LED_A 2
#define LED_B 3

int main() {
    uint32_t t1a, t2a, t1b, t2b;
    const uint32_t PD_MS_A = 1000;
    const uint32_t PD_MS_B = 500;
    bool a, b;
    gpio_init(LED_A);
    gpio_set_dir(LED_A,true);
    gpio_init(LED_B);
    gpio_set_dir(LED_B,true);
    t1a = t1b = timer_read();
    a = b = true;
    gpio_put(LED_A,a);
    gpio_put(LED_B,b);
    while (true) {
        t2a = t2b = timer_read();
        if (timer_elapsed_ms(t1a, t2a) >= PD_MS_A) {
            t1a = t2a;
            a = !a;
            gpio_put(2,a);
        }
        if (timer_elapsed_ms(t1b, t2b) >= PD_MS_B) {
            t1b = t2b;
            b = !b;
            gpio_put(3,b);
        }       
    }
}