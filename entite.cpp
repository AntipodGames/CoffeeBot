#include "entite.h"


Entite::Entite(){}

Entite::Entite(const Entite & e){

    nom = e.nom;
    x = e.x;
    y = e.y;
    width = e.width;
    height = e.height;
    vitesse = e.vitesse;
    tz = e.tz;
    vie = e.vie;
    angle = e.angle;
    //stateStrings = e.stateStrings;
    currentState = e.currentState;
    ID = e.ID;
    currentFrame = e.currentFrame;
    internalClock.start(e.internalClock.interval());
    speedVector.first = 0;
    speedVector.second = 0;
}


Entite::Entite(std::string name, double v, int px, int py,int w, int h, int vi)
{
    nom = name;
    currentState = RIGHT;
    x = px;
    y = py;

    width = w;
    height = h;

    currentFrame = 1;

    vitesse = v;

    vie = vi;

    angle = 0;
    statID++;
    ID=statID;
    //image = AnimatedSprite(spt1);

    //image.setPosition(x,y);

    tz.set_centre(x,y);
    tz.set_rayon(h);

    speedVector.first = 0;
    speedVector.second = 0;
}



int Entite::get_x(){
    return x;
}

int Entite::get_y(){
    return y;
}

int Entite::getHeight(){
    return height;
}

void Entite::set_x(int px){
    x = px;
    tz.set_centre(x,y);
}
void Entite::set_y(int py){
    y = py;
    tz.set_centre(x,y);
}
void Entite::set_x(double px){
    x = px;
    tz.set_centre(x,y);
}
void Entite::set_y(double py){
    y = py;
    tz.set_centre(x,y);
}

int Entite::move(){
    addX(speedVector.first);
    addY(speedVector.second);
}

QPair<double,double> Entite::getSpeedVector(){
    return speedVector;
}

void Entite::setSpeedVector(QPair<double,double> v){
    speedVector = v;
}

void Entite::setSpeedVector(double vx, double vy){
    speedVector.first = vx;
    speedVector.second = vy;
}

void Entite::setSpeedX(double vx){
    speedVector.first = vx;
}

void Entite::setSpeedY(double vy){
    speedVector.second = vy;
}

bool Entite::addX(int n){
    tz.move(n,0);
        x += n;
        //image.setPosition(x,y);
        return true;


}
bool Entite::addY(int n){
    tz.move(0,n);
        y += n;
       // image.setPosition(x,y);
        return true;




}

bool Entite::addX(double n){
    tz.move(n,0.);
        x = x + n;
       // image.setPosition(x,y);
        return true;



}
bool Entite::addY(double n){
    tz.move(0.,n);
        y = y + n;
       // image.setPosition(x,y);
        return true;


    return false;
}


int Entite::get_vitesse(){
    return vitesse;
}
void Entite::set_vitesse(int v){
    vitesse = v;
}

/*AnimatedSprite &Entite::get_image(){
    return image;
}*/


TzEllipse& Entite::get_trigger(){
    return tz;
}

std::string Entite::get_nom(){
    return nom;
}

void Entite::perdVie(int degats){
    vie-=degats;
    if(vie <= 0)
        vie = 0;
}

int Entite::getVie(){
    return vie;
}

float Entite::getAngle(){
    return angle;
}

int Entite::getFrame(){
    return currentFrame;
}

float Entite::calcAngle(float x1, float y1, float x2, float y2){


    if(x1 - x2 > 0)
        angle = atan((y1 - y2)/(x1 - x2));
    else if(x1 - x2 < 0)
        angle = atan((y1 - y2)/(x1 - x2))+PI;

    return angle;
}


void Entite::set_nom(std::string n){
    nom = n;
}

void Entite::setState(state stt){
    currentState = stt;
}

void Entite::setAngle(float a){
    angle = a;
}

/**
 * Identifiant of the entity
 *@brief Entite::getID
 * @return ID
 */
int Entite::getID(){
    return ID;
}



//std::string Entite::toString(){
  //  return NULL;
//}



void Entite::setOnTheFloor(bool b){
    onTheFloor = b;
}

void Entite::setCollRight(bool b){
    collRight = b;
}

void Entite::setCollLeft(bool b){
    collLeft = b;
}


void Entite::setCollUp(bool b){
    collUp = b;
}


bool Entite::getOnTheFloor(){
    return onTheFloor;
}
