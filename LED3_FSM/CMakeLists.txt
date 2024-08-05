cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(LED3_FSM)

pico_sdk_init()

add_executable(LED3_FSM)

target_sources(LED3_FSM PRIVATE 
    LED3_FSM.c
    led_out.c
    timer.c
    )

target_link_libraries(LED3_FSM PRIVATE 
    pico_stdlib 
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(LED3_FSM)



