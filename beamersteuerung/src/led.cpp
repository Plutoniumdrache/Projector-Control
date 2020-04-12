#include "led.h"

led::led()
{
}

// choosing the pinNumber of the LED
void led::initializeLED(int pinNumber)
{
    this->pinNumber = pinNumber;
    pinMode(pinNumber, OUTPUT); // Setting the pinMode on OUTPUT
}

/* Switching the LED on */
void led::switchLED_On()
{
    digitalWrite(pinNumber, HIGH);
}

/* Switching the LED off */
void led::switchLED_Off()
{
    digitalWrite(pinNumber, LOW);
}

/* blinking the LED for a specific amount of time,
    in a specific intervall,
    choosing the Status of the LED after blinking (on/off)*/
void led::blinkLED(unsigned long duration, unsigned long intervall, bool endStat)
{
    LEDclock.setStartTime();
    while(LEDclock.expiredTime() <= duration)
    {
        if(LEDclock.intervallTimer(intervall))
        {
            if(ledStat)
            {
                switchLED_Off();
                ledStat = OFF;
            } else if (!ledStat)
            {
                switchLED_On();
                ledStat = ON;
            }
        }
    }
    if (endStat)
    {
        switchLED_On();
    } else
    {
        switchLED_Off();
    }
}

/* Blinking the LED in a specific intervall as long as the method is called.
    No in the programm/code. */
void led::blinkiBlinkLED(unsigned long intervall)
{

    if (LEDclock.intervallTimer(intervall))
    {
        if (ledStat)
        {
            switchLED_Off();
            ledStat = OFF;
        } else if (!ledStat)
        {
            switchLED_On();
            ledStat = ON;
        }
    }

}

led::~led()
{
}