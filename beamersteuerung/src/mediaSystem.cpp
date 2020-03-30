
#include <mediaSystem.h>

mediaSystem::mediaSystem(/* args */)
{
    Serial.begin(BAUDRATE_SERIAL_MONITOR); // USB Serial Monitor, internal serial connection
    Serial1.begin(BAUDRATE_HDMI_SWITCH); // HDMI switch on Serial port 1
    Serial2.begin(BAUDRATE_BEAMER); // Beamer on Serial port 2
}

mediaSystem::~mediaSystem()
{
}
