cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(gpio_demo_project)

pico_sdk_init()

add_executable(gpio_demo
        gpio_demo.c
        )

# pull in common dependencies
target_link_libraries(
        gpio_demo 
        pico_stdlib 
        pico_bootsel_via_double_reset
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(gpio_demo)

