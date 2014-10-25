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
#define TIMER 16


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

    void bonusPurge();


public slots:
    void run();
    void pause();
    void makeStop(bool);
    void reloadLevel();


signals:
    void sendDM(DisplayManager&);
    void sendMort(int);
    void sendScore(int);
    void sendTime(envTime);
    void sendTotalTime(envTime);

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

    QVector<int> cacaIdList;
    QVector<int> cacadorIdList;

    DisplayManager DM;
    int flyID;
    int width;
    int height;
    int level = 2;
    int stars = 0;
    bool stop = false;
    DataManager dataLoader;

    bool isSliding  = false;
    sf::Sprite hitBox;


};

#endif // ENVIRONMENT_H
