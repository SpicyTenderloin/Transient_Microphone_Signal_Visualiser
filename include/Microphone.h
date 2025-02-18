#include <Adafruit_SSD1351.h>
#include <Adafruit_GFX.h>
#include "OLED.h"

#ifndef Microphone_H
#define Microphone_H

// Initialise array to store samples
extern volatile int readings[SCREEN_WIDTH];

extern uint16_t DCOffset; // Global variable to store DC offset

// Maintainence function for trimming the microphone DC offset
uint16_t estimateDCoffset(int numSamples);
#endif

#ifndef MicIn
#define micIn A0
#endif