cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(tbird)

pico_sdk_init()

add_executable(tbird)

target_sources(tbird PRIVATE 
    tbird_main.c
    tbird_fsm.c
    sw_in.c
    led_out.c
    timer.c
    )

target_link_libraries(tbird PRIVATE 
    pico_stdlib 
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(tbird)



