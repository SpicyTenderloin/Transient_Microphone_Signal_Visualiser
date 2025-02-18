#include <Arduino.h>

#ifndef VU_Meter_h
#define VU_Meter_h

extern uint32_t lastUpdateMillis;
const unsigned long interval = 10; // for refresh rate of 60fps

// Intialise pins for VUmeter
void VUInit(void);

// Update the VU meter
void VUupdate(void);

#define Level1 2
#define Level2 3
#define Level3 4
#define Level4 5
#define Level5 6
#define Level6 7
#define Level7 12
#define Level8 A1
#define Level9 A2
#define Level10 A3
#define Level11 A4
#define Level12 A5

#endif