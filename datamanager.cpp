#include "datamanager.h"
#include <QFile>
#include <QRegExp>

void DataManager::loadLevelData(QString fileToLoad){

    QFile file(fileToLoad);

    if(!file.open(QIODevice::ReadOnly)){
        std::cerr << "fail to open file :" << fileToLoad.toStdString() << std::endl;
        exit(1);
    }

    QString stringFile(file.readAll());

    QRegExp flyRegExp("fly,(\\d+),(\\d+)");

    stringFile.contains(flyRegExp);


    initPos.first = flyRegExp.cap(1).toInt();
    initPos.second = flyRegExp.cap(2).toInt();


    QRegExp bestTimeRegExp("Best time,(\\d+):(\\d+):(\\d+)");

    stringFile.contains(bestTimeRegExp);


    bestTime = bestTimeRegExp.cap(1).toInt()*60000 + bestTimeRegExp.cap(2).toInt()*1000+bestTimeRegExp.cap(3).toInt();


    //TODO : cacaLoader

    file.close();
}

void DataManager::saveHighScore(QString fileToLoad,QString score){

    QFile file(fileToLoad);

    if(!file.open(QIODevice::WriteOnly)){
        std::cerr << "fail to open file :" << fileToLoad.toStdString() << std::endl;
        exit(1);
    }



    QString flypos("fly," +QString::number(initPos.first) + "," + QString::number(initPos.second) + "\n");

    QString string("Best time," + score +"\n");

    file.write(flypos.toAscii());

    file.write(string.toAscii());



    file.close();
}
