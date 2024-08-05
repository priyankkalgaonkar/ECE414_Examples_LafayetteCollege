
/*
*  Demonstration of ADC operation
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// ADC Channel 0 at GP26 (Pin 31)
#define CH0_PIN 26
#define CH0 0


int main() {
    uint16_t data;
    stdio_init_all();
    adc_init();
    adc_gpio_init(CH0_PIN);
    printf("Starting adc_demo\n");
    adc_select_input(CH0);
    while(true) {
        data = adc_read();
        printf("%d\n",data);
        sleep_ms(500);
    }
}