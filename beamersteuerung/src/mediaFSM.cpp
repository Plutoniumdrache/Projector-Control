#include "mediaFSM.h"

mediaFSM::mediaFSM(mediaSystem* pmS)
{
    this->pmS = pmS;
    state = systemState::IDLE;
}

void mediaFSM::evalEvents()
{
    switch (state)
    {
    case systemState::IDLE:
        pmS->hdmiSwitch.setDefaultMode();
        state = systemState::INITIAL;
        break;
    case systemState::INITIAL:
        if(pmS->powerButton.isButtonPressed()) //ACHTUNG HIER FEHLT NOCH DER POWER BUTTON
        {
            pmS->beamer.switchBeamerOn();
            state = systemState::BEAMER_ON;
        }
        break;
    case systemState::BEAMER_ON:
        if(pmS->clock.isTimeExpired(40000) || pmS->beamer.checkResponseCode())
        {
            state = systemState::PRE_DEFAULT;
        }
        break;
    case systemState::PRE_DEFAULT:
        pmS->beamer.switchToHDMIswitch();
        pmS->hdmiSwitch.switchToPC();
        state = systemState::INPUT_PC;
        break;
    case systemState::INPUT_PC:
        if(pmS->clock.isTimeExpired(10000) && pmS->sourceButton.isButtonPressed())
        {
            
        }
        break;
    
    default:
        break;
    }
}


void mediaFSM::evalStates()
{

}

mediaFSM::~mediaFSM()
{
}