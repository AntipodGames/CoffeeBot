#ifndef BINARYSWITCH_H
#define BINARYSWITCH_H
#include "entite.h"

class BinarySwitch : public Entite
{
public:
    BinarySwitch();

private:
    bool activated();
};

#endif // BINARYSWITCH_H
