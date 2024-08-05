/**
 * UART Demonstration
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

#define UART_ID uart0
#define BAUD_RATE 115200

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

int main() {

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    stdio_init_all();
    // gpio_init(LED_PIN);
    // gpio_set_dir(LED_PIN, GPIO_OUT);
    // uart_init(UART_ID, BAUD_RATE);
    
    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    // gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    // gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);
    uart_puts(UART_ID, "\n\nHello! is this thing on?\n");
    printf("printf demands to be seen and heard!\n\n");
    while (true) {
        if (uart_is_readable(UART_ID)) {
            char c = uart_getc(UART_ID);
            uart_putc(UART_ID,c+1);
        }
        gpio_put(LED_PIN, 1);
        sleep_ms(500);
        gpio_put(LED_PIN, 0);
        sleep_ms(500);
        uart_putc(uart0, '#');
    }
}
