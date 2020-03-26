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
        // sending the beamer command to power the beamer on:
        Serial2.println(BEAMER_ON);
        // remember the sent command:
        lastBeamerCommand = BEAMER_ON;
    #endif
}

void beamerControl::switchBeamerOff()
{
    #ifdef TESTMODE
        Serial.println(BEAMER_OFF);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(BEAMER_OFF);
        lastBeamerCommand = BEAMER_OFF;
    #endif
}

void beamerControl::switchToHDMIswitch()
{
    #ifdef TESTMODE
        Serial.println(PORT_HDMI_SWITCH);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(PORT_HDMI_SWITCH);
        lastBeamerCommand = PORT_HDMI_SWITCH;
    #endif

}

void beamerControl::switchToChromecast()
{
    #ifdef TESTMODE
        Serial.println(PORT_CHROMECAST);
    #endif

    #ifdef DEFAULTMODE
        Serial2.println(PORT_CHROMECAST);
        lastBeamerCommand = PORT_CHROMECAST;
    #endif

}

/* read the incomming serial data and check for the correct output
 "beamer command" + ":" */
bool beamerControl::checkResponseCode()
{
    #ifdef DEFAULTMODE
        String readString = Serial1.readString();
        // Serial.println(readString);
        
        /* Adding the command which was send 
        to the switch return code " Command OK" */
        String combinedString = String(lastBeamerCommand + beamerCommandOK);
        // Serial.println(combinedString);
        
        // Trim both strings
        readString.trim();
        combinedString.trim();

        // check if the received message is correct
        return readString.equals(combinedString);
    #endif

    #ifdef TESTMODE
        return NO_MESSAGE_IN_TESTMODE;
    #endif
}

// bool beamerControl::transmissionSuccess() {
//     char *buffer = NULL;
//     char cr = ':';
//     int length = 100;
//     if(Serial1.available())
//     {
//         Serial1.readBytes(buffer, length);
//     }

//     if(*buffer == cr)
//     {
//         return true;
//         Serial.println("Es wurde gelesen:");
//         Serial.println(buffer);
//         Serial.println();
//     }else
//     {
//         return false;
//         Serial.println("Diese miese");
//     }

// }