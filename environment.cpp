#include "environment.h"


Environment::Environment(){
    width = hitBox.getScale().x;
    height = hitBox.getScale().y;
    playerStat.insert("mort",0);
    playerStat.insert("score",0);
}

void Environment::init(){
    std::cout << "Environment Initialisation" << std::endl;
}


void Environment::bonusPurge(){

}

void Environment::reloadLevel(){

}

void Environment::run(){



    DM.setEM(entityMap);

    emit sendDM(DM);
    emit sendMort(playerStat.value("mort"));
    emit sendScore(playerStat.value("score"));
    for(QMap<int,Entite*>::iterator it = entityMap.begin(); it != entityMap.end(); it++){
        sf::Image* tmpImg = new sf::Image(hitBox.getTexture()->copyToImage());
        if(it.value()->get_trigger().intersection(tmpImg,sf::Color::Black)){
            if(it.value()->get_trigger().intersectAngle(tmpImg, sf::Color::Black) <= PI / 5.0
                    && it.value()->get_trigger().intersectAngle(tmpImg, sf::Color::Black) >= - PI / 5.0){

            }
        }
        delete tmpImg;
    }
}

void Environment::makeStop(bool b){
    stop = b;
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
