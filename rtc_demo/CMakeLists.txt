cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(rtc_demo_project)

pico_sdk_init()

add_executable(rtc_demo
        rtc_demo.c
        )

# pull in common dependencies and additional rtc hardware support
target_link_libraries(rtc_demo pico_stdlib hardware_rtc
pico_bootsel_via_double_reset)

# create map/bin/hex file etc.
pico_add_extra_outputs(rtc_demo)

