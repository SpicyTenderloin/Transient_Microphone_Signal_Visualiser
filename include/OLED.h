#include <Arduino.h>
#include <Adafruit_SSD1351.h>

// The SSD1351 is connected like this (plus VCC plus GND)
const uint8_t OLED_pin_scl_sck = 13;
const uint8_t OLED_pin_sda_mosi = 11;
const uint8_t OLED_pin_cs_ss = 10;
const uint8_t OLED_pin_res_rst = 8;
const uint8_t OLED_pin_dc_rs = 9;

// Screen dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

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