cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(tft_demo)

pico_sdk_init()

add_executable(tft_demo)

pico_generate_pio_header(tft_demo ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

target_sources(tft_demo PRIVATE tft_demo.c TFTMaster.c glcdfont.c)

target_link_libraries(tft_demo PRIVATE 
    pico_stdlib pico_rand 
    hardware_gpio hardware_pio 
    hardware_irq  
    pico_bootsel_via_double_reset
    )

pico_add_extra_outputs(tft_demo)
