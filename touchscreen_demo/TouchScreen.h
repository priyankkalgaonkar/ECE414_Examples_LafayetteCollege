// Modified by Matthew Watkins for PIC32

// Touch screen library with X Y and Z (pressure) readings as well
// as oversampling to avoid 'bouncing'
// (c) ladyada / adafruit
// Code under MIT License

#ifndef _ADAFRUIT_TOUCHSCREEN_H_
#define _ADAFRUIT_TOUCHSCREEN_H_
//#include <stdint.h>    // notsure we need this
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

/*
 * Pin Assigments for toucscreen
 *  Y+ => ADC1/GP27 (Pin 32)
 *  Y- => GP21 (Pin 27)
 *  X+ => GP22 (Pin 9)
 *  X- => ADC0/GP26 (Pin 31)
 * 
 */
// GPIO Positions for touchscren terminals
#define XPbit 22
#define XMbit 26
//XM ADC position
#define XMchan 0
#define YPbit 27
//YP ADC position
#define YPchan 1
#define YMbit 21

//resistance between X+ and X- terminals
//measure for specific device
#define RXPLATE 275

struct TSPoint {
  int16_t x, y, z;
};

void setTSPoint(struct TSPoint * p, int16_t x0, int16_t y0, int16_t z0);

 
/*uint16_t pressure(void);
int readTouchY();
int readTouchX();*/
void getPoint(struct TSPoint * p);

#endif
