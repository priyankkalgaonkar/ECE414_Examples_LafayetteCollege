/*
 * led25 - simple module to write built-in LED on Pico 
 */

#include "pico/stdlib.h"

#define LED25 25

void led25_out_init() {
    gpio_init(LED25);
    gpio_set_dir(LED25, true);
    gpio_put(LED25,false);
}

void led25_out_write(bool val) {
    gpio_put(LED25, val);
}