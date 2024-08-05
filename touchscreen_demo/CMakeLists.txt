cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(touchscreen_demo)

pico_sdk_init()

add_executable(touchscreen_demo)

pico_generate_pio_header(touchscreen_demo ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

target_sources(touchscreen_demo PRIVATE 
    touchscreen_demo.c
    TouchScreen.c
    TFTMaster.c
    glcdfont.c
    
    )

target_link_libraries(touchscreen_demo PRIVATE 
    pico_stdlib 
    hardware_adc 
    hardware_gpio hardware_pio 
    hardware_irq    
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(touchscreen_demo)






