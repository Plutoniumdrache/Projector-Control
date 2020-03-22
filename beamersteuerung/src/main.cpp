// bibs
#include <Arduino.h>
#include "beamerControl.h"
#include "switchControl.h"
#include "button.h"
#include "led.h"
#include "timer.h"

// defines

// #define TESTMODE
// #define MINIMALTEST

#define BAUDRATE_SERIAL_MONITOR 9600
#define BAUDRATE_HDMI_SWITCH    19200
#define BAUDRATE_BEAMER         9600

// obejcts, variables
timer clock;
beamerControl beamer;

button powerButton(22);
button sourceButton(24);

led powerLED(26);
led sourceLED(28);
led statusLED(30);

led pcLED(32);
led wiiLED(34);
led xboxLED(36);
led chromecastLED(38);
led externalInputLED(40);
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE_SERIAL_MONITOR); // USB Serial Monitor, internal serial connection
  Serial1.begin(BAUDRATE_HDMI_SWITCH); // HDMI switch on Serial port 1
  Serial2.begin(BAUDRATE_BEAMER); // Beamer on Serial port 2
  
} 

void loop() {
  // put your main code here, to run repeatedly:
  
 /*  static int count = 0;

  Serial.println("Start!");
  delay(3000);
  clock.setStartTime();
  while(clock.expiredTime() < 3000)
  {
    Serial.println("Moin Moin");
    delay(1000);
  }
  
  if(!count)
  {
    Serial.println("Zeit abgelaufen");
    count = 1;
    delay(2000);
  }
  count = 1; */

 // Moin mOIn 

  










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
  
    // powerLED.switchLED_On();
    // sourceLED.switchLED_On();
    statusLED.switchLED_On();
    pcLED.switchLED_On();
    wiiLED.switchLED_On();
    xboxLED.switchLED_On();
    chromecastLED.switchLED_On();
    externalInputLED.switchLED_On();

    // delay(1000);

    // powerLED.switchLED_Off();
    // sourceLED.switchLED_Off();
    // statusLED.switchLED_Off();
    // pcLED.switchLED_Off();
    // wiiLED.switchLED_Off();
    // xboxLED.switchLED_Off();
    // chromecastLED.switchLED_Off();
    // externalInputLED.switchLED_Off();

    // delay(1000);
  }
  #endif
  


}
