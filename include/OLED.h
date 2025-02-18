#include <Arduino.h>
#include <Adafruit_SSD1351.h>
#include "Timer1.h"


// Screen dimensions
#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 128
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 128
#endif

#ifndef OLED_h
#define OLED_h

// The SSD1351 is connected like this (plus VCC plus GND)
const uint8_t OLED_pin_scl_sck = 13;  // SCL - D13
const uint8_t OLED_pin_sda_mosi = 11; // SDA - D11
const uint8_t OLED_pin_cs_ss = 10;    //  CS - D10
const uint8_t OLED_pin_res_rst = 9;   // RES - D9
const uint8_t OLED_pin_dc_rs = 8;     //  DC - D8

// declare the display
extern Adafruit_SSD1351 oled;

// SSD1331 color definitions
const uint16_t Black = 0x0000;
const uint16_t Blue = 0x001F;
const uint16_t Red = 0xF800;
const uint16_t Green = 0x07E0;
const uint16_t Cyan = 0x07FF;
const uint16_t Magenta = 0xF81F;
const uint16_t Yellow = 0xFFE0;
const uint16_t White = 0xFFFF;

void oledInit(void);
void drawBackground(void);

#endif