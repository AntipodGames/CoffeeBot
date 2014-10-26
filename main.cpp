#include <iostream>
#include <QApplication>
#include "ingame.h"
#define WIDTH 1280
#define HEIGHT 720

using namespace std;

int main(int argc, char** argv)
{
    QApplication* App = new QApplication(argc,argv);

    InGame* IG = new InGame(WIDTH,HEIGHT);

    IG->init();
    IG->show();



    return App->exec();
}

