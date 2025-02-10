#include <Arduino.h>
#include <Adafruit_SSD1351.h>

// The SSD1351 is connected like this (plus VCC plus GND)
const uint8_t OLED_pin_scl_sck = 13;  // SCL - D13
const uint8_t OLED_pin_sda_mosi = 11; // SDA - D11
const uint8_t OLED_pin_cs_ss = 10;    //  CS - D10
const uint8_t OLED_pin_res_rst = 9;   // RES - D9
const uint8_t OLED_pin_dc_rs = 8;     //  DC - D8

// Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

extern const int SampleFrequency;

// declare the display
Adafruit_SSD1351 oled =
    Adafruit_SSD1351(
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        &SPI,
        OLED_pin_cs_ss,
        OLED_pin_dc_rs,
        OLED_pin_res_rst);

// SSD1331 color definitions
const uint16_t Black = 0x0000;
const uint16_t Blue = 0x001F;
const uint16_t Red = 0xF800;
const uint16_t Green = 0x07E0;
const uint16_t Cyan = 0x07FF;
const uint16_t Magenta = 0xF81F;
const uint16_t Yellow = 0xFFE0;
const uint16_t White = 0xFFFF;

extern const int timerperiod;

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
