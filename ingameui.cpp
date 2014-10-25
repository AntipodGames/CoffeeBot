#include "ingameui.h"

InGameUI::InGameUI(){}

InGameUI::InGameUI(QPoint pos, QSize size,QWidget* parent) :QWidget(parent)
{



    mainLayout = new QVBoxLayout();
    menu = new QHBoxLayout();
    statContainer = new QVBoxLayout();
    statContainer2 = new QVBoxLayout();

    pause = new QPushButton("Pause");
    reload = new QPushButton("Retry Level");

    menu->addWidget(pause);
    menu->addWidget(reload);

    //Definition du widget stat


    Mort = new QLabel(QString("Mort : 0"));
    Score = new QLabel(QString("Score : 0"));
    time = new QLabel(QString("Time : 00:00:00"));
    totaltime = new QLabel(QString("Best Time : 00:00:00"));

//    statContainer->addWidget(Score);
    statContainer->addWidget(Mort);
    statContainer->addWidget(time);

    statContainer2->addWidget(totaltime);

    //Ajout du tableau de stat au menu
    menu->addLayout(statContainer);
    menu->addLayout(statContainer2);
    mainLayout->addLayout(menu);
    setLayout(mainLayout);

   // move(pos);
    setMaximumSize(size);


}

void InGameUI::updateMort(int scr){
    QString tmpS("Morts : ");
    tmpS += QString::number(scr);
    Mort->setText(tmpS);
}

void InGameUI::updateScore(int scr){
    QString tmpS("Score : ");
    tmpS += QString::number(scr);
    Score->setText(tmpS);
}

void InGameUI::updateTime(envTime scr){
    QString tmpS("Time : ");
    tmpS += timeToString(scr);
    time->setText(tmpS);
}

void InGameUI::updateTotalTime(envTime scr){
    QString tmpS("Best Time : ");
    tmpS += timeToString(scr);
    totaltime->setText(tmpS);
}
