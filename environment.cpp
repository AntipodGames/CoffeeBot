#include "environment.h"


Environment::Environment(){
    width = hitBox.getScale().x;
    height = hitBox.getScale().y;
    playerStat.insert("mort",0);
    playerStat.insert("score",0);

    dashTimer = new QTimer();
    dashCoolDownTimer = new QTimer();
    dashTimer->setInterval(dashDuration);
    dashCoolDownTimer->setInterval(dashRefresh);
    connect(dashTimer, SIGNAL(timeout()), this, SLOT(resetDashSpeed()));
    connect(dashCoolDownTimer, SIGNAL(timeout()), this, SLOT(resetDashCD()));
}

void Environment::init(){
    std::cout << "Environment Initialisation" << std::endl;
    Hero* robot = new Hero("Robot",5,200,1450,10,10,1,0);
    entityMap.insert(robot->getID(),robot);
    entityTypeMap.insert(robot->get_nom(),robot->getID());

    emit sendEM(entityMap);

}


void Environment::bonusPurge(){

}

void Environment::reloadLevel(){

}

//bool Environment::collisionManager( QPair<double,double> speedVector){

//}

void Environment::run(){


    for(QMap<int,Entite*>::iterator it = entityMap.begin(); it != entityMap.end(); it++){
        TzEllipse tmpTrigger = it.value()->get_trigger();
        tmpTrigger.set_centre(it.value()->get_trigger().get_centreX() + it.value()->getSpeedVector().first
                              , it.value()->get_trigger().get_centreY() + it.value()->getSpeedVector().second );
        if(tmpTrigger.intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
            //collision avec un mur a gauche
            if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI + PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI - PI / 4.){
                it.value()->setSpeedX(0);
//                it.value()->moveRight();
            }


            //collision avec un mur a droite
            if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <=  PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= - PI / 4.){
//                it.value()->moveLeft();
                it.value()->setSpeedX(0);
            }


//            collision avec le plafond
            if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <=  -PI/2 + PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= -PI/2 - PI / 4.){
                it.value()->setSpeedY(0);
            }

        }
        applyGravity(it,tmpTrigger);
    }



    getHero()->move();


    emit sendEM(entityMap);
    emit sendHeroPos(getHero()->get_x(),getHero()->get_y());
}

void Environment::applyGravity(QMap<int,Entite*>::iterator it,TzEllipse tmpTrigger){
    it.value()->setOnTheFloor(false);
    if(tmpTrigger.intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
        if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI / 2. + PI / 4.
                && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI / 2. - PI / 4.){
            it.value()->setSpeedY(0);
            it.value()->setOnTheFloor(true);
        }
        else
            if(!it.value()->getOnTheFloor()){
                double newSpeedY = it.value()->getSpeedVector().second + (double)it.value()->getHeight() * G / 400;
                if(newSpeedY > maxFallingSpeed)
                    newSpeedY = maxFallingSpeed;
                it.value()->setSpeedY(newSpeedY);
            }
    }
    else{
        double newSpeedY = it.value()->getSpeedVector().second + (double)it.value()->getHeight() * G / 400;
        if(newSpeedY > maxFallingSpeed)
            newSpeedY = maxFallingSpeed;
        it.value()->setSpeedY(newSpeedY);
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

void Environment::turnRight(bool b){
    if(b)
        getHero()->setSpeedX(getHero()->getSpeedVector().first + getHero()->get_vitesse());
    else {
        if(getHero()->getSpeedVector().first - getHero()->get_vitesse() > 0)
            getHero()->setSpeedX(getHero()->getSpeedVector().first - getHero()->get_vitesse());
        else getHero()->setSpeedX(0);
    }
}

void Environment::turnLeft(bool b){
    if(b)
        getHero()->setSpeedX(getHero()->getSpeedVector().first - getHero()->get_vitesse());
    else  {
        if(getHero()->getSpeedVector().first + getHero()->get_vitesse() < 0)
            getHero()->setSpeedX(getHero()->getSpeedVector().first - getHero()->get_vitesse());
        else getHero()->setSpeedX(0);
    }
}

void Environment::jump(){
    if(getHero()->getOnTheFloor())
        getHero()->setSpeedY(- getHero()->get_vitesse() * 1.5);
}

void Environment::dash(bool right){
    if(canDash){
        dashTimer->start();
        dashCoolDownTimer->start();
        isDashing = true;
        canDash = false;
        if(right){
            getHero()->setSpeedX(dashSpeed);
        }
        else{
            getHero()->setSpeedX(-dashSpeed);
        }
    }
}

void Environment::resetDashSpeed(){
    getHero()->setSpeedX(0);
    isDashing = false;
    dashTimer->stop();
}

void Environment::resetDashCD(){
    canDash = true;
    dashCoolDownTimer->stop();
}
