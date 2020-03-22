#include "Arduino.h"

#define INIT 0

class led
{
private:
    int pinNumber = INIT;
public:
    led(int pinNumber);
    void switchLED_On();
    void switchLED_Off();
    ~led();
};