cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(timer_demo_project)

pico_sdk_init()

add_executable(timer_demo
        timer_demo.c timer.c
        )

# pull in common dependencies
target_link_libraries(timer_demo pico_stdlib pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(timer_demo)

