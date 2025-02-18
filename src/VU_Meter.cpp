#include "VU_Meter.h"
#include "Microphone.h"

uint32_t lastUpdateMillis = 0;

// Intialise pins for VUmeter
void VUInit(void)
{
    pinMode(Level1, OUTPUT);
    pinMode(Level2, OUTPUT);
    pinMode(Level3, OUTPUT);
    pinMode(Level4, OUTPUT);
    pinMode(Level5, OUTPUT);
    pinMode(Level6, OUTPUT);
    pinMode(Level7, OUTPUT);
    pinMode(Level8, OUTPUT);
    pinMode(Level9, OUTPUT);
    pinMode(Level10, OUTPUT);
    pinMode(Level11, OUTPUT);
    pinMode(Level12, OUTPUT);
}

// Update the latches for VU meter
void VUupdate(void)
{
    uint32_t currentMillis = millis();

    if (currentMillis - lastUpdateMillis >= interval)
    {
        lastUpdateMillis = currentMillis;

        int maxRead = 0;
        for (int i = 0; i < (SCREEN_WIDTH); i++)
        {
            if (readings[i] > maxRead)
            {
                maxRead = readings[i];
            }
        }
        // int VUlevel = ceil((abs(maxRead - DCOffset) * 12.0) / 512.0);

        uint16_t amplitude = ceil(abs(maxRead - DCOffset));
        uint8_t VUlevel;

        // Map VU level to an parabolic curve (y=2.27x^2)
        if (amplitude <= 32)
        {
            VUlevel = 0;
        }
        else if (amplitude > 32 && amplitude <= 50)
        {
            VUlevel = 1;
        }
        else if (amplitude > 50 && amplitude <= 72)
        {
            VUlevel = 2;
        }
        else if (amplitude > 72 && amplitude <= 98)
        {
            VUlevel = 3;
        }
        else if (amplitude > 98 && amplitude <= 128)
        {
            VUlevel = 4;
        }
        else if (amplitude > 128 && amplitude <= 162)
        {
            VUlevel = 5;
        }
        else if (amplitude > 162 && amplitude <= 200)
        {
            VUlevel = 6;
        }
        else if (amplitude > 200 && amplitude <= 242)
        {
            VUlevel = 7;
        }
        else if (amplitude > 242 && amplitude <= 288)
        {
            VUlevel = 8;
        }
        else if (amplitude > 288 && amplitude <= 338)
        {
            VUlevel = 9;
        }
        else if (amplitude > 338 && amplitude <= 392)
        {
            VUlevel = 10;
        }
        else if (amplitude > 392 && amplitude <= 450)
        {
            VUlevel = 11;
        }
        else if (amplitude > 450 && amplitude <= 512)
        {
            VUlevel = 12;
        }
        else
        {
            VUlevel = 0;
        }
        // Serial.println(VUlevel);

        switch (VUlevel)
        {

        case 12:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, HIGH);
            digitalWrite(Level9, HIGH);
            digitalWrite(Level10, HIGH);
            digitalWrite(Level11, HIGH);
            digitalWrite(Level12, HIGH);
            break;

        case 11:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, HIGH);
            digitalWrite(Level9, HIGH);
            digitalWrite(Level10, HIGH);
            digitalWrite(Level11, HIGH);
            digitalWrite(Level12, LOW);
            break;

        case 10:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, HIGH);
            digitalWrite(Level9, HIGH);
            digitalWrite(Level10, HIGH);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 9:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, HIGH);
            digitalWrite(Level9, HIGH);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 8:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, HIGH);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 7:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, HIGH);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 6:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, HIGH);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 5:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, HIGH);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 4:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, HIGH);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 3:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, HIGH);
            digitalWrite(Level4, LOW);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 2:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, HIGH);
            digitalWrite(Level3, LOW);
            digitalWrite(Level4, LOW);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 1:
            digitalWrite(Level1, HIGH);
            digitalWrite(Level2, LOW);
            digitalWrite(Level3, LOW);
            digitalWrite(Level4, LOW);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        case 0:
            digitalWrite(Level1, LOW);
            digitalWrite(Level2, LOW);
            digitalWrite(Level3, LOW);
            digitalWrite(Level4, LOW);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            digitalWrite(Level12, LOW);
            break;

        default:
            digitalWrite(Level1, LOW);
            digitalWrite(Level2, LOW);
            digitalWrite(Level3, LOW);
            digitalWrite(Level4, LOW);
            digitalWrite(Level5, LOW);
            digitalWrite(Level6, LOW);
            digitalWrite(Level7, LOW);
            digitalWrite(Level8, LOW);
            digitalWrite(Level9, LOW);
            digitalWrite(Level10, LOW);
            digitalWrite(Level11, LOW);
            break;
        }
    }
}