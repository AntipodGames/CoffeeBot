#ifndef ANIMATEDMANAGER_H
#define ANIMATEDMANAGER_H
#include "animatedsprite.h"
#include <stdexcept>
#include <iostream>
#include <QMap>

class AnimatedManager
{
public:
    AnimatedManager();
    AnimatedManager(const AnimatedManager&);

    void add(const std::string &, AnimatedSprite);
    AnimatedSprite &get(const std::string &);
    void set(const std::string &,const std::string &);
    void changeFrame(const std::string&,int);
    void deleteFrame(const std::string&,int);

    int getFrame(std::string,int);

private:
   std::map <std::string ,AnimatedSprite> BDD;
   QMap <std::string ,QVector<int> > frameBDD;
};

#endif // ANIMATEDMANAGER_H
