#include <Arduino.h>

#ifndef ClockFrequency
#define ClockFrequency 16e6
#endif

#ifndef Timer1_h
#define Timer1_h

const int SampleFrequency = 4e3; // kHz

// Timer 1 is in charge of ensuring the microphone signal is sampled at consistent intervals
// Can be set to sample at 32Hz-200kHz
// Prescalar of 8 allows for timers between 5 micro seconds 32 milliseconds cor
void timer1init(uint32_t Frequency);

#endif
