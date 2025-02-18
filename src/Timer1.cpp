#include "Timer1.h"

// Timer 1 is in charge of ensuring the microphone signal is sampled at consistent intervals
// Can be set to sample at 32Hz-200kHz
// Prescalar of 8 allows for timers between 5 micro seconds 32 milliseconds
void timer1init(uint32_t Frequency)
{
    // Set control registers to clear any previous configurations
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    // initialize counter value to 0
    TCNT1 = 0;
    // set compare match register for 1hz increments
    // Calculate OCR1A = (Clock Frequency / (Desired Frequency * prescaler)) - 1
    // uint32_t Frequency = 1.0 / (micros * 1e-6);
    uint32_t comp = (ClockFrequency / (Frequency * 8)) - 1;
    OCR1A = comp; // = (16*10^6) / (1*8) - 1 (must be <65536)
    // turn on CTC mode (resets counter to 0 when it reaches OCR1A)
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 8 prescaler
    // Prescalar of 8 allows for timers between 5 micro seconds 32 milliseconds
    TCCR1B |= (1 << CS11);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
}