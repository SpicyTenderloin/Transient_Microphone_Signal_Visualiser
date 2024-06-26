#include <Arduino.h>
#include <Adafruit_SSD1351.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#include "Microphone.h"
#include "OLED.h"
#include "Timer1.h"
#include "Timer2.h"

// Initialise array to store samples
volatile int readings[SCREEN_WIDTH];

const int timerperiod = 10;

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Hello world!"));

  // Initialize the display
  oledInit();

  // Calculate DC offset
  estimateDCoffset(300);
  delay(2000);

  // Draw Background
  oled.fillScreen(Black);
  drawBackground();

  // Configure Timer 1 to trigger every 10 microseconds for 100kHz
  timer1init(timerperiod);

  // Optional Second Timer
  // Timer2init();

  Serial.println("Init Complete");
  sei();
}
void loop()
{
  // Uncomment to calibrate microphone
  // cli();
  // estimateDCoffset(1000);
}

// Timer1 ISR
ISR(TIMER1_COMPA_vect)
{
  // Counter to keep track of position in readings array
  static int count = 0;

  // Test old reading within bounds and erase
  if (((readings[count] * SCREEN_HEIGHT) / 1024) > 7 && ((readings[count] * SCREEN_HEIGHT) / 1024) < 114)
  {
    oled.drawPixel(count, ((readings[count] * SCREEN_HEIGHT) / 1024), Black);
  }
  // Measure new reading
  readings[count] = analogRead(micIn);

  // Test new reading within bounds and print
  if (((readings[count] * SCREEN_HEIGHT) / 1024) > 7 && ((readings[count] * SCREEN_HEIGHT) / 1024) < 114)
  {
    oled.drawPixel(count, ((readings[count] * SCREEN_HEIGHT) / 1024), White);
  }
  count = (count + 1) % SCREEN_WIDTH; // Wrap around
}

// OPTIONAL Second Timer

// // Timer 0 ISR
// ISR(TIMER0_COMPA_vect)
// {
//     timer0_ticks++;
//     if (timer0_ticks >= 2)
//     { // 2 ticks * 0.5 seconds = 1 second
//         timer2flag = true;
//         timer0_ticks = 0; // Reset the tick counter
//     }
// }