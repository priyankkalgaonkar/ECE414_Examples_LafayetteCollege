cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(adc_demo)

pico_sdk_init()

add_executable(adc_demo)


target_sources(adc_demo PRIVATE 
    adc_demo.c
    )

target_link_libraries(adc_demo PRIVATE 
    pico_stdlib 
    hardware_adc
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(adc_demo) 



