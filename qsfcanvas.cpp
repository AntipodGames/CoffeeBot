#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{

}





void QSFcanvas::keyPressEvent(QKeyEvent * ke){




}

void QSFcanvas::keyReleaseEvent(QKeyEvent * e){

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
//    AM.add("Fly",AnimatedSprite(TM,"graphics/FLYanim",4,7*TAILLE,0,true));
//    AM.add("cacador",AnimatedSprite(TM,"graphics/cacador",1,5*12,0,false));
    //*/


    std::cout << "init!!!!" << std::endl;


}

void QSFcanvas::receiveDM(DisplayManager & dm){
    DM = dm;
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




    clear();

    setView(view);

    carte.afficher(*this,"inf");

    DM.display(AM,*this);






}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
