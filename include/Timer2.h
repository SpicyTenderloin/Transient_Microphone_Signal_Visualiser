#include <Arduino.h>

volatile bool timer2flag = false;

// 8 bit timer by default setup to interrupt every 500ms
void Timer2init()
{
    // Set up Timer0
    cli();      // Disable interrupts during setup
    TCCR0A = 0; // Set entire TCCR0A register to 0
    TCCR0B = 0; // Same for TCCR0B
    TCNT0 = 0;  // Initialize counter value to 0
    // Set compare match register to 125 (for 0.5 second interval)
    OCR0A = 125;
    // Turn on CTC mode (resets counter to 0 when it reaches OCR0A)
    TCCR0A |= (1 << WGM01);
    // Set CS02 and CS00 bits for 1024 prescaler
    TCCR0B |= (1 << CS02) | (1 << CS00);
    // Enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);
    sei(); // Enable interrupts
}
