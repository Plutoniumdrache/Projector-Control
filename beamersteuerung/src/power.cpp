#include "power.h"

power::power() {

}
bool power::on() {
    Serial1.write("PWR ON\r\n");
    clock.setStartTime();
    while(clock.expiredTime() < 3000)
    {
        if(Serial1.available() > 0)
        {
            memset(buffer, 0, sizeof(buffer));
            Serial1.readBytes(buffer,1);
            if(colon == *buffer)
            {
                return SUCCESSFUL;
            }
            
        }
    }
    return NOTSUCCESSFUL;
}

bool power::off()
{
    return false;
}
power::~power() {

}