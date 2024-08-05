cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(TFT_PIO-project)

pico_sdk_init()

add_executable(TFT_PIO)

#pico_enable_stdio_usb(TFT_PIO 1)
#pico_enable_stdio_uart(TFT_PIO 0)

pico_generate_pio_header(TFT_PIO ${CMAKE_CURRENT_LIST_DIR}/SPIPIO.pio)

target_sources(TFT_PIO PRIVATE TFT_PIO.c TFTMaster.c glcdfont.c)

target_link_libraries(TFT_PIO PRIVATE pico_stdlib hardware_gpio pico_time hardware_pio hardware_pwm hardware_irq pico_bootsel_via_double_reset)

pico_add_extra_outputs(TFT_PIO)
