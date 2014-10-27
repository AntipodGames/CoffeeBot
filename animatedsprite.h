#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include <QVector>
#include <SFML/Graphics.hpp>
#include "texturemanager.h"
#include <QFile>
//#include <QFileOpenEvent>
#include <stack>
#define PI 3.14159265359

class AnimatedSprite
{
public:
    AnimatedSprite();
    AnimatedSprite(TextureManager &TM, std::string adr, int nbrFX, int size, int centreX, int centreY, int vit);
    AnimatedSprite(TextureManager &TM, std::string adr, int nbrFX, int nbrFY, int size, int centreX, int centreY, int vit);

//    AnimatedSprite(TextureManager& TM, std::string adr, int nbrF, int size, int vit,bool);
    AnimatedSprite(const AnimatedSprite&);

    void affichage(sf::RenderWindow&);
    void setFrameX(int);
    void setFrameY(int);

    int getFrameX();
    int getFrameY();
    void setPosition(int,int);
    sf::Sprite& getImage();
    void setAngle(float);
    float getAngle();
    void Rotate(float angle);
    int getScale();
    int getNbrFrameX();
    int getNbrFrameY();
    void resize(int x, int y);


    static sf::Vector2f TransformToLocal(const sf::Vector2f &);


private:
    sf::Sprite image;
    int nbrFrameX;
    int nbrFrameY;
    int frameX;
    int frameY;
    int cpt;
    int vitesse;
    int** matrix;
    int scale;

    void dataAnalyser(int width, std::string str);

};

#endif // ANIMATEDSPRITE_H
