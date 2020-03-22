// bibs
#include <Arduino.h>
#include "power.h"
#include "beamerControl.h"
#include "button.h"
#include "led.h"

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
led LED_1(40);
  

void setup() {
  // put your setup code here, to run once:
  Serial.begin(BAUDRATE_SERIAL_MONITOR); // Laptop Serial Monitor, internal serial connection
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

  
  clock.setStartTime();
   while(true)
  {
    if(pushbutton1.isButtonPressed())
      {
        Serial.println("Taster gedrückt");
        LED_1.switchLED_On();
      } 
    else if(clock.expiredTime() > 5000)
      {
          Serial.println("Nada");
          clock.setStartTime();
          LED_1.switchLED_Off();
      }
  }



}
