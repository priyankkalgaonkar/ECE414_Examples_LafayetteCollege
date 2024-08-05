
#include "stdio.h"
#include "pico/stdlib.h"
#include "dds.h"

int main()
{
    stdio_init_all();
    dds_init();
    while (1)
    {
        printf("\nEnter a note:");
        while (!uart_is_readable(uart0))
            ;
        char c = getchar();
        putchar(c);
        switch (c)
        {
        case 'C':
            dds_play(FREQ_C3);
            break;
        case 'D':
            dds_play(FREQ_D3);
            break;
        case 'E':
            dds_play(FREQ_E3);
            break;
        case 'F':
            dds_play(FREQ_F3);
            break;
        case 'G':
            dds_play(FREQ_G3);
            break;
        case 'A':
            dds_play(FREQ_A3);
            break;
        case 'B':
            dds_play(FREQ_B3);
            break;
        case 'c':
            dds_play(FREQ_C4);
            break;
        case 'd':
            dds_play(FREQ_D4);
            break;
        case 'e':
            dds_play(FREQ_E4);
            break;
        case 'f':
            dds_play(FREQ_F4);
            break;
        case 'g':
            dds_play(FREQ_G4);
            break;
        case 'a':
            dds_play(FREQ_A4);
            break;
        case 'b':
            dds_play(FREQ_B4);
            break;
        case 'v':
            dds_play(FREQ_C5)
;            break;
        case 'o':
        case 'O':
        case '0':
            dds_play(FREQ_OFF);
            break;
        default:
            printf("\nunknown note\n");
            break;
        }
    }
}