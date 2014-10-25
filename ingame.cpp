#include "ingame.h"

InGame::InGame()
{
}

InGame::InGame(int width, int height)
{
    MainFrame = new QFrame();
    MainFrame->resize(width, height-50);
    env = new Environment();
    SFMLView = new QSFcanvas(QPoint(0,0),QSize(width,height-50),MainFrame);
    gui = new InGameUI(QPoint(0,height-50),QSize(width,50));

    Width = width;
    Height = height;

    setMinimumSize(width,height);

    Pause = new QMessageBox(this);
    endLevel = new QMessageBox();

    SM = new SoundManager("Fly_menu.mp3",12800);

    container = new QVBoxLayout(this);

    container->addWidget(MainFrame);
    container->addWidget(gui);
    container->setMargin(0);

    endLevel->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    Pause->setText("Pause");



}

void InGame::init(){

    connect(env,SIGNAL(newLevel(int)),SFMLView,SLOT(switchMap(int)));

    connect(env,SIGNAL(sendMort(int)),gui,SLOT(updateMort(int))); //signal of death
    connect(env,SIGNAL(sendScore(int)),gui,SLOT(updateScore(int))); // update of score
    connect(env,SIGNAL(sendTime(envTime)),gui,SLOT(updateTime(envTime)));
    connect(env,SIGNAL(sendTotalTime(envTime)),gui,SLOT(updateTotalTime(envTime)));


    env->init();



    //gestion de la pause-----------------------------------------------------
    connect(SFMLView,SIGNAL(setPause()),env,SLOT(pause())); //pause
    connect(SFMLView,SIGNAL(setPause()),this,SLOT(pausePopUp())); //window pop up for pause
    connect(Pause,SIGNAL(accepted()),env,SLOT(pause()));
    connect(Pause,SIGNAL(accepted()),SFMLView,SLOT(pause()));
    connect(gui->pause,SIGNAL(pressed()),env,SLOT(pause()));
    connect(gui->pause,SIGNAL(pressed()),SFMLView,SLOT(pause()));
    //----------------------------------------------------------------------

    connect(gui->reload,SIGNAL(pressed()),env,SLOT(reloadLevel()));

    connect(env,SIGNAL(endLvl(QString)),this,SLOT(endLvlPopUp(QString)));//signal of endlvl

    connect(env,SIGNAL(sendDM(DisplayManager&)),SFMLView,SLOT(receiveDM(DisplayManager&)));
//    connect(SFMLView,SIGNAL(turnLeft()),env->getFly(),SLOT(Left()));
//    connect(SFMLView,SIGNAL(turnRight()),env->getFly(),SLOT(Right()));
    connect(SFMLView,SIGNAL(activBoost(bool)),env->getFly(),SLOT(Boost(bool)));
    connect(SFMLView,SIGNAL(activSlide(bool)),env->getFly(),SLOT(SlideMod(bool)));
//    connect(env->getFly(),SIGNAL(noLeft()),SFMLView,SLOT(desableLeft()));
//    connect(env->getFly(),SIGNAL(noRight()),SFMLView,SLOT(desableRight()));
    connect(env->getFly(),SIGNAL(sendPos(int,int)),SFMLView,SLOT(updateView(int,int)));
    connect(SFMLView,SIGNAL(sendPadPos(float,float)),env->getFly(),SLOT(posUpdate(float,float)));
    connect(SFMLView,SIGNAL(takeContr(bool)),env->getFly(),SLOT(takeControl(bool)));
    connect(env,SIGNAL(padBlock()),SFMLView,SLOT(blockPad()));
    connect(env,SIGNAL(sigWall()),env->getFly(),SLOT(wall()));
    connect(SFMLView,SIGNAL(retry()),env,SLOT(reloadLevel()));

    connect(env,SIGNAL(chgMusic(QString)),this,SLOT(changeMusic(QString)));


    MainFrame->show();
    SFMLView->show();
    SFMLView->initView(env->getFly()->get_x(),env->getFly()->get_y(),Width,Height);



    SM->playPause();

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
