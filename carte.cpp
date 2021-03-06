#include "carte.h"


//*Constructeurs
Carte::Carte(){

}

Carte::Carte(TextureManager &TM, std::string adr1, std::string adr2, std::string adr3)
{
    firstPlan.setTexture(*(TM.GetTexture(adr1)));
    firstPlan.setPosition(0,0);
    secondPlan.setTexture(*(TM.GetTexture(adr2)));
    secondPlan.setPosition(0,0);

    thirdPlan.setTexture(*(TM.GetTexture(adr3)));
    secondPlan.setPosition(0,0);

}
//*/


//*Methodes
void Carte::afficher(sf::RenderWindow& App,std::string txt){
    if (txt.compare("first") == 0)
        App.draw(firstPlan);
    else if(txt.compare("second") == 0)
        App.draw(secondPlan);
    else if(txt.compare("third") == 0)
        App.draw(thirdPlan);
}
//*/

//*Getters
sf::Sprite& Carte::get_image(std::string txt){
    if (txt.compare("first") == 0)
        return firstPlan;
    else if(txt.compare("second"))
        return secondPlan;
    else if(txt.compare("third"))
        return thirdPlan;
}



//*/


void Carte::set_Map(TextureManager & TM,std::string adr){
    firstPlan.setTexture(*(TM.GetTexture(adr)));
}
