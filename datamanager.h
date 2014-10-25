#ifndef DATAMANAGER_H
#define DATAMANAGER_H
#include <iostream>
#include <QString>

class DataManager
{
public:
    DataManager(){}

    void loadLevelData(QString fileToLoad);
    std::pair<int,int> getInitPos(){return initPos;}
    int getBestTime(){return bestTime;}
    void setBestTime(int b){bestTime = b;}

    void saveHighScore(QString fileToLoad,QString);

private:
    //Level Data
    std::pair<int,int> initPos;
    int bestTime; //milli second
        //TODO: caca data
};

#endif // DATAMANAGER_H
