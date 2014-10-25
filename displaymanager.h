#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <QVector>
#include <qsfml.h>
#include "animatedmanager.h"
#include "entite.h"
#include <QMap>
#include <utility>

class DisplayManager
{
private:
    typedef std::pair<QPoint/*entityPos*/,int/*entityID*/> sprite;
    typedef QMap<int,QVector<sprite> > spriteMap;
    spriteMap sprites;
    QMap<int,Entite*> EM;

public:
    DisplayManager();
    DisplayManager(const DisplayManager&);

    void add(int x, int y, int ID);
    void remove(int ID, int y);
    void setEM(QMap<int,Entite*>&);

    void display(AnimatedManager &, sf::RenderWindow &);



};

#endif // DISPLAYMANAGER_H
