#ifndef ENTITE_H
#define ENTITE_H
#include <QTimer>
#include <QTime>
#include "animatedsprite.h"
#include "imagemanager.h"
#include "tzellipse.h"
#include "carte.h"
#include "cmath"
static const std::string stateStrings[] = {"Right","Left","Down","Up","Dead"};
static int statID = 0;
class Entite
{

public:

   /* typedef struct typetourelle{
        forme form;
        int**  physx;
    }typetourelle;
    static QVector<int**> ttours;*/

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

    virtual int get_vitesse();
    virtual std::string get_nom();

   // virtual AnimatedSprite& get_image();
    virtual TzEllipse& get_trigger();

    virtual int getID();

    virtual int getVie();
    virtual float getAngle();

    virtual int getFrame();


    //*/

    //*Setters
    virtual void set_x(int);
    virtual void set_y(int);
    virtual void set_x(double);
    virtual void set_y(double);
    virtual void set_vitesse(int);
    virtual void set_nom(std::string);
    virtual void setState(state);
    virtual void setAngle(float);
    //*/

    //*Methodes
    virtual void perdVie(int degats);

    virtual void chFrame();


    virtual float calcAngle(float x1, float y1, float x2, float y2);

 //   virtual std::string toString()=0;
    //*/

protected:
    //*Attributs
    float x;
    float y;
    int width;
    int height;
    float vitesse; // unit : pixel/ms
    std::string nom;
 //   AnimatedSprite image;
    TzEllipse tz;
    int vie;
    float angle;
    state currentState;
    int currentFrame;
    QTimer internalClock;
    QTime frameClock;
    //*/

    //*Fonctions internes
    virtual bool addX(int);
    virtual bool addY(int);
    virtual bool addX(double);
    virtual bool addY(double);
    //*/

    int ID;

};



#endif // ENTITE_H
