#include "switchControl.h"

switchControl::switchControl(/* args */)
{
}

void switchControl::switchToPC()
{
    #ifdef TESTMODE
        Serial.println(PORT_PC);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_PC);
    #endif
}

void switchControl::switchToWii()
{
    #ifdef TESTMODE
        Serial.println(PORT_WII);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_WII);
    #endif
}

void switchControl::switchToXbox()
{
    #ifdef TESTMODE
        Serial.println(PORT_XBOX);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_XBOX);
    #endif
}

void switchControl::switchToExternalInput()
{
    #ifdef TESTMODE
        Serial.println(PORT_EXTERNAL_INPUT);
    #endif

    #ifdef DEFAULTMODE
        Serial1.println(PORT_EXTERNAL_INPUT);
    #endif
}

switchControl::~switchControl()
{
}
