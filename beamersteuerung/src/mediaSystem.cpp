
#include <mediaSystem.h>

mediaSystem::mediaSystem(/* args */)
{
    Serial.begin(BAUDRATE_SERIAL_MONITOR); // USB Serial Monitor, internal serial connection
    Serial1.begin(BAUDRATE_HDMI_SWITCH); // HDMI switch on Serial port 1
    Serial2.begin(BAUDRATE_BEAMER); // Beamer on Serial port 2
    initalizeAllObjects();
}

mediaSystem::~mediaSystem()
{
}

void mediaSystem::initalizeAllObjects()
{
    powerButton.initializeButton(pin_PowerButton);
    sourceButton.initializeButton(pin_SourceButton);
    
    powerLED.initializeLED(pin_PowerLed);
    sourceLED.initializeLED(pin_SourceLed);
    statusLED.initializeLED(pin_StatusLed);

    pcLED.initializeLED(pin_Pc_Led);
    wiiLED.initializeLED(pin_Wii_Led);
    xboxLED.initializeLED(pin_xBox_Led);
    chromecastLED.initializeLED(pin_Chromecast_Led);
    externalInputLED.initializeLED(pin_externalInput_Led);


}
