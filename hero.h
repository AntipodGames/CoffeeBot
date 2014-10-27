#ifndef HERO_H
#define HERO_H
#include "entite.h"

class Hero : public Entite
{
    Q_OBJECT

public:
    Hero(){}
    Hero(std::string name, double vit, int px, int py, int w, int h, int life, int cad);
    Hero(const Hero& h) : Entite(h), frameY(h.frameY){}

    float frameY;
};

#endif // HERO_H
