#include "switchControl.h"

switchControl::switchControl(/* args */)
{
}


/* turning the auto switch mode off */
void switchControl::setDefaultMode()
{
     #ifdef TESTMODE
        Serial.println(SWITCH_MODE_DEFAULT);
    #endif

    #ifdef DEFAULTMODE
        // sending the switch command to change to the PC input Port
        Serial1.println(SWITCH_MODE_DEFAULT);
        // remember the sent command
        lastSwitchCommand = SWITCH_MODE_DEFAULT;
    #endif
}

void switchControl::switchToPC()
{
    #ifdef TESTMODE
        Serial.println(PORT_PC);
    #endif

    #ifdef DEFAULTMODE
        // sending the switch command to change to the PC input Port:
        Serial1.println(PORT_PC);
        // remember the sent command:
        lastSwitchCommand = PORT_PC;
    #endif
}

void switchControl::switchToWii()
{
    #ifdef TESTMODE
        Serial.println(PORT_WII);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_WII);
        lastSwitchCommand = PORT_WII;
    #endif
}

void switchControl::switchToXbox()
{
    #ifdef TESTMODE
        Serial.println(PORT_XBOX);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_XBOX);
        lastSwitchCommand = PORT_XBOX;
    #endif
}

void switchControl::switchToExternalInput()
{
    #ifdef TESTMODE
        Serial.println(PORT_EXTERNAL_INPUT);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_EXTERNAL_INPUT);
        lastSwitchCommand = PORT_EXTERNAL_INPUT;
    #endif
}

/* read the incomming serial data and check for the correct output
 "switch command" + " Command OK" */
bool switchControl::checkResponseCode()
{
    #ifdef DEFAULTMODE
        String readString = Serial1.readString();
        // Serial.println(readString);
        
        /* Adding the command which was send 
        to the switch return code " Command OK" */
        String combinedString = String(lastSwitchCommand + switchCommandOK);
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

switchControl::~switchControl()
{
}
