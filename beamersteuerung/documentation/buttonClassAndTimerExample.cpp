// Example Code for using the button class and print 
// every 5 seconds a word into the serial monitor

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