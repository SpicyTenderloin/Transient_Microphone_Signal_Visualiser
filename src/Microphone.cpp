#include "Microphone.h"

uint16_t DCOffset = 0; // Global variable to store DC offset

// Maintainence function for trimming the microphone DC offset
uint16_t estimateDCoffset(int numSamples)
{
    // Initialise Variables wi
    float total = 0.0; // Variable to accumulate the total sum of samples

    oled.setCursor(30, 64);
    oled.setTextColor(White);
    oled.print("Loading ");

    for (int i = 0; i < numSamples; i++)
    {
        int sensorValue = analogRead(micIn); // Read the sensor value
        total += sensorValue;                // Add the sensor value to the total
        delay(10);                           // Delay between samples

        // Print Loading Status
        // Erase old
        oled.setTextColor(Black);
        oled.setCursor(80, 64);
        int percentLoad = ((static_cast<float>(i - 1) / numSamples) * 100);
        oled.print(percentLoad);
        oled.print("%");
        // Print New
        oled.setTextColor(White);
        oled.setCursor(80, 64);
        percentLoad = ((static_cast<float>(i) / numSamples) * 100);
        oled.print(percentLoad);
        oled.print("%");
    }
    // Calculate Average
    float average = total / numSamples;

    // Print DC offset to OLED
    oled.fillScreen(Black);
    oled.setCursor(15, 64);
    oled.print("DC Offset: ");
    oled.print(average / 1024 * 5);
    oled.print("V");

    // Print DC offset to Serial Monitor
    Serial.print(F("Microphone signal DC offset: "));
    Serial.print(average / 1024 * 5); // Print the average
    Serial.println(F("V"));

    // Delay to hold DC offset value on screen

    return uint16_t(average);
}
