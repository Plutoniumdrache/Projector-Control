#include "Arduino.h"

//#define TESTMODE
#define DEFAULTMODE

#define NO_MESSAGE_IN_TESTMODE true

// Switch commands
#define PORT_PC             "sw i01" // Input: HDMI 1
#define PORT_WII            "sw i02" // Input: HDMI 2
#define PORT_XBOX           "sw i03" // Input: HDMI 3
#define PORT_EXTERNAL_INPUT "sw i04" // Input: HDMI 4
#define SWITCH_MODE_DEFAULT "swmode default" // Disable the auto switch mode

class switchControl
{
private:
    // Switch return this command + sent command:
    String switchCommandOK = " Command OK";
    String lastSwitchCommand = "nothing";
public:
    switchControl(/* args */);
    void setDefaultMode();
    void switchToPC();
    void switchToWii();
    void switchToXbox();
    void switchToExternalInput();
    bool checkResponseCode();
    virtual ~switchControl();  
};