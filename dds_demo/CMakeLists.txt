cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(dds_demo_project)

pico_sdk_init()

add_executable(dds_demo
        dds_demo.c dds.c dac4822.c
        )

# pull in common dependencies
target_link_libraries(
        dds_demo 
        hardware_spi 
        pico_stdlib
        pico_bootsel_via_double_reset
)

# create map/bin/hex file etc.
pico_add_extra_outputs(dds_demo)

