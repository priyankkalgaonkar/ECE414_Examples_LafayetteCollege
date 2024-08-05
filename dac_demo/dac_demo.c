
#include "stdio.h"
#include "pico/stdlib.h"
#include "dac4822.h"

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
    uint16_t dac_level = 2048;  // start at half range
    stdio_init_all();
    init_dac4822();
    printf("Setting OC limit to %d\n", dac_level);
    write_dac4822(dac_level);
    while (1) { 
        if (uart_is_readable(uart0)) {
            char c = getchar();
            putchar(c);
            if (c == '+') {
                dac_level = min(dac_level+100, 4095);
            } else if (c == '-') {
                dac_level = max(dac_level-100, 0);
            } else if (c == '0' ) {
                dac_level = 0;
            } else if (c == 'f') {
                dac_level = 4095;
            } else printf("?\n");
            printf("\nSetting DAC level to %d\n", dac_level);
            write_dac4822(dac_level);
        }
    }
}
