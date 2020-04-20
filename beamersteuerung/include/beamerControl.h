#include <Arduino.h>

//#define TESTMODE
#define DEFAULTMODE

#define NO_MESSAGE_IN_TESTMODE true

#define BEAMER_CMD_ON "PWR ON"
#define BEAMER_CMD_OFF "PWR OFF"
#define PORT_HDMI_SWITCH "SOURCE 30" // Input: HDMI 1
#define PORT_CHROMECAST "SOURCE A0" // Input: HDMI 2

class beamerControl
{
private:
    String beamerCommandOK = ":";
    String lastBeamerCommand = "nothing";
public:
    beamerControl();
    virtual ~beamerControl();
    void switchBeamerOn();
    void switchBeamerOff();
    void switchToHDMIswitch();
    void switchToChromecast();
    bool checkResponseCode();


    // bool transmissionSuccess();

};