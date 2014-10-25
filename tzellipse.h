#ifndef TZELLIPSE_H
#define TZELLIPSE_H
#include "SFML/Graphics.hpp"
#include <QVector>
#include <QObject>

class TzEllipse{
private:
    //*Attributs
    float centreX;
    float centreY;
    float rayon;
    float currentAngle;
    //*/

    //*Fonctions internes
    float distance(float,float,float,float);
    int distance(int,int,int,int);
    //*/



public:
    //*Constructeurs
    TzEllipse();
    TzEllipse(const TzEllipse&);
    TzEllipse(float, float, float);
    TzEllipse(int, int, int);
    //*/

    //*Methodes
    bool isIN(int,int);
    void move(int,int);
    void move(double, double);
    void draw (sf::RenderWindow &);
    bool *isColor(sf::Sprite,sf::Color);
    bool isColor2(sf::Sprite,sf::Color);
    bool intersection(TzEllipse);
    bool intersection(sf::Image *,sf::Color);

    bool isInSprite(sf::Image *,sf::Color);

    float intersectAngle(sf::Image *sprt );

    TzEllipse boost(int h);

    //*/

    //*Getters
    float get_centreX();
    float get_centreY();
    float get_rayon();
    //*/

    //*Setters
    void set_centre(float,float);
    void set_centre (int ,int );
    void set_rayon(float);
    //*/
};

#endif // TZELLIPSE_H
