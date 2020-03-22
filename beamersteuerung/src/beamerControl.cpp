#include "beamerControl.h"

beamerControl::beamerControl() {
    

}
beamerControl::~beamerControl() {

}

void beamerControl::switchBeamerOn()
{
    #ifdef TESTMODE
        Serial.println(BEAMER_ON);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(BEAMER_ON);
    #endif
}

void beamerControl::switchBeamerOff()
{
    #ifdef TESTMODE
        Serial.println(BEAMER_OFF);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(BEAMER_OFF);
    #endif
}

void beamerControl::switchToHDMIswitch()
{
    #ifdef TESTMODE
        Serial.println(PORT_HDMI_SWITCH);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(PORT_HDMI_SWITCH);
    #endif

}

void beamerControl::switchToChromecast()
{
    #ifdef TESTMODE
        Serial.println(PORT_CHROMECAST);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(PORT_CHROMECAST);
    #endif

}

bool beamerControl::transmissionSuccess() {
char *buffer = NULL;
char cr = ':';
int length = 100;
if(Serial1.available())
{
    Serial1.readBytes(buffer, length);
}

if(*buffer == cr)
{
    return true;
    Serial.println("Es wurde gelesen:");
    Serial.println(buffer);
    Serial.println();
}else
{
    return false;
    Serial.println("Diese miese");
}

}