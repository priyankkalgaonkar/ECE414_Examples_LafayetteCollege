cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(ic_pio_demo_project)

pico_sdk_init()

add_executable(ic_pio_demo
        ic_demo.c ic_pio.c
        )

pico_generate_pio_header(
        ic_pio_demo 
        ${CMAKE_CURRENT_LIST_DIR}/ic_pio.pio
        )

# pull in common dependencies
target_link_libraries(
        ic_pio_demo 
        pico_stdlib
        hardware_pio
        pico_bootsel_via_double_reset
        )

# create map/bin/hex file etc.
pico_add_extra_outputs(ic_pio_demo)

