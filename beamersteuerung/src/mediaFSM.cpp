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
        pmS->beamer.switchBeamerOff();
        state = systemState::INITIAL;
        break;
    case systemState::INITIAL:
        if(pmS->powerButton.isButtonPressed())
        {
            pmS->powerLED.switchLED_Off();
            pmS->beamer.switchBeamerOn();
            state = systemState::BEAMER_ON;
        }
        break;
    case systemState::BEAMER_ON:
        if(pmS->clock.isTimeExpired(MAX_LAMP_IGNITION_TIME))// || pmS->beamer.checkResponseCode())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_DEFAULT;
        }
        break;
    case systemState::PRE_DEFAULT:
        pmS->beamer.switchToHDMIswitch();
        pmS->hdmiSwitch.switchToPC();
        state = systemState::INPUT_PC;
        break;
    case systemState::PRE_SELECT_WII:
        if (pmS->clock.isTimeExpired(HCI_TIME))
        {
            pmS->beamer.switchToHDMIswitch();
            pmS->hdmiSwitch.switchToWii();
            pmS->clock.resetTimer();
            state = systemState::INPUT_WII;
        } else if (pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_XBOX;
        }
        break;
    case systemState::PRE_SELECT_XBOX:
        if (pmS->clock.isTimeExpired(HCI_TIME))
        {
            pmS->beamer.switchToHDMIswitch();
            pmS->hdmiSwitch.switchToXbox();
            pmS->clock.resetTimer();
            state = systemState::INPUT_XBOX;
        } else if (pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_CAST;
        }
        break;
    case systemState::PRE_SELECT_CAST:
        if (pmS->clock.isTimeExpired(HCI_TIME))
        {
            pmS->beamer.switchToChromecast();
            pmS->clock.resetTimer();
            state = systemState::INPUT_CAST;
        } else if (pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_EXTERNAL;
        }
        break;
    case systemState::PRE_SELECT_EXTERNAL:
        if (pmS->clock.isTimeExpired(HCI_TIME))
        {
            pmS->beamer.switchToHDMIswitch();
            pmS->hdmiSwitch.switchToExternalInput();
            pmS->clock.resetTimer();
            state = systemState::INPUT_EXTERNAL;
        } else if (pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_PC;
        }
        break;
    case systemState::PRE_SELECT_PC:
        if (pmS->clock.isTimeExpired(HCI_TIME))
        {
            pmS->beamer.switchToHDMIswitch();
            pmS->hdmiSwitch.switchToPC();
            pmS->clock.resetTimer();
            state = systemState::INPUT_PC;
        } else if (pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_WII;
        }
        break;
    case systemState::INPUT_WII:
        if (pmS->clock.isTimeExpired(NO_HCI_TIME)) // SourceLED goes on, if no HCI time has passed
        {
            pmS->sourceLED.switchLED_On();
        }

        if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_XBOX;
        } else if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->powerButton.isButtonPressed())
        {
            pmS->beamer.switchBeamerOff();
            pmS->clock.resetTimer();
            state = systemState::BEAMER_OFF;
        }
        break;
    case systemState::INPUT_XBOX:
        if (pmS->clock.isTimeExpired(NO_HCI_TIME)) 
        {
            pmS->sourceLED.switchLED_On();
        }

        if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_CAST;
        } else if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->powerButton.isButtonPressed())
        {
            pmS->beamer.switchBeamerOff();
            pmS->clock.resetTimer();
            state = systemState::BEAMER_OFF;
        }
        break;
    case systemState::INPUT_CAST:
        if (pmS->clock.isTimeExpired(NO_HCI_TIME)) 
        {
            pmS->sourceLED.switchLED_On();
        }

        if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_EXTERNAL;
        } else if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->powerButton.isButtonPressed())
        {
            pmS->beamer.switchBeamerOff();
            pmS->clock.resetTimer();
            state = systemState::BEAMER_OFF;
        }
        break;
    case systemState::INPUT_EXTERNAL:
        if (pmS->clock.isTimeExpired(NO_HCI_TIME)) 
        {
            pmS->sourceLED.switchLED_On();
        }

        if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_PC;
        } else if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->powerButton.isButtonPressed())
        {
            pmS->beamer.switchBeamerOff();
            pmS->clock.resetTimer();
            state = systemState::BEAMER_OFF;
        }
        break;
    case systemState::INPUT_PC:
        if (pmS->clock.isTimeExpired(NO_HCI_TIME)) 
        {
            pmS->sourceLED.switchLED_On();
        }

        if(pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->sourceButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            state = systemState::PRE_SELECT_WII;
        } else if (pmS->clock.isTimeExpired(NO_HCI_TIME) && pmS->powerButton.isButtonPressed())
        {
            pmS->clock.resetTimer();
            pmS->beamer.switchBeamerOff();
            state = systemState::BEAMER_OFF;
        }        
        break;
    case systemState::BEAMER_OFF:
        if(pmS->clock.isTimeExpired(COOLDOWN_PERIOD))
        {
            pmS->clock.resetTimer();
            state = systemState::INITIAL;
        }
        break;
    default:
        break;
    }
}

