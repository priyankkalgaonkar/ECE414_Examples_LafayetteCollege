
#include "stdio.h"
#include "pico/stdlib.h"
#include "pwm_pin.h"

static inline int32_t max (uint32_t a, uint32_t b) {
    if (a > b) return a;
    else return b;
}

static inline int32_t min (uint32_t a, uint32_t b) {
    if (a < b) return a;
    else return b;
}

uint8_t linebuf [100];

int main() {
    uint16_t pwm_level = 0x8000;  // start with a 50% duty cycle
    stdio_init_all();
    printf("Setting OC limit to %x\n", pwm_level);
    pwm_pin_init(pwm_level);
    while (1) { 
        if (uart_is_readable(uart0)) {
            char c = getchar();
            putchar(c);
            if (c == '+') {
                pwm_level = min(pwm_level+0x1000, 0xffff);
            } else if (c == '-') {
                pwm_level = max(pwm_level-0x1000, 0);
            } else if (c == '0' ) {
                pwm_level = 0;
            } else if (c == 'f') {
                pwm_level = 0xffff;
            } else printf("?\n");
            printf("\nSetting PWM level to 0x%x\n", pwm_level);
            pwm_pin_set_level(pwm_level);
        }
    }
}
