#include "binaryswitch.h"

BinarySwitch::BinarySwitch(std::string name, double vit, int px, int py, int w, int h, int life, int cad)
    : Entite(name,vit,px,py,w,h,life)
{
}

void BinarySwitch::switchTrigger(){
    if(canSwitch)
        activated = !activated;
}

bool BinarySwitch::isActivated(){
    return activated;
}

void BinarySwitch::allowToSwitch(bool b){
    canSwitch = b;

}
