#ifndef INGAMEUI_H
#define INGAMEUI_H
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "environment.h"



class InGameUI : public QWidget
{
    Q_OBJECT

public:
    QVBoxLayout* mainLayout;
    QHBoxLayout* menu;
    QVBoxLayout* statContainer;
    QVBoxLayout* statContainer2;
    QPushButton* pause;
    QPushButton* reload;
    QLabel* Mort;
    QLabel* Score;
    QLabel* time;
    QLabel* totaltime;



    InGameUI();
    InGameUI(QPoint, QSize, QWidget *parent = 0);

public slots:
    void updateMort(int scr);
    void updateScore(int scr);
    void updateTime(envTime scr);
    void updateTotalTime(envTime scr);

};

#endif // INGAMEUI_H
