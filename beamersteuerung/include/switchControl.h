#include "Arduino.h"

#define TESTMODE
// #define DEFAULTMODE

#define PORT_PC             "sw i01" // Input: HDMI 1
#define PORT_WII            "sw i02" // Input: HDMI 2
#define PORT_XBOX           "sw i03" // Input: HDMI 3
#define PORT_EXTERNAL_INPUT "sw i04" // Input: HDMI 4

class switchControl
{
private:
    /* data */
public:
    switchControl(/* args */);
    void switchToPC();
    void switchToWii();
    void switchToXbox();
    void switchToExternalInput();
    ~switchControl();  
};