#ifndef BINARYSWITCH_H
#define BINARYSWITCH_H
#include "entite.h"

class BinarySwitch : public Entite
{
public:
    BinarySwitch(){}
    BinarySwitch(std::string name, double vit, int px, int py, int w, int h, int life, int cad);
    BinarySwitch(const BinarySwitch& bs) : Entite(bs), activated(bs.activated){}

    bool isActivated();
    void allowToSwitch(bool);

public slots:
    void switchTrigger();


private:
    bool activated = false;
    bool canSwitch =false;
};

#endif // BINARYSWITCH_H
