#ifndef ENTITE_H
#define ENTITE_H
#include <QTimer>
#include <QTime>
#include <QPair>
#include "animatedsprite.h"
#include "imagemanager.h"
#include "tzellipse.h"
#include "carte.h"
#include "cmath"
static const std::string stateStrings[] = {"Right","Left","Down","Up","Dead"};
static int statID = 0;
class Entite : public QObject
{

public:

    typedef enum state {
        RIGHT,
        LEFT,
        DOWN,
        UP,
        DEAD
    }state;

    //*Constructeurs
    Entite();
    Entite(const Entite&);
    Entite(std::string name, double v, int px, int py, int w, int h, int vi);
    //*/

    //*Getters
    virtual int get_x();
    virtual int get_y();
    virtual int getHeight();

    virtual int get_vitesse();
    virtual std::string get_nom();

    virtual TzEllipse& get_trigger();

    virtual int getID();

    virtual int getVie();
    virtual float getAngle();

    virtual float getFrame();

    virtual std::string getState();

    //*/

    //*Setters
    virtual void set_x(int);
    virtual void set_y(int);
    virtual void set_x(double);
    virtual void set_y(double);
    virtual void set_vitesse(int);
    virtual void set_nom(std::string);
    virtual void setState(std::string);
    virtual void setAngle(float);
    virtual void setFrame(float);
    //*/

    //*Methodes
    virtual void perdVie(int degats);



    virtual float calcAngle(float x1, float y1, float x2, float y2);

 //   virtual std::string toString()=0;
    //*/

    virtual int move();
    QPair<double,double> getSpeedVector();
    void setSpeedVector(QPair<double,double> v);
    void setSpeedVector(double vx, double vy);
    void setSpeedX(double vx);
    void setSpeedY(double vy);
    void setOnTheFloor(bool b);
    void setCollRight(bool b);
    void setCollLeft(bool b);
    void setCollUp(bool);
    bool getOnTheFloor();

protected:
    //*Attributs
    float x;
    float y;
    int width;
    int height;
    float vitesse; // unit : pixel/ms
    QPair<double,double> speedVector;
    std::string nom;
 //   AnimatedSprite image;
    TzEllipse tz;
    int vie;
    float angle;
    std::string currentState;
    float currentFrame;
    QTimer internalClock;
    //*/

    //*Fonctions internes
    virtual bool addX(int);
    virtual bool addY(int);
    virtual bool addX(double);
    virtual bool addY(double);
    //*/

    int ID;
    bool onTheFloor;
    bool collRight;
    bool collLeft;
    bool collUp;

};



#endif // ENTITE_H
