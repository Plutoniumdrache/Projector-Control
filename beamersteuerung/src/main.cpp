// bibs
#include <Arduino.h>
#include "mediaFSM.h"


// defines

// #define TESTMODE
// #define MINIMALTEST



// obejcts, variables


  

void setup() {
  // put your setup code here, to run once:
  
} 

void loop() {
  // put your main code here, to run repeatedly:
  

  #ifdef MINIMALTEST
  // Test setup: all LEDs on, button LEDs on if button is pressed
  clock.setStartTime();
   while(true)
  {
    if(powerButton.isButtonPressed())
      {
        Serial.println("ON/OFF Taste gedrückt");
        powerLED.switchLED_On();
      } 
    else if(sourceButton.isButtonPressed())
      {
        Serial.println("Source Taste gedrückt");
        sourceLED.switchLED_On();
      }
    else if(clock.expiredTime() > 5000)
      {
          Serial.println("Nix los hier");
          clock.setStartTime();
          powerLED.switchLED_Off();
          sourceLED.switchLED_Off();
      }
  
    statusLED.switchLED_On();
    pcLED.switchLED_On();
    wiiLED.switchLED_On();
    xboxLED.switchLED_On();
    chromecastLED.switchLED_On();
    externalInputLED.switchLED_On();

  #endif
  

  //jetzt aber richtig (normal mode):
  mediaSystem* pmS = new mediaSystem;
  mediaFSM* pff = new mediaFSM(pmS);
  while(true)
  {
    pff->evalEvents();
    pff->evalStates();
  }


}