/**
 * Real-Time Clock Demonstration 
 * This code stolen from pico_
 */

#include <stdio.h>
#include "hardware/rtc.h"
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
 

int main() {
    stdio_init_all();
    printf("Hello RTC!\n");
 
    char datetime_buf[256];
    char *datetime_str = &datetime_buf[0];
 
    // Start on Friday 5th of June 2020 15:45:00
    datetime_t t = {
            .year  = 2023,
            .month = 11,
            .day   = 14,
            .dotw  = 2, // 0 is Sunday, so 5 is Friday
            .hour  = 11,
            .min   = 51,
            .sec   = 00
    };
 
    // Start the RTC
    rtc_init();
    rtc_set_datetime(&t);
 
    // clk_sys is >2000x faster than clk_rtc, so datetime is not updated immediately when rtc_get_datetime() is called.
    // tbe delay is up to 3 RTC clock cycles (which is 64us with the default clock settings)
    sleep_us(64);
 
    // Print the time
    while (true) {
        rtc_get_datetime(&t);
        datetime_to_str(datetime_str, sizeof(datetime_buf), &t);
        printf("\r%s      ", datetime_str);
        sleep_ms(1000);
    }
}