// STATES
void mediaFSM::evalStates()
{
    switch (state)
    {
    case systemState::IDLE:
        // first turn everything off
        pmS->sourceLED.switchLED_Off();
        pmS->powerLED.switchLED_Off();
        pmS->statusLED.switchLED_Off();

        pmS->chromecastLED.switchLED_Off();
        pmS->externalInputLED.switchLED_Off();
        pmS->wiiLED.switchLED_Off();
        pmS->xboxLED.switchLED_Off();
        pmS->pcLED.switchLED_Off();
        break;
    case systemState::INITIAL:
        pmS->statusLED.switchLED_On();
        pmS->powerLED.switchLED_On();
        break;
    case systemState::BEAMER_ON:
        pmS->powerLED.blinkiBlinkLED(SLOW_BLINKING);
        break;
    case systemState::PRE_DEFAULT:
        pmS->powerLED.switchLED_On();
        pmS->statusLED.switchLED_Off();
        break;
    case systemState::PRE_SELECT_WII:
        pmS->sourceLED.switchLED_On();
        pmS->pcLED.switchLED_Off();
        pmS->wiiLED.blinkiBlinkLED(FAST_BLINKING);
        break;
    case systemState::PRE_SELECT_XBOX:
        pmS->sourceLED.switchLED_On();
        pmS->wiiLED.switchLED_Off();
        pmS->xboxLED.blinkiBlinkLED(FAST_BLINKING);
        break;
    case systemState::PRE_SELECT_CAST:
        pmS->sourceLED.switchLED_On();
        pmS->xboxLED.switchLED_Off();
        pmS->chromecastLED.blinkiBlinkLED(FAST_BLINKING);
        break;
    case systemState::PRE_SELECT_EXTERNAL:
        pmS->sourceLED.switchLED_On();
        pmS->chromecastLED.switchLED_Off();
        pmS->externalInputLED.blinkiBlinkLED(FAST_BLINKING);
        break;
    case systemState::PRE_SELECT_PC:
        pmS->sourceLED.switchLED_On();
        pmS->externalInputLED.switchLED_Off();
        pmS->pcLED.blinkiBlinkLED(FAST_BLINKING);
        break;
    case systemState::INPUT_WII:
        pmS->sourceLED.switchLED_Off();
        pmS->wiiLED.switchLED_On();
        break;
    case systemState::INPUT_XBOX:
        pmS->sourceLED.switchLED_Off();
        pmS->xboxLED.switchLED_On();
        break;
    case systemState::INPUT_CAST:
        pmS->sourceLED.switchLED_Off();
        pmS->chromecastLED.switchLED_On();
        break;
    case systemState::INPUT_EXTERNAL:
        pmS->sourceLED.switchLED_Off();
        pmS->externalInputLED.switchLED_On();
        break;
    case systemState::INPUT_PC:
        pmS->pcLED.switchLED_On();
        pmS->sourceLED.switchLED_Off();
        break;
    case systemState::BEAMER_OFF:
        pmS->powerLED.switchLED_Off();
        pmS->sourceLED.switchLED_Off();

        pmS->statusLED.blinkiBlinkLED(SLOW_BLINKING);
        
        pmS->chromecastLED.switchLED_Off();
        pmS->externalInputLED.switchLED_Off();
        pmS->pcLED.switchLED_Off();
        pmS->wiiLED.switchLED_Off();
        pmS->xboxLED.switchLED_Off();
        break;
    default:
        break;
    }
}

mediaFSM::~mediaFSM()
{
}