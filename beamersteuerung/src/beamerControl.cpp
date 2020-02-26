#include "beamerControl.h"

beamerControl::beamerControl() {
    

}
beamerControl::~beamerControl() {

}

bool beamerControl::transmissionSuccess() {
char *buffer = NULL;
char cr = ':';
int length = 100;
if(Serial1.available())
{
    Serial1.readBytes(buffer, length);
}

if(*buffer == cr)
{
    return true;
    Serial.println("Es wurde gelesen:");
    Serial.println(buffer);
    Serial.println();
}else
{
    return false;
    Serial.println("Diese miese");
}

}