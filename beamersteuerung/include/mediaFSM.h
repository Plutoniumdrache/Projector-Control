#include "mediaSystem.h"

enum class systemState {
    IDLE,
    INITIAL,
    BEAMER_ON,
    BEAMER_OFF,
    PRE_DEFAULT,
    PRE_SELECT_WII,
    PRE_SELECT_XBOX,
    PRE_SELECT_CAST,
    PRE_SELECT_EXTERNAL,
    PRE_SELECT_PC,
    INPUT_WII,
    INPUT_XBOX,
    INPUT_CAST,
    INPUT_EXTERNAL,
    INPUT_PC,
    ERROR
};

class mediaFSM
{
private:
    mediaSystem* pmS;
    systemState state;
    unsigned long delayPeriod = 4000; // time between input selection and changing the input
public:
    mediaFSM(mediaSystem* pmS);
    void evalEvents();
    void evalStates();
    ~mediaFSM();
};

