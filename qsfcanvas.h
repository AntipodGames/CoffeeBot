#ifndef QSFCANVAS_H
#define QSFCANVAS_H
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <QEvent>
#include <QMouseEvent>
//#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "qsfml.h"
#include "imagemanager.h"
#include "environment.h"
#include "animatedmanager.h"
#include "displaymanager.h"

class QSFcanvas : public Qsfml
{

    Q_OBJECT

public:
    QSFcanvas(const QPoint& Position, const QSize& Size,QWidget *parent = 0);

    ImageManager& getIM();

    void initView(int, int, int width, int height);

public slots :
    void receiveEM(QMap<int,Entite*>&);
    void switchMap(int);
    void desableLeft();
    void desableRight();
    void updateView(int x,int y);
    void blockPad();
    void moveSecondPlan(QPair<double,double>);
    void initSecondPlan();

signals:
    void setPause();
    void turnLeft(bool);
    void turnRight(bool);
    void jump();
    void dash(bool right);
    void activBoost(bool);
    void activSlide(bool);
    void sendPadPos(float,float);
    void sendStop(bool);
    void takeContr(bool);
    void retry();

private:
    ImageManager IM;
    TextureManager TM;
    AnimatedManager AM;
    DisplayManager DM;

    sf::Clock Time;
    time_t initialTime;
    Carte carte;

    sf::View view;

    bool leftPressed = false;
    bool rightPressed = false;
    bool spacePressed = false;
    bool ctrlPressed = false;
    float axisXPos = 0;
    float axisYPos = 0;
    bool padBlocked = false;

    void OnInit();
    void OnUpdate();
    void keyPressEvent(QKeyEvent *MEvent);
    void keyReleaseEvent(QKeyEvent *);

    void gamePadEvent();

};

#endif // QSFCANVAS_H
