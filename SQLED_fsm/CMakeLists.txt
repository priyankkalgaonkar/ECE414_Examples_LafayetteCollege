cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(SQLED_fsm)

pico_sdk_init()

add_executable(SQLED_fsm)

target_sources(SQLED_fsm PRIVATE 
    SQLED_fsm.c
    led_out.c
    timer.c
    )

target_link_libraries(SQLED_fsm PRIVATE 
    pico_stdlib 
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(SQLED_fsm)



