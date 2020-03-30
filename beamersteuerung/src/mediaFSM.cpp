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
        state = systemState::INITIAL;
        break;
    case systemState::INITIAL:
        if(pmS->powerButton.isButtonPressed());
        {
            pmS->beamer.switchBeamerOn();
            state = systemState::BEAMER_ON;
        }
        break;
    case systemState::BEAMER_ON:
        if(pmS->clock.isTimeExpired(40000) || pmS->beamer.checkResponseCode())
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