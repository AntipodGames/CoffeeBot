#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{

}





void QSFcanvas::keyPressEvent(QKeyEvent * ke){


    if(ke->key() == Qt::Key_Z || ke->key() == Qt::Key_Up){
        axisYPos = -1;
    }
    if(ke->key() == Qt::Key_S || ke->key() == Qt::Key_Down){
        axisYPos = 1;
    }
    if(ke->key() == Qt::Key_Q || ke->key() == Qt::Key_Left){
        axisXPos = -1;
    }
    if(ke->key() == Qt::Key_D || ke->key() == Qt::Key_Right){
        axisXPos = 1;
    }
    if(ke->key() == Qt::Key_Shift){
        emit activSlide(true);
    }


    if(!padBlocked)
        emit sendPadPos(axisXPos,axisYPos);


}

void QSFcanvas::keyReleaseEvent(QKeyEvent * e){
    if(e->key() == Qt::Key_Z || e->key() == Qt::Key_Up){
        axisYPos = 0;
    }
    if(e->key() == Qt::Key_S || e->key() == Qt::Key_Down){
        axisYPos = 0;
    }
    if(e->key() == Qt::Key_Q || e->key() == Qt::Key_Left){
        axisXPos = 0;
    }
    if(e->key() == Qt::Key_D || e->key() == Qt::Key_Right){
        axisXPos = 0;
    }
    if(e->key() == Qt::Key_Space){
        pause();
        emit setPause();
    }
    if(e->key() == Qt::Key_Shift){
        emit activSlide(false);
        padBlocked = false;

    }
    if(e->key() == Qt::Key_Enter){
        emit retry();
    }

    if(!padBlocked)
        emit sendPadPos(axisXPos,axisYPos);
}

void QSFcanvas::gamePadEvent(){

    /*
     * Triangle == 0
     * L1 == 4
     * L2 == 6
     * R1 == 5
     * R2 == 7
     */

//    axisXPos = sf::Joystick::getAxisPosition(0,sf::Joystick::X);
//    axisYPos = sf::Joystick::getAxisPosition(0,sf::Joystick::Y);


    sf::Event Event;
    if (this->pollEvent(Event))
    {
        if((Event.type == sf::Event::JoystickMoved) && ((Event.joystickMove.axis == sf::Joystick::X))){
            axisXPos = Event.joystickMove.position/100;
           // std::cout << axisXPos << std::endl;
        }
        if((Event.type == sf::Event::JoystickMoved) && ((Event.joystickMove.axis == sf::Joystick::Y))){
            axisYPos = Event.joystickMove.position/100;

            //std::cout << axisYPos << std::endl;
        }
        if((Event.type == sf::Event::JoystickButtonPressed)){
            if(Event.joystickButton.button == 5){ //R1
                emit activSlide(true);
            }

//            if(Event.JoyButton.Button == 4) //L1
//                emit activBoost(true);


        }
        if((Event.type == sf::Event::JoystickButtonReleased)){
            if(Event.joystickButton.button == 5){ //R1
                emit activSlide(false);
                padBlocked = false;
            }
            if(Event.joystickButton.button == 4) //L1
                emit retry();


        }
        if(!padBlocked)
            emit sendPadPos(axisXPos,axisYPos);
    }



}


void QSFcanvas::initView(int x, int y,int width,int height){
    sf::Vector2f viewCenter(x,y);
    sf::Vector2f viewSize(width,height);
    view = sf::View(viewCenter,viewSize);
}

void QSFcanvas::OnInit(){

    setMouseTracking(true);



    //*Initialisation des images
    AM.add("Fly",AnimatedSprite(TM,"graphics/FLYanim",4,7*TAILLE,0,true));
    AM.add("Circle",AnimatedSprite(TM,"graphics/blackcircle",1,TAILLE,0,true));
    AM.add("caca",AnimatedSprite(TM,"graphics/CACA",1,5*10,0,false));
    AM.add("cacador",AnimatedSprite(TM,"graphics/cacador",1,5*12,0,false));
    //*/


    std::cout << "init!!!!" << std::endl;


}

void QSFcanvas::receiveDM(DisplayManager & dm){
    DM = dm;
}



void QSFcanvas::pause(){
    if(myTimer.isActive())
        myTimer.stop();
    else myTimer.start();
}

void QSFcanvas::desableLeft(){

    leftPressed = false;
}

void QSFcanvas::desableRight(){
    rightPressed = false;
}

void QSFcanvas::updateView(int x, int y){
    view.setCenter(x,y);
}

void QSFcanvas::blockPad(){
    padBlocked = true;
}

void QSFcanvas::switchMap(int lvl){
    QString tmp("graphics/level");
    tmp += QString::number(lvl);
    tmp += ".png";
    carte = Carte(TM,tmp.toStdString(),tmp.toStdString(),tmp.toStdString());

}

void QSFcanvas::OnUpdate()
{


    gamePadEvent();

    if(leftPressed)
        emit turnLeft();
    if(rightPressed)
        emit turnRight();


    clear();

    setView(view);

    carte.afficher(*this,"inf");

    DM.display(AM,*this);






}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
