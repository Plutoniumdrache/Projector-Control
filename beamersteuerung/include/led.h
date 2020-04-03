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
    bool entry = false;
public:
    led();
    void initializeLED(int pinNumber);
    void switchLED_On();
    void switchLED_Off();
    void blinkLED(unsigned long duration, unsigned long intervall, bool endStat);
    void blinkiBlinkLED(unsigned long intervall);
    ~led();
};