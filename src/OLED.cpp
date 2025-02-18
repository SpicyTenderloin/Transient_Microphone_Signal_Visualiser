#include "OLED.h"

// Initialise array to store samples
volatile int readings[SCREEN_WIDTH];

// declare the display
Adafruit_SSD1351 oled =
    Adafruit_SSD1351(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        &SPI,
        OLED_pin_cs_ss,
        OLED_pin_dc_rs,
        OLED_pin_res_rst);

void oledInit(void)
{
    oled.begin();
    oled.setFont();
    oled.fillScreen(Black);
    oled.setTextColor(White);
    oled.setTextSize(1);
    oled.enableDisplay(1);
}

void drawBackground(void)
{
    oled.setCursor(1, 1);
    oled.print("5V     Transient");
    oled.setCursor(1, 121);
    oled.print("0V");
    oled.setCursor(50, 121);
    oled.print("Fs:");
    oled.print(SampleFrequency / 1e3);
    oled.print(" kHz");
    Serial.println("Init Complete");
}