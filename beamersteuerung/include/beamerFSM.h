
#include <Arduino.h>

//Systemzustände
enum class SystemState{
BEAMER_OFF,
BEAMER_ON,
WAITING,
EXTERN,
VGA,
XBOX,
WII,
CHROMECAST,
PC
};

class beamerFSM {
public:
beamerFSM();
virtual ~beamerFSM();
void evalEvents();
void evalStates();


private:
SystemState state;
bool BeamerState;


};