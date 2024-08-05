/*
 * File:   sw_in.c
 * Author: nestorj
 * 
 * Reference implementation of sw_in module
 */

#include "sw_in.h"
#include "pico/stdlib.h"

void sw_in_init() {
    gpio_init(SW1_PIN);
    gpio_set_dir(SW1_PIN, false);
    gpio_pull_up(SW1_PIN);
    gpio_init(SW2_PIN);
    gpio_set_dir(SW2_PIN, false);
    gpio_pull_up(SW2_PIN);
}

bool sw_in_read1() {
    return !gpio_get(SW1_PIN);
}

bool sw_in_read2() {
    return !gpio_get(SW2_PIN);
 }

