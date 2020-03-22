// bibs
#include <Arduino.h>
#include  "power.h"
#include "beamerControl.h"
#include "button.h"

// defines

#define BAUDRATE_SERIAL_MONITOR 9600
#define BAUDRATE_HDMI_SWITCH    19200
#define BAUDRATE_BEAMER         9600

// obejcts, variables
power object;
timer clock;
beamerControl control;
char buffer;
char input;
button pushbutton1(50);
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE_SERIAL_MONITOR); // Laptop Serial Monitor, internal serial connection
  Serial1.begin(BAUDRATE_HDMI_SWITCH); // HDMI switch on Serial1
  Serial2.begin(BAUDRATE_BEAMER); // Beamer on serial 2
  
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

  
  clock.setStartTime();
   while(true)
  {
    if(pushbutton1.isButtonPressed())
      {
        Serial.println("Taster gedrückt");
      } 
    else if(clock.expiredTime() > 5000)
      {
          Serial.println("Nada");
          clock.setStartTime();
      }
  }

 /*  
  unsigned long startZeit = 0;
  unsigned long gemerkteZeit = 0;
  unsigned long aktuelleZeit = 0;
  unsigned long intervall = 5000;
  while(true)
  {
      aktuelleZeit = millis();
      if(aktuelleZeit - startZeit >= intervall)
      {
        Serial.println("Ausführung");
        startZeit = millis();
      }
  } */

  clock.setStartTime();
  while(true)
  {
    //delay(2000);
    Serial.println(clock.expiredTime());
    if(clock.expiredTime() > 6000)
    {
      Serial.println("Ausführung");
      clock.setStartTime();
    }
  }

}
