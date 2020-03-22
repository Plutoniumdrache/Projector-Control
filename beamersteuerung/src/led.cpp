#include "led.h"

led::led(int pinNumber)
{
    this->pinNumber = pinNumber;
    pinMode(pinNumber, OUTPUT);
}

void led::switchLED_On()
{
    digitalWrite(pinNumber, HIGH);
}

void led::switchLED_Off()
{
    digitalWrite(pinNumber, LOW);
}

led::~led()
{
}