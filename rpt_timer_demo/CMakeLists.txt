cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ztimer_demo)

pico_sdk_init()

add_executable(ztimer_demo)

target_sources(ztimer_demo PRIVATE 
    ztimer.c
    ztimer_demo.c
    )

target_link_libraries(ztimer_demo PRIVATE 
    pico_stdlib 
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(ztimer_demo)



