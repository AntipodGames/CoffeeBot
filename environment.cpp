#include "environment.h"


Environment::Environment(){

    hitBox.setTexture(*(TM.GetTexture("graphics/level" + QString::number(level).toStdString() + ".png")));

    width = hitBox.getScale().x;
    height = hitBox.getScale().y;
    timer.setInterval(TIMER);

    playerStat.insert("mort",0);
    playerStat.insert("score",0);



}

void Environment::init(){

    std::cout << "Environment Initialisation" << std::endl;

    waitStart = true;
    //Load the level data
    dataLoader.loadLevelData(QString("Data/level")
                             + QString::number(level)
                             + QString(".data"));

    emit sendTotalTime(convertTime(dataLoader.getBestTime()));


    Fly* mouche = new Fly("Fly",7,dataLoader.getInitPos().first,dataLoader.getInitPos().second,15,15,1);

    entityMap.insert(mouche->getID(),mouche);

    flyID = mouche->getID();

    DM.setEM(entityMap);
    emit sendDM(DM);

    emit newLevel(level);

    connect(&timer,SIGNAL(timeout()),this,SLOT(run()));
    timer.start();

}


void Environment::bonusPurge(){
    if(!cacaIdList.isEmpty()){
        for(int i = 0; i < cacaIdList.size(); i++){
            DM.remove(cacaIdList[i],entityMap.value(cacaIdList[i])->get_y());
            entityMap.remove(cacaIdList[i]);
        }
        cacaIdList.clear();
    }
    if(!cacadorIdList.isEmpty()){
        for(int i = 0; i < cacadorIdList.size(); i++){
            DM.remove(cacadorIdList[i],entityMap.value(cacadorIdList[i])->get_y());
            entityMap.remove(cacadorIdList[i]);
        }
        cacadorIdList.clear();
    }
}

void Environment::reloadLevel(){
    getFly()->set_x(dataLoader.getInitPos().first);
    getFly()->set_y(dataLoader.getInitPos().second);
    getFly()->setAngle(0);
    getFly()->Boost(false);
    getFly()->emitSendPos();
    waitStart = true;
    sendTime(convertTime(0));
    emit chgMusic("Fly_menu.mp3");

    //plus bonus & caca
}

void Environment::run(){

    ((Fly*) entityMap.value(flyID))->move();

    bool badAngle = false;

    if(!waitStart){
        int tmpT = chrono.elapsed();

        envTime currentTime = convertTime(tmpT);

        emit sendTime(currentTime);
    }

    if(getFly()->isInSlidingMod()){
        getFly()->Boost(true);
        emit padBlock();
    }

    if(getFly()->get_trigger().intersection(IM.GetImage("graphics/level"
                                                        + QString::number(level).toStdString()
                                                        + ".png"),
                                            sf::Color::Black)){

        isSliding= false;

        if(!getFly()->isInSlidingMod()){
            getFly()->Boost(false);
        }
        if(!badAngle && !isSliding){
            badAngle =  getFly()->slide(IM.GetImage("graphics/level"
                                                    + QString::number(level).toStdString()
                                                    + ".png"));
            isSliding = true;
        }
        if (badAngle)
            emit sigWall();


    }
    if(((Fly*) entityMap.value(flyID))->get_trigger().intersection(IM.GetImage("graphics/level"
                                                                               + QString::number(level).toStdString()
                                                                               + ".png")
                                                                     ,sf::Color::Red)){
        // La Mort !
        reloadLevel();
        playerStat.insert("mort",playerStat.value("mort")+1);
        //        bonusPurge();
        //        bonusLoader(level);
    }
    if(((Fly*) entityMap.value(flyID))->get_trigger().intersection(IM.GetImage("graphics/level"
                                                                               + QString::number(level).toStdString()
                                                                               + ".png")
                                                                   ,sf::Color(0,255,0))){
        if(((Fly*) entityMap.value(flyID))->get_trigger().intersection(IM.GetImage("graphics/level"
                                                                                   + QString::number(level).toStdString()
                                                                                   + ".png")
                                                                       ,sf::Color(0,0,255))
                && !isArrived){
            emit sigWall();
            getFly()->Boost(false);
        }else{
            isArrived = true;
        }
    }
    if(((Fly*) entityMap.value(flyID))->get_trigger().isInSprite(IM.GetImage("graphics/level"
                                                                             + QString::number(level).toStdString()
                                                                             + ".png")
                                                                 ,sf::Color(0,0,255))
            && !waitStart && isArrived){
        // ligne d'arrivee !

        waitStart = true;
        isArrived = false;

        totalTime = chrono.elapsed();
        emit chgMusic("Fly_menu.mp3");

        if(totalTime < dataLoader.getBestTime()){
            dataLoader.saveHighScore(QString("Data/level")
                                     + QString::number(level)
                                     + QString(".data"),timeToString(convertTime(totalTime)));
            emit sendTotalTime(convertTime(totalTime));
            dataLoader.setBestTime(totalTime);
        }
    }
    if(((Fly*) entityMap.value(flyID))->get_trigger().isInSprite(IM.GetImage("graphics/level"
                                                                             + QString::number(level).toStdString()
                                                                             + ".png")
                                                                 ,sf::Color::White)
            && waitStart){
        // départ !
        chrono.start();
        waitStart = false;
        emit chgMusic("Flying_pixels_short.mp3");

    }


    //    bpoint pt;
    //    pt.first = entityMap.value(flyID)->get_x();
    //    pt.second = entityMap.value(flyID)->get_y();

    //    for(int i = 0; i < cacaIdList.size();i++){
    //        if(entityMap.value(cacaIdList[i])->get_trigger().isIN(pt.first,pt.second)){
    //            DM.remove(cacaIdList[i],pt.second);

    //            /*   if(entityMap.value(bonusIdList[i])->get_nom() == "caca")
    //                playerStat.insert("score",playerStat.value("score")+100);
    //            if(entityMap.value(bonusIdList[i])->get_nom() == "cacador")
    //                playerStat.insert("score",playerStat.value("score")+1000);

    //*/
    //            entityMap.remove(cacaIdList[i]);
    //            cacaIdList.remove(i);
    //            cacaIdList.squeeze();

    //        }
    //    }
    //    for(int i = 0; i < cacadorIdList.size();i++){
    //        if(entityMap.value(cacadorIdList[i])->get_trigger().isIN(pt.first,pt.second)){
    //            DM.remove(cacadorIdList[i],pt.second);

    //            /*   if(entityMap.value(bonusIdList[i])->get_nom() == "caca")
    //                playerStat.insert("score",playerStat.value("score")+100);
    //            if(entityMap.value(bonusIdList[i])->get_nom() == "cacador")
    //                playerStat.insert("score",playerStat.value("score")+1000);

    //*/
    //            entityMap.remove(cacadorIdList[i]);
    //            cacadorIdList.remove(i);
    //            cacadorIdList.squeeze();

    //        }
    //    }



    DM.setEM(entityMap);

    emit sendDM(DM);
    emit sendMort(playerStat.value("mort"));
    emit sendScore(playerStat.value("score"));
}

void Environment::pause(){
    if(timer.isActive())
        timer.stop();
    else timer.start();
}

void Environment::makeStop(bool b){
    stop = b;
}

Fly* Environment::getFly(){

    return (Fly*) entityMap.value(flyID);

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
