#include "environment.h"


Environment::Environment(){
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

    BinarySwitch* binSwitch = new BinarySwitch("trigger",0,2600,670,5*TAILLE,5*TAILLE,1,0);
    entityMap.insert(binSwitch->getID(),binSwitch);
    entityTypeMap.insert(binSwitch->get_nom(),binSwitch->getID());

    BinarySwitch* lightS = new BinarySwitch("light",0,200,1425,5*TAILLE,5*TAILLE,1,0);
    entityMap.insert(lightS->getID(),lightS);
    entityTypeMap.insert(lightS->get_nom(),lightS->getID());

    //    delete robot;
    //    delete binSwitch;

    emit sendEM(entityMap);

}


void Environment::bonusPurge(){

}

void Environment::reloadLevel(){
    getHero()->set_x(200);
    getHero()->set_y(1450);
    getHero()->setSpeedX(0);
    getHero()->setSpeedY(0);
    emit initSecondPlan();
//TODO reinitialisation des trigger
//    for(QMultiMap<std::string,int>::iterator it = entityTypeMap.begin()
//        ; it != entityTypeMap.end(); it++){
//        if(it.key() == "triggerOn")
//            entityMap.value(it.value())->
//    }
}

void Environment::setHitbox(std::string str){
    hitbox = str;
}

//bool Environment::collisionManager( QPair<double,double> speedVector){

//}

void Environment::run(){

    if(!isDashing){
        if(getHero()->getOnTheFloor()){
            if(goLeft){
                getHero()->setSpeedX(getHero()->getSpeedVector().first - getHero()->get_vitesse());
                getHero()->setFrame(getHero()->getFrame()+0.5);
            }
            if(goRight){
                getHero()->setSpeedX(getHero()->getSpeedVector().first + getHero()->get_vitesse());
                getHero()->setFrame(getHero()->getFrame()+0.5);

            }
        }else{
            if(goLeft){double updatedSpeed = getHero()->getSpeedVector().first - 0.2*getHero()->get_vitesse();
                if(updatedSpeed < -maxNormalSpeed)
                    updatedSpeed = -maxNormalSpeed;
                getHero()->setSpeedX(updatedSpeed);
            }
            if(goRight){
                double updatedSpeed = getHero()->getSpeedVector().first + 0.2*getHero()->get_vitesse();
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
        if(tmpTrigger.intersection(IM.GetImage(hitbox),sf::Color::Black)){
            double thetaMin = tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).first()*PI;
            double thetaMax = tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).last()*PI;
            double tmpTheta = (thetaMax - thetaMin) / 2.;
            if(tmpTheta >= 0.2){
                double finalTheta = thetaMax - tmpTheta - PI;
                if(finalTheta < -PI)
                    finalTheta += 2.* PI;

                double dX = 4. * TAILLE * (1. - cos(tmpTheta)) * cos(finalTheta);
                double dY = 4. * TAILLE * (1. - cos(tmpTheta)) * sin(finalTheta);

//                if(dY < 1. && dY > -1.){
//                    std::cout << "mur ";
//                    if(dX < 0.)
//                        std::cout << "à droite" << std::endl;
//                    else
//                        std::cout << "à gauche" << std::endl;

//                }

                it.value()->get_trigger().move(dX, dY);
                it.value()->set_x(it.value()->get_x() + dX);
                it.value()->set_y(it.value()->get_y() + dY);
            }



        } //


        //    std::cout << getHero()->frameY << std::endl;

        //TMP TRIGGER <- TRIGGER PREVISIONNEL
        tmpTrigger = it.value()->get_trigger();
        tmpTrigger.set_centre(it.value()->get_trigger().get_centreX() + it.value()->getSpeedVector().first
                              , it.value()->get_trigger().get_centreY() + it.value()->getSpeedVector().second );

        //CHECK NUMERO 2 : LE CHECK PRE DEPLACEMENT
        if(tmpTrigger.intersection(IM.GetImage(hitbox),sf::Color::Black)){
            //collision avec un mur a gauche
            if(PI >= tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).first()*PI
                    && PI < tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).last()*PI){
                it.value()->setSpeedX(0);
            }
            //collision avec un mur a droite
            if(0 >= tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).first()*PI
                    && 0 < tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).last()*PI){
                it.value()->setSpeedX(0);
            }
            //            collision avec le plafond
            if(3.* PI/2. >= tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).first()*PI
                    && 3.* PI/2. < tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).last()*PI){
                it.value()->setSpeedY(0);
            }
        }
        if(tmpTrigger.intersection(IM.GetImage(hitbox),sf::Color::Red)){
            reloadLevel();
        }
        if(!isDashing){
            applyGravity(it,tmpTrigger);
        }
        //gestion des triggers
        if(it.value()->get_nom() == "trigger" || it.value()->get_nom() == "triggerOn"){//operation specifique aux BinarySwitch.
            if(it.value()->get_trigger().isIN(getHero()->get_x(),getHero()->get_y())){
                ((BinarySwitch*) it.value())->allowToSwitch(true);
            }else ((BinarySwitch*) it.value())->allowToSwitch(false);
            if(it.value()->getID() == 2 && ((BinarySwitch*) it.value())->isActivated())
                hitbox = "graphics/hitmap2.png";
        }

    }

    if(abs(getHero()->getSpeedVector().first) > 0. && abs(getHero()->getSpeedVector().first) <= 2.)
        getHero()->frameY = 1;
    else if(abs(getHero()->getSpeedVector().first) > 2. && abs(getHero()->getSpeedVector().first) <=4)
        getHero()->frameY = 2;
    else if(abs(getHero()->getSpeedVector().first) >4 && abs(getHero()->getSpeedVector().first) <= 5)
        getHero()->frameY = 3;
    else if(abs(getHero()->getSpeedVector().first) > 5)
        getHero()->frameY = 4;
    //   else if(getHero()->getSpeedVector().first > 5)
    //       getHero()->frameY = 4;

    if(getHero()->getSpeedVector().first < 0 && goLeft)
        getHero()->setState("LEFT");
    if(getHero()->getSpeedVector().first >= 0 && goRight )
        getHero()->setState("RIGHT");


    emit moveSecondPlan(getHero()->getSpeedVector());

    getHero()->move();


    emit sendEM(entityMap);
    emit sendHeroPos(getHero()->get_x(),getHero()->get_y());
}

void Environment::applyGravity(QMap<int,Entite*>::iterator it,TzEllipse tmpTrigger){
    it.value()->setOnTheFloor(false);
    if(tmpTrigger.intersection(IM.GetImage(hitbox),sf::Color::Black)){
        //        if(tmpTrigger.intersectAngle(IM.GetImage(hitbox), sf::Color::Black) <= PI / 2. + PI / 4.
        //                && tmpTrigger.intersectAngle(IM.GetImage(hitbox), sf::Color::Black) >= PI / 2. - PI / 4.)
        if(PI/2 >= tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).first()*PI
                && PI/2 < tmpTrigger.intersectTabAngle(IM.GetImage(hitbox), sf::Color::Black).last()*PI ){
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

void Environment::switchTriggers(){
    ((BinarySwitch*) entityMap.value(2))->switchTrigger();
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
        dashCineticY = getHero()->getSpeedVector().second;
        getHero()->setSpeedY(0);
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
    getHero()->setSpeedY(dashCineticY);
    dashCineticY = 0;
    isDashing = false;
    dashTimer->stop();
}

void Environment::resetDashCD(){
    canDash = true;
    dashCoolDownTimer->stop();
}
