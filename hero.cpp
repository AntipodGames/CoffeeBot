#include "hero.h"

Hero::Hero(std::string name, double vit, int px, int py, int w, int h, int life, int cad)
    : Entite(name,vit,px,py,w,h,life)
{
    frameY =1;
}

