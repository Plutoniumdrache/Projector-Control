#include "timer.h"

timer::timer() {

}

/* Setzen der Startzeit, ab hier wird die Zeit gemessen */
void timer::setStartTime() {
    startTime = millis(); 
}

/*
* Berechnung der vergangenen Zeit vom setzen der Startzeit
* mit setStartTime() an, bis zum Zeitpubkt an der die Methode
* expiredTime() aufgerufen wird.
* Rückgabe der vergangenen Zeit in Millisekunden.
*/
unsigned long timer::expiredTime() {
    currentTime = millis();
    return (currentTime-startTime);
}

timer::~timer() {

}