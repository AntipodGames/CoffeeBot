#ifndef INGAME_H
#define INGAME_H
#include <QWidget>
#include <QtGui>


#include <QMessageBox>
#include <qtimer.h>
#include "qsfcanvas.h"
#include "environment.h"
#include "ingameui.h"
#include "soundmanager.h"
#define TIMER 10

class InGame : public QWidget
{
    Q_OBJECT
public:
    InGame( int width, int height);
    InGame();

    void init();
public slots :
    void pausePopUp();
    void endLvlPopUp(QString);
    void changeMusic(QString);
    void pause();


private:
    QVBoxLayout* container;
    QSFcanvas* SFMLView;
    Environment* env;
    InGameUI* gui;
    QMessageBox* Pause;
    QMessageBox* endLevel;
    QFrame* MainFrame;
    SoundManager* SM;
    QTimer timer;

    int Width;
    int Height;

};

#endif // INGAME_H
