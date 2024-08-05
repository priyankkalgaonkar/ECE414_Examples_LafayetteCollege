#include <stdio.h> //The standard C library
#include <stdlib.h> //C stdlib
#include "pico/stdlib.h" //Standard library for Pico
#include <math.h> //The standard math library
#include "hardware/gpio.h" //The hardware GPIO library
#include "pico/time.h" //The pico time library
#include "hardware/irq.h" //The hardware interrupt library
#include "hardware/pwm.h" //The hardware PWM library
#include "hardware/pio.h" //The hardware PIO library
#include "TFTMaster.h" //The TFT Master library

int main(){ //The program running on core 0
    int i, j; //The insex variables
    unsigned short col, count = 0; //Variables to store current colour and count
    stdio_init_all(); //Initialize all of the present standard stdio types that are linked into the binary
    tft_init_hw(); //Initialize the hardware for the TFT
    tft_begin(); //Initialize the TFT
    tft_setRotation(0); //Set TFT rotation
    tft_fillScreen(ILI9340_BLACK); //Fill the entire screen with black colour
    printf("test am I alive?\n");

    while(1){ //Infinite while loop
        printf("@");
        sleep_ms(500);
        unsigned long begin_time = (unsigned long)(get_absolute_time() / 1000); //Get the start time
        switch(count){ //Based on the current count, switch different colours
            case 0: col = ILI9340_BLUE;
                    break;
            case 1: col = ILI9340_RED;
                    break;
            case 2: col = ILI9340_GREEN;
                    break;
            case 3: col = ILI9340_CYAN;
                    break;
            case 4: col = ILI9340_MAGENTA;
                    break;
            case 5: col = ILI9340_YELLOW;
                    break;
            case 6: col = ILI9340_WHITE;
                    break;
        }
        for(i = 0; i < ILI9340_TFTWIDTH / 4; i++){
            for(j = 0; j < ILI9340_TFTHEIGHT / 4; j++){
                //tft_drawRect(i << 2, j << 2, 4, 4, col); //Simply drawing a rectangle takes 222 ms
                tft_fillRect(i << 2, j << 2, 4, 4, col); //Filling the entire rectangle surprisingly takes 110 ms
            }
        }
        count = (count + 1) % 7; //Increment the count and keep it between 0-6
        unsigned char exTime = ((unsigned long)(get_absolute_time() / 1000) - begin_time); //Calculate the amount of time taken
        printf("%u\n", exTime); //Print the time out
    }
}


