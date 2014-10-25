#include "carte.h"


//*Constructeurs
Carte::Carte(){

}

Carte::Carte(TextureManager &TM, std::string adr1, std::string adr2, std::string adr3)
{

    //hb = new Hitbox(IM,adr);


    Iinf.setTexture(*(TM.GetTexture(adr1)));

    Isup.setTexture(*(TM.GetTexture(adr2)));
    hitbox.setTexture(*(TM.GetTexture(adr3)));
    hbpath = adr3;

//    Iinf.Resize(w,h);
//    Isup.Resize(w,h);
//    hitbox.Resize(w,h);


}
//*/


//*Methodes
void Carte::afficher(sf::RenderWindow& App,std::string txt){
    if (txt.compare("inf") == 0)
        App.draw(Iinf);
    else
        App.draw(Isup);
}
//*/

//*Getters
sf::Sprite Carte::get_image(std::string txt){
    if(txt.compare("sup") == 0)
        return Isup;
    else
        return Iinf;
}


sf::Image* Carte::get_hitbox(ImageManager &IM){
    return IM.GetImage(hbpath);
}

//*/


void Carte::set_Map(ImageManager & IM,std::string adr){
    sf::Texture text;
    text.loadFromImage(*(IM.GetImage(adr)));
    Iinf.setTexture(text);
}
