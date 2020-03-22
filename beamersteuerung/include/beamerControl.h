#include <Arduino.h>

#define TESTMODE
// #define DEFAULTMODE

#define BEAMER_ON "PWR ON"
#define BEAMER_OFF "PWR OFF"
#define PORT_HDMI_SWITCH "SOURCE 30" // Input: HDMI 1
#define PORT_CHROMECAST "SOURCE A0" // Input: HDMI 2

class beamerControl {
public:
beamerControl();
virtual ~beamerControl();
bool transmissionSuccess();
void switchBeamerOn();
void switchBeamerOff();
void switchToHDMIswitch();
void switchToChromecast();

private:

};