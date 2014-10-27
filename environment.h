#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <QObject>
#include <QTimer>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QPoint>
#include "displaymanager.h"
#include "datamanager.h"
#include "texturemanager.h"
#include "hero.h"
#define G 9.81


typedef struct envTime{
    int minute;
    int second;
    int centSec;
}envTime;

envTime convertTime(int);

QString timeToString(envTime);

class Environment : public QObject
{
    Q_OBJECT

public:
    Environment();

    void keyPressEvent(QKeyEvent *);

    void init();
    void applyGravity(QMap<int,Entite*>::iterator it, TzEllipse tmpTrigger);

    void bonusPurge();

    Hero *getHero();


public slots:
    void run();
    void makeStop(bool);
    void reloadLevel();

    //HERO
    void turnRight(bool);
    void turnLeft(bool);
    void jump();
    void dash(bool right);
    void resetDashSpeed();
    void resetDashCD();
    //-



signals:
    void sendEM( QMap<int,Entite*>&);
    void sendMort(int);
    void sendScore(int);
    void sendTime(envTime);
    void sendTotalTime(envTime);

    void sendHeroPos(int,int);

    void moveSecondPlan(QPair<double,double>);
    void initSecondPlan();

    void newLevel(int);
    void endLvl(QString);
    void padBlock();
    void sigWall();
    void chgMusic(QString);


private:

    typedef std::pair<int,int> bpoint;

    //Attributs
    ImageManager IM;
    TextureManager TM;

    QMap<QString,int> playerStat;

    QTimer timer;
    QTime chrono;
    int totalTime; //milli second

    bool waitStart;
    bool isArrived = false;

    QMap<int,Entite*> entityMap;
    QMultiMap<std::string,int> entityTypeMap;

    bool goLeft = false;
    bool goRight = false;

    int width;
    int height;
    int level = 2;
    int stars = 0;
    bool stop = false;
    DataManager dataLoader;

    bool isDead = false;

    bool isSliding  = false;
    sf::Sprite hitBox;

    bool canDash = true;
    bool isDashing = false;
    double maxFallingSpeed = 8.;
    double maxNormalSpeed = 6.;
    double dashSpeed = 20.;
    int dashRefresh = 1000;
    int dashDuration = 150;
    QTimer* dashTimer;
    QTimer* dashCoolDownTimer;
    double dashCineticY;

};

#endif // ENVIRONMENT_H
