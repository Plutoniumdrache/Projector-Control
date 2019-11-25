#include <Arduino.h>
#include "timer.h"

#define SUCCESSFUL true
#define NOTSUCCESSFUL false
#define DELAY 3000 // in Millisekunden


class power {
public:
power();
virtual ~power();
bool on();
bool off();

private:
char buffer[1];
char colon = ':';
timer clock;

};