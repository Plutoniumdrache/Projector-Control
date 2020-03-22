#include "button.h"

button::button(int pinNumber)
{
    this->pinNumber = pinNumber;
    pinMode(pinNumber, INPUT_PULLUP);
}

button::~button()
{
}

bool button::isButtonPressed()
{
    // Aufpassen, da pinMode INPUT_PULLUP ist. Evtl: alles reverse logic machen
    bool read = digitalRead(pinNumber); 
    if (read != lastButtonState)
    {
        lastDebounceTime = millis();
    }
    if((millis() - lastDebounceTime) > debounceDelay)
    {
        if (read != buttonState)
        {
            buttonState = read;
            if(HIGH == buttonState)
            {
                return true;
            }
        }
    }
    lastButtonState = read;
    return false;
}