/*
 * led_out - module  to write an 8-bit value to pins 
 * GPIO9-GPIO2
 * 
 * ECE 414 - Lafayette College
 * J. Nestor July 2023 
 */

#include "led_out.h"
#include "pico/stdlib.h"

const static uint32_t MASK_9_2 = 0x000003fc;

void led_out_init() {

    gpio_init_mask(MASK_9_2);
    gpio_set_dir_out_masked(MASK_9_2);
}

void led_out_write(uint8_t val) {
    gpio_put_masked(MASK_9_2, val << 2);
}
