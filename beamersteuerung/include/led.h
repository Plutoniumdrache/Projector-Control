#include "Arduino.h"
#include "timer.h"

#define INIT 0
#define OFF false
#define ON true

class led
{
private:
    int pinNumber = INIT;
    timer LEDclock;
    bool ledStat = OFF;
public:
    led(int pinNumber);
    void switchLED_On();
    void switchLED_Off();
    void blinkLED(unsigned long duration, unsigned long intervall, bool endStat);
    ~led();
};