// bibs
#include <Arduino.h>
#include "mediaFSM.h"


// defines

// #define TESTMODE
// #define MINIMALTEST



// obejcts, variables


  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  
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
  

  // int ledStat = LOW;

  // // Timerfunktion probieren
  // while(true)
  // {
  //   if(clock.isTimeExpired(10000))
  //   {
  //     if(ledStat)
  //     {
  //       sourceLED.switchLED_Off();
  //       ledStat = LOW;
  //     } else if (!ledStat)
  //     {
  //       sourceLED.switchLED_On();
  //       ledStat = HIGH;
  //     }
  //   }
  //   // else if(clock2.isTimeExpired(500))
  //   // {
  //   //   sourceLED.switchLED_Off();
  //   // }
  // }

  // String readString;
  // bool test = true;
  // while(true)
  // {
  //   if (test)
  //   {
  //     Serial1.println("sw +");
  //     Serial1.flush();

  //     readString = Serial1.readString();
  //     Serial.println(readString);
  //   }
  //   //test = false;
  //   delay(2000);
  // }

  // switchControl switchi;
  // while(true)
  // {
  //     switchi.switchToPC();
  //     if(switchi.checkResponseCode())
  //     {
  //       Serial.println("fuck yes");
  //     }
  //     delay(6000);
  // }

  // //jetzt aber richtig:
  // mediaSystem* pmS = new mediaSystem;
  // mediaFSM* pff = new mediaFSM(pmS);
  // while(true)
  // {
  //   pff->evalEvents();
  //   pff->evalStates();
  // }


}
