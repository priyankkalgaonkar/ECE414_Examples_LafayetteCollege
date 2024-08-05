cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ic_demo_project)

pico_sdk_init()

add_executable(ic_demo
        ic_demo.c ic.c timer.c
        )

# pull in common dependencies
target_link_libraries(
        ic_demo 
        pico_stdlib
        pico_bootsel_via_double_reset
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(ic_demo)

