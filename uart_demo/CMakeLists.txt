cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(uart_demo)

pico_sdk_init()

add_executable(uart_demo
        uart_demo.c
        )

# pull in common dependencies
target_link_libraries(uart_demo pico_stdlib  )
#add for double-click remount: pico_bootsel_via_double_reset

# let's see if this turns on STDIO on the uart
pico_enable_stdio_uart(uart_demo 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(uart_demo)



