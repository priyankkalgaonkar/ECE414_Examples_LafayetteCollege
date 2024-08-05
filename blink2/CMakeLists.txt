cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(blink2)

pico_sdk_init()

add_executable(blink2
        blink2.c
        )

# pull in common dependencies
target_link_libraries(blink2 pico_stdlib pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(blink2)

