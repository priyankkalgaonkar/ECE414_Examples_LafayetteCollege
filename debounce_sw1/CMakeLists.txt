cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(debounce_sw1_demo)

pico_sdk_init()

add_executable(debounce_sw1_demo)
        
target_sources(debounce_sw1_demo PRIVATE
        debounce_sw1_demo.c
        debounce_sw1.c
        sw_in.c
        timer.c
        led25_out.c
        )

# pull in common dependencies
target_link_libraries(debounce_sw1_demo pico_stdlib  pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(debounce_sw1_demo)

