#include <stdio.h>         //The standard C library
#include <math.h>          //The standard math library
#include "pico/stdlib.h"   //Standard library for Pico
#include "pico/rand.h"     // for random numbers
#include "TFTMaster.h"     //The TFT Master library

// local symbolic constants for brevity in code
#define DW ILI9340_TFTWIDTH
#define DH ILI9340_TFTHEIGHT
// maximum radius for drawing circles
#define MAX_RAD 50

int main()
{                                  
    int i;
    unsigned short col, count = 0; // Variables to store current colour and count
    stdio_init_all();              // Initialize all of the present standard stdio types that are linked into the binary
    tft_init_hw();                 // Initialize the hardware for the TFT
    tft_begin();                   // Initialize the TFT
    tft_setRotation(3);            // Set TFT rotation
    tft_fillScreen(ILI9340_BLACK); // Fill the entire screen with black colour
    printf("test am I alive?\n");
    tft_setTextColor(ILI9340_RED);
    tft_setTextSize(2);

    printf("@");
    sleep_ms(500);
    tft_fillScreen(ILI9340_BLUE);
    tft_drawRect(5, 5, 100, 100, ILI9340_GREEN);
    for (i = 1; i < 20; i++)
    {
        int y = i * 20;
        tft_setCursor(10, y);
        tft_writeString("this is a string");
    }
    sleep_ms(500);
    static char buffer[64];

    count = 0;
    while (1) // Infinite while loop
    {
        // Clear the screen
        tft_fillScreen(ILI9340_BLACK);

        // Draw some text
        tft_setCursor(0, 0); // Upper Left Hand Corner
        tft_setTextColor(ILI9340_WHITE);
        tft_setTextSize(2);

        tft_writeString("Hello World.");
        for (i = 1; i < 10; i++)
        {
            tft_setCursor(0, i * 20);
            sprintf(buffer, "Count = %d", count++);
            tft_writeString(buffer);
        }

        // Draw some random lines.  Note: Avoid using get_rand_32() function in
        // performance critical code!
        for (i = 0; i < 10; i++)
        {
            tft_drawLine(get_rand_32() % DW, get_rand_32() % DH, get_rand_32() % DW, get_rand_32() % DH, get_rand_32() & 0xffff);
        }

        // Draw some get_rand_32()om filled circles
        for (i = 0; i < 10; i++)
        {
            tft_fillCircle(get_rand_32() % (DW - 2 * MAX_RAD) + MAX_RAD, get_rand_32() % (DH - 2 * MAX_RAD) + MAX_RAD, get_rand_32() % MAX_RAD, get_rand_32() & 0xffff);
        }

        // Wait a bit.
        sleep_ms(500);
    }
}
