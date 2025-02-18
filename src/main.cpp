#include <stdio.h>
#include <Adafruit_SSD1351.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#include "Microphone.h"
#include "OLED.h"
#include "Timer1.h"
#include "VU_Meter.h"

void setup()
{
  Serial.begin(9600);
  Serial.println(F("Hello world!"));

  // Initialize the display
  oledInit();

  // Initialise VU meter
  VUInit();
  digitalWrite(Level1, HIGH);
  
  // Calculate DC offset
  DCOffset = estimateDCoffset(100);
  delay(500);

  // Draw Background
  oled.fillScreen(Black);
  drawBackground();

  // Configure Timer 1 to trigger every 10 microseconds for 100kHz
  timer1init(SampleFrequency);

  Serial.println("Init Complete");
  sei();
}
void loop()
{
  VUupdate();
}

// Timer1 ISR
ISR(TIMER1_COMPA_vect)
{
  // Counter to keep track of position in readings array
  static int count = 0;

  // Test old reading within bounds and erase
  if (((readings[count] * SCREEN_HEIGHT) / 1024) > 7 && ((readings[count] * SCREEN_HEIGHT) / 1024) < 114)
  {
    oled.drawPixel(count, SCREEN_HEIGHT - ((readings[count] * SCREEN_HEIGHT) / 1024), Black);
  }
  // Measure new reading
  readings[count] = analogRead(micIn);

  // Test new reading within bounds and print
  if (((readings[count] * SCREEN_HEIGHT) / 1024) > 7 && ((readings[count] * SCREEN_HEIGHT) / 1024) < 114)
  {
    oled.drawPixel(count, SCREEN_HEIGHT - ((readings[count] * SCREEN_HEIGHT) / 1024), White);
  }
  // Increment counter, reset to zero after 128
  count = (count + 1) % SCREEN_WIDTH;
}