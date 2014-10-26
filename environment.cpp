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
    Hero* robot = new Hero("Robot",1,200,1450,4*TAILLE,4*TAILLE,1,0);
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

    if(!isDashing){
        if(getHero()->getOnTheFloor()){
            if(goLeft){
                getHero()->setSpeedX(getHero()->getSpeedVector().first - getHero()->get_vitesse());
            }
            if(goRight){
                getHero()->setSpeedX(getHero()->getSpeedVector().first + getHero()->get_vitesse());
            }
        }else{
            if(goLeft){double updatedSpeed = getHero()->getSpeedVector().first - 0.15*getHero()->get_vitesse();
                if(updatedSpeed < -maxNormalSpeed)
                    updatedSpeed = -maxNormalSpeed;
                getHero()->setSpeedX(updatedSpeed);
            }
            if(goRight){
                double updatedSpeed = getHero()->getSpeedVector().first + 0.15*getHero()->get_vitesse();
                if(updatedSpeed > maxNormalSpeed)
                    updatedSpeed = maxNormalSpeed;
                getHero()->setSpeedX(updatedSpeed);
            }
        }
    }

    for(QMap<int,Entite*>::iterator it = entityMap.begin(); it != entityMap.end(); it++){

        //TMP TRIGGER <- TRIGGER ACTUEL
        TzEllipse tmpTrigger = it.value()->get_trigger();

        //CHECK NUMERO 1 : LE CHECK POST DEPLACEMENT
//        if(tmpTrigger.intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
//            double thetaMin = tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).first()*PI;
//            double thetaMax = tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).last()*PI;
//            double theta = (thetaMax - thetaMin) / 2.;
//            if(theta >= 0.2){
//                double newTheta = theta - PI;
//                if(newTheta < -PI)
//                    newTheta += 2. * PI;
//                double dX = 2. * TAILLE * (1. - cos(theta)) * cos(newTheta);
//                double dY = - 2. * TAILLE * (1. - cos(theta)) * sin(newTheta);
//                std::cout << dX << "; " << dY << std::endl;
//                it.value()->get_trigger().move(dX, dY);
//                it.value()->set_x(it.value()->get_x() + dX);
//                it.value()->set_y(it.value()->get_y() + dY);
//            }
//        }

        //TMP TRIGGER <- TRIGGER PREVISIONNEL
        tmpTrigger = it.value()->get_trigger();
        tmpTrigger.set_centre(it.value()->get_trigger().get_centreX() + it.value()->getSpeedVector().first
                              , it.value()->get_trigger().get_centreY() + it.value()->getSpeedVector().second );

        //CHECK NUMERO 2 : LE CHECK PRE DEPLACEMENT
        if(tmpTrigger.intersection(IM.GetImage("graphics/hitmap2.png"),sf::Color::Black)){
            //collision avec un mur a gauche
            /* if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI + PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI - PI / 4.)*/
            if(PI >= tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).first()*PI
                    && PI < tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).last()*PI){
                it.value()->setSpeedX(0);
                //                it.value()->moveRight();
            }


            //collision avec un mur a droite
            /*if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <=  PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= - PI / 4.)*/
            if(0 >= tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).first()*PI
                    && 0 < tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).last()*PI){
                //                it.value()->moveLeft();
                it.value()->setSpeedX(0);
            }


            //            collision avec le plafond
            /*if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <=  -PI/2 + PI / 4.
                    && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= -PI/2 - PI / 4.)*/
            if(-PI/2 >= tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).first()*PI
                    && -PI/2 < tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).last()*PI){
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
        //        if(tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) <= PI / 2. + PI / 4.
        //                && tmpTrigger.intersectAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black) >= PI / 2. - PI / 4.)
        if(PI/2 >= tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).first()*PI
                && PI/2 < tmpTrigger.intersectTabAngle(IM.GetImage("graphics/hitmap2.png"), sf::Color::Black).last()*PI ){
            it.value()->setSpeedY(0);
            if(!isDashing)
                it.value()->setSpeedX(it.value()->getSpeedVector().first-0.15*it.value()->getSpeedVector().first);
            //            it.value()->setSpeedY(it.value()->getSpeedVector().second - (double)it.value()->getHeight() * G / 200);
            it.value()->setOnTheFloor(true);
        }
        else
            if(!it.value()->getOnTheFloor()){
                double newSpeedY = it.value()->getSpeedVector().second + 2*TAILLE * G / 500;
                if(newSpeedY > maxFallingSpeed)
                    newSpeedY = maxFallingSpeed;
                it.value()->setSpeedY(newSpeedY);
            }
    }
    else{
        double newSpeedY = it.value()->getSpeedVector().second + 2*TAILLE * G / 500;
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
    //     getHero()->moveRight();
    goRight = b;


}

void Environment::turnLeft(bool b){
    //    getHero()->moveLeft();

    goLeft = b;


}

void Environment::jump(){

    if(getHero()->getOnTheFloor())
        getHero()->setSpeedY(- getHero()->get_vitesse() * 6.5);
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
    isDashing = false;
    dashTimer->stop();
}

void Environment::resetDashCD(){
    canDash = true;
    dashCoolDownTimer->stop();
}
