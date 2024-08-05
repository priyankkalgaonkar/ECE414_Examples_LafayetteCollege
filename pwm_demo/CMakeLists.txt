cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pwm_demo_project)

pico_sdk_init()

add_executable(pwm_demo
        pwm_demo.c pwm_pin.c
        )

# pull in common dependencies
target_link_libraries(
        pwm_demo 
        hardware_pwm 
        pico_stdlib
        pico_bootsel_via_double_reset
)

# create map/bin/hex file etc.
pico_add_extra_outputs(pwm_demo)

