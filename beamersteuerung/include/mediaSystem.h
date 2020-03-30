// Include statements
#include "beamerControl.h"
#include "switchControl.h"
#include "button.h"
#include "led.h"

// defines

// Baudrates:
#define BAUDRATE_SERIAL_MONITOR 9600
#define BAUDRATE_HDMI_SWITCH    19200
#define BAUDRATE_BEAMER         9600

// Buttons:
//#define PIN_POWER_BUTTON        22
// #define PIN_SOURCE_BUTTON       24

// // Button LEDs and status LED
// #define PIN_POWER_LED           26
// #define PIN_SOURCE_LED          28
// #define PIN_STATUS_LED          30

// // Device LEDs
// #define PIN_PC_LED              32
// #define PIN_WII_LED             34
// #define PIN_XBOX_LED            36
// #define PIN_CHROMECAST_LED      38
// #define PIN_EXTERNALINPUT_LED   40

class mediaSystem
{
private:
    // pinNumbers
    const int pin_PowerButton = 22;
    const int pin_SourceButton = 24;

    const int pin_PowerLed = 26;
    const int pin_SourceLed = 28;
    const int pin_StatusLed = 30;

    const int pin_Pc_Led = 32;
    const int pin_Wii_Led = 34;
    const int pin_xBox_Led = 36;
    const int pin_Chromecast_Led = 38;
    const int pin_externalInput_Led = 40;

public:
    mediaSystem(/* args */);
    timer clock;
    beamerControl beamer;
    switchControl hdmiSwitch;

    button powerButton(const int pin_PowerButton);
    button sourceButton(const int pin_SourceButton);

    led powerLED(const int pin_PowerLed);
    led sourceLED(const int pin_SourceLed);
    led statusLED(const int pin_StatusLed);

    led pcLED(const int pin_Pc_Led);
    led wiiLED(const int pin_Wii_Led);
    led xboxLED(const int pin_xBox_Led);
    led chromecastLED(const int pin_Chromecast_Led);
    led externalInputLED(const int pin_externalInput_Led);
    ~mediaSystem();

};

