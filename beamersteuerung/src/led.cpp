#include "led.h"

// choosing the pinNumber for the LED
led::led(int pinNumber)
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

led::~led()
{
}