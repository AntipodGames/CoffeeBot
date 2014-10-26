#include "qsfcanvas.h"


QSFcanvas::QSFcanvas(const QPoint& Position, const QSize& Size, QWidget* parent) : Qsfml(parent, Position, Size)
{
    carte = Carte(TM,"graphics/hitmap2.png","graphics/hitmap2.png","graphics/hitmap2.png");


}





void QSFcanvas::keyPressEvent(QKeyEvent * ke){

    if(ke->key() == Qt::Key_Z){
        upPressed = true;
    }
    if(ke->key() == Qt::Key_Q){
//        leftPressed = true;
        emit turnLeft(true);
    }
    if(ke->key() == Qt::Key_D){
//        rightPressed = true;
        emit turnRight(true);
    }
    if(ke->key() == Qt::Key_S){
        downPressed = true;
    }

}

void QSFcanvas::keyReleaseEvent(QKeyEvent * e){

    if(e->key() == Qt::Key_Z){
        upPressed = false;

    }
    if(e->key() == Qt::Key_Q){
//        leftPressed = false;
        emit turnLeft(false);

    }
    if(e->key() == Qt::Key_D){
//        rightPressed = false;
        emit turnRight(false);

    }
    if(e->key() == Qt::Key_S){
        downPressed = false;

    }
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
    AM.add("Robot",AnimatedSprite(TM,"graphics/rectrouge",1,3*TAILLE,0,true));
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

    if(x < carte.get_image("inf").getTextureRect().width - view.getSize().x/2
            && x > view.getSize().x/2)
        view.setCenter(x,view.getCenter().y);
    else if(x >= carte.get_image("inf").getTextureRect().width - view.getSize().x/2)
        view.setCenter(carte.get_image("inf").getTextureRect().width - view.getSize().x/2
                       ,view.getCenter().y);
    else if(x <= view.getSize().x/2)
        view.setCenter(view.getSize().x/2,view.getCenter().y);


    if(y < carte.get_image("inf").getTextureRect().height - view.getSize().y/2
                                && y >= view.getSize().y/2)
        view.setCenter(view.getCenter().x,y);
    else if(y >= carte.get_image("inf").getTextureRect().height - view.getSize().y/2)
        view.setCenter(view.getCenter().x
                       ,carte.get_image("inf").getTextureRect().height - view.getSize().y/2);
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

//    if(rightPressed)
//        emit turnRight();
//    if(leftPressed)
//        emit turnLeft();
    if(upPressed)
        emit jump();


    clear();

    setView(view);

    carte.afficher(*this,"inf");

    DM.display(AM,*this);






}

ImageManager& QSFcanvas::getIM(){
    return IM;
}
