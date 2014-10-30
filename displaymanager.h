#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <QVector>
#include "qobject.h"
#include "qsfml.h"
#include "animatedmanager.h"
#include "hero.h"
#include "binaryswitch.h"
#include "carte.h"
#include "texturemanager.h"
#include <QMap>
#include <utility>

class DisplayManager : public QObject
{
    Q_OBJECT

private:
    typedef std::pair<QPoint/*entityPos*/,int/*entityID*/> sprite;
    typedef QMap<int,QVector<sprite> > spriteMap;
    spriteMap sprites;
    QMap<int,Entite*> EM;
    Carte carte;

public slots:
    void moveSecondPlan(QPair<double,double>);
    void initSecondPlan();

public:    
    DisplayManager();
    DisplayManager(const DisplayManager&);

    void init(TextureManager&);

    void add(int x, int y, int ID);
    void remove(int ID, int y);
    void setEM(QMap<int,Entite*>&);

    Carte& getCarte();

    void display(TextureManager&,AnimatedManager &, sf::RenderWindow &);



};

#endif // DISPLAYMANAGER_H
