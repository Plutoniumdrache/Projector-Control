#include "Arduino.h"

#define INIT 0
#define SHORT_DELAY 50

class button
{
private:
    int pinNumber = INIT;
    bool buttonState = LOW;
    bool lastButtonState = LOW;
    unsigned long debounceDelay = SHORT_DELAY;
    unsigned long lastDebounceTime = INIT;
public:
    button(int pinNumber);
    ~button();
    bool isButtonPressed();
};