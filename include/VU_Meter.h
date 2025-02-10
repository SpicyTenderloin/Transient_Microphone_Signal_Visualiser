#include <Arduino.h>

// Define control pins
#define A_PIN 2    // Address bit A
#define B_PIN 3    // Address bit B
#define C_PIN 4    // Address bit C
#define Data_PIN 5 // Data input
// #define E_PIN 6  // Enable latch
// #define CLR_PIN 7  // Clear all outputs

void VUInit(void)
{
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
  pinMode(Data_PIN, OUTPUT);
}
