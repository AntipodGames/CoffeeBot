#include "ingame.h"

InGame::InGame()
{
}

InGame::InGame(int width, int height)
{
    MainFrame = new QFrame();
    MainFrame->resize(width, height);
    env = new Environment();
    SFMLView = new QSFcanvas(QPoint(0,0),QSize(width,height),MainFrame);
//    gui = new InGameUI(QPoint(0,height-50),QSize(width,50));

    Width = width;
    Height = height;

    setMinimumSize(width,height);

    Pause = new QMessageBox(this);
    endLevel = new QMessageBox();

//    SM = new SoundManager("Fly_menu.mp3",12800);

    container = new QVBoxLayout(this);

    container->addWidget(MainFrame);
//    container->addWidget(gui);
    container->setMargin(0);

    endLevel->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    Pause->setText("Pause");

    // Préparation du timer
    timer.setInterval(TIMER);
}

void InGame::init(){


    MainFrame->show();
    SFMLView->show();
    SFMLView->initView(1300,800,Width,Height);


    // On paramètre le timer de sorte qu'il génère un rafraîchissement à la fréquence souhaitée
    connect(&timer, SIGNAL(timeout()), SFMLView, SLOT(repaint()));
    connect(&timer,SIGNAL(timeout()),env,SLOT(run()));
    timer.start();



//    SM->playPause();

}

void InGame::changeMusic(QString str){
    SM->playPause();

    SM = new SoundManager(str,12800);
    SM->playPause();

}

void InGame::pausePopUp(){
    if(Pause->isEnabled())
        Pause->close();
    else Pause->exec();
}

void InGame::endLvlPopUp(QString str){
    endLevel->setText(str);
    endLevel->exec();
}

void InGame::pause(){
    if(timer.isActive())
        timer.stop();
    else timer.start();
}
