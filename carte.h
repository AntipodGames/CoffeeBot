#ifndef CARTE_H
#define CARTE_H
#include <SFML/Graphics.hpp>
#include <QVector>
#include "texturemanager.h"
#include "imagemanager.h"


class Carte
{
protected:
   //*Attributs
   sf::Sprite Isup;
   sf::Sprite Iinf;
   sf::Sprite hitbox;
   std::string hbpath;
   //*/




public:

    //*Constructeurs
    Carte();
    Carte(TextureManager &, std::string, std::string, std::string);
    //*/

    //*Methodes
    void afficher(sf::RenderWindow &, std::string);
    //*/

    //*Getters
    sf::Sprite get_image(std::string);
    sf::Image *get_hitbox(ImageManager&);
    //*/

    //*Setters
    void set_Map(ImageManager&, std::string adr);
    //*/
};

#endif // CARTE_H
