#include <Arduino.h>

#define TESTMODE
// #define DEFAULTMODE

#define BEAMER_ON "PWR ON"
#define BEAMER_OFF "PWR OFF"
#define HDMI1 "SOURCE 30"
#define HDMI2 "SOURCE A0"

class beamerControl {
public:
beamerControl();
virtual ~beamerControl();
bool transmissionSuccess();
void switchBeamerOn();
void switchBeamerOff();
void switchToHDMI1();
void switchToHDMI2();

private:

};