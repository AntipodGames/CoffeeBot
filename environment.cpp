#include "environment.h"


Environment::Environment(){
    width = hitBox.getScale().x;
    height = hitBox.getScale().y;
    playerStat.insert("mort",0);
    playerStat.insert("score",0);
}

void Environment::init(){
    std::cout << "Environment Initialisation" << std::endl;
    Hero* robot = new Hero("Robot",5,600,1450,10,10,1,0);
    entityMap.insert(robot->getID(),robot);
    entityTypeMap.insert(robot->get_nom(),robot->getID());

    emit sendEM(entityMap);

}


void Environment::bonusPurge(){

}

void Environment::reloadLevel(){

}

void Environment::run(){



    for(QMap<int,Entite*>::iterator it = entityMap.begin(); it != entityMap.end(); it++){
        if(it.value()->get_trigger().intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
            if(it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI + PI / 4.
                    && it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI - PI / 4.){
                it.value()->moveRight();
                it.value()->setCollLeft(true);
            }
            else
                it.value()->setCollLeft(false);
            if(it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <=  PI / 4.
                    && it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= - PI / 4.){
                it.value()->moveLeft();
                it.value()->setCollRight(true);
            }
            else
                it.value()->setCollRight(false);
        }
        applyGravity(it);
    }

    getHero()->move();


    emit sendEM(entityMap);
    emit sendHeroPos(getHero()->get_x(),getHero()->get_y());
}

void Environment::applyGravity(QMap<int,Entite*>::iterator it){
    it.value()->setOnTheFloor(false);
    if(it.value()->get_trigger().intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
        if(it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI / 2. + PI / 4.
                && it.value()->get_trigger().intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI / 2. - PI / 4.){
            it.value()->setSpeedY(0);
            it.value()->setSpeedY(it.value()->getSpeedVector().second - (double)it.value()->getHeight() * G / 200);
            it.value()->setOnTheFloor(true);
        }
        else
            if(!it.value()->getOnTheFloor())
                it.value()->setSpeedY(it.value()->getSpeedVector().second + (double)it.value()->getHeight() * G / 500);
    }
    else{
        it.value()->setSpeedY(it.value()->getSpeedVector().second + (double)it.value()->getHeight() * G / 500);
    }
}

void Environment::makeStop(bool b){
    stop = b;
}


Hero* Environment::getHero(){
    return (Hero*) entityMap.value(entityTypeMap.value("Robot"));
}


envTime convertTime(int millisec){
    envTime currentTime;
    currentTime.centSec = (millisec)%100;
    currentTime.second = (millisec/1000)%60;
    currentTime.minute = millisec/60000;

    return currentTime;

}

QString timeToString(envTime t){
    QString tmpS(QString::number(t.minute) + QString(":")
                 + QString::number(t.second) + QString(":")
                 + QString::number(t.centSec));

    return tmpS;

}

void Environment::turnRight(){
     getHero()->moveRight();
}

void Environment::turnLeft(){
    getHero()->moveLeft();
}

void Environment::jump(){
    if(getHero()->getOnTheFloor())
        getHero()->setSpeedY(- getHero()->get_vitesse() * 1.5);
}
