#include "beamerFSM.h"

beamerFSM::beamerFSM() {
    this->state = SystemState::BEAMER_OFF;
    this->BeamerState = false;

}
beamerFSM::~beamerFSM() {

}

void beamerFSM::evalEvents() {
switch(state){
    case SystemState::BEAMER_OFF:

    break;
    case SystemState::BEAMER_ON:

    break;
    case SystemState::CHROMECAST:

    break;
    case SystemState::EXTERN:

    break;
    case SystemState::PC:
    
    break;
    case SystemState::VGA:

    break;
    case SystemState::WAITING:

    break;
    case SystemState::WII:

    break;
    case SystemState::XBOX:

    break;

}
}

void beamerFSM::evalStates() {

}