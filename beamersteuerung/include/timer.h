/*
* Diese Klasse bietet die Möglichkeit Zeiten zu messen.
* Die Methode setStartTime() setzt den Zeitpunkt ab wo
* die Zeit gemessen werden soll.
* Die Methode expiredTime() gibt zu dem Zeitpunkt, wo sie
* aufgerufen wird, die bereits vergangene Zeit zurück.
* Der Rückkgabewert ist in Millisekunden.
*/

#include <Arduino.h>

#define EXPIRED true
#define NOT_EXPIRED false

class timer {
public:
timer();
virtual ~timer();
void setStartTime();
unsigned long expiredTime();


private:
unsigned long startTime;
unsigned long currentTime;
};