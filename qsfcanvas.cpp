#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{
}





void QSFcanvas::keyPressEvent(QKeyEvent * ke){

    if(ke->key() == Qt::Key_Space){

        emit jump();
    }
    if(ke->key() == Qt::Key_Q){
        leftPressed = true;
        emit turnLeft(true);
    }
    if(ke->key() == Qt::Key_D){
        rightPressed = true;
        emit turnRight(true);
    }
    if(ke->key() == Qt::Key_Control){
        if(rightPressed && !leftPressed)
            emit dash(true);
        if(leftPressed && !rightPressed)
            emit dash(false);
    }

}

void QSFcanvas::keyReleaseEvent(QKeyEvent * e){

    if(e->key() == Qt::Key_Space){
        spacePressed = false;

    }
    if(e->key() == Qt::Key_Q){
        leftPressed = false;
        emit turnLeft(false);

    }
    if(e->key() == Qt::Key_D){
        rightPressed = false;
        emit turnRight(false);

    }
    if(e->key() == Qt::Key_Control){
        ctrlPressed = false;

    }
    if(e->key() == Qt::Key_E)
        emit switchTrigger();
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
    {/*
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


        }*/

    }



}


void QSFcanvas::initView(int x, int y,int width,int height){
    sf::Vector2f viewCenter(x,y);
    sf::Vector2f viewSize(width,height);
    view = sf::View(viewCenter,viewSize);
}

DisplayManager& QSFcanvas::getDM(){
    return DM;
}

void QSFcanvas::OnInit(){

    setMouseTracking(true);
    DM.init(TM);



    //*Initialisation des images
    AM.add("Robot",AnimatedSprite(TM,"graphics/animavance",5,5,10*TAILLE,0,true));
    AM.add("trigger",AnimatedSprite(TM,"graphics/rectrouge",1,1,10*TAILLE,0,true));
    AM.add("triggerOn",AnimatedSprite(TM,"graphics/rectvert",1,1,10*TAILLE,0,true));
    AM.add("light",AnimatedSprite(TM,"graphics/lumiere",1,1,50*TAILLE,0,true));
//    AM.add("cacador",AnimatedSprite(TM,"graphics/cacador",1,5*12,0,false));
    //*/


    std::cout << "init!!!!" << std::endl;


}

void QSFcanvas::receiveEM(QMap<int,Entite*>& em){
    DM.setEM(em);
}




void QSFcanvas::desableLeft(){

    leftPressed = false;
}

void QSFcanvas::desableRight(){
    rightPressed = false;
}

void QSFcanvas::updateView(int x, int y){

    if(x < DM.getCarte().get_image("first").getTextureRect().width - view.getSize().x/2
            && x > view.getSize().x/2)
        view.setCenter(x,view.getCenter().y);
    else if(x >= DM.getCarte().get_image("first").getTextureRect().width - view.getSize().x/2)
        view.setCenter(DM.getCarte().get_image("first").getTextureRect().width - view.getSize().x/2
                       ,view.getCenter().y);
    else if(x <= view.getSize().x/2)
        view.setCenter(view.getSize().x/2,view.getCenter().y);


    if(y < DM.getCarte().get_image("first").getTextureRect().height - view.getSize().y/2
                                && y >= view.getSize().y/2)
        view.setCenter(view.getCenter().x,y);
    else if(y >= DM.getCarte().get_image("first").getTextureRect().height - view.getSize().y/2)
        view.setCenter(view.getCenter().x
                       ,DM.getCarte().get_image("first").getTextureRect().height - view.getSize().y/2);
    else if(y <= view.getSize().y/2)
        view.setCenter(view.getSize().x,view.getCenter().y/2);
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

    clear();

    setView(view);

    DM.display(TM,AM,*this);
}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
