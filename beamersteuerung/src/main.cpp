#include <Arduino.h>
#include  "power.h"
  timer clock;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  static int count = 0;

  Serial.println("Start!");
  delay(3000);
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
  count = 0;
  
}
