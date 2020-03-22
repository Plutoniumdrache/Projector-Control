
//Beispiel Code für die Anwendung der Timer Klasse

Serial.println("Start!"); // Code Ausführung beginnt
  delay(3000); // Kurze Pause
  clock.setStartTime(); // Startzeit wird gesetzt

  /* prüfen ob die bereits laufende Zeit kleiner 
  als die maximale Zeitdauer ist */
  while(clock.expiredTime() < 3000)  
  {
    Serial.println("Moin Moin"); // Testausgabe erfolgt 3 mal
    delay(1000);
  }