#include "displaymanager.h"

DisplayManager::DisplayManager(){
   lightS.load();
}

void DisplayManager::init(TextureManager& TM){
    carte = Carte(TM,"graphics/1srtplan1.png","graphics/2ndPlan.png","graphics/3rdPlan.png");

}

DisplayManager::DisplayManager(const DisplayManager & dm) : sprites(dm.sprites){}

void DisplayManager::add(int x, int y, int ID){
    QPoint coord(x,y);
    sprite newSprite;
    newSprite.first = coord;
    newSprite.second = ID;
    if(sprites.contains(y/TAILLE)){ //si il y a deja des sprites
        QVector<sprite> tmp(sprites.value(y/TAILLE));
        tmp.append(newSprite);
        sprites.insert(y/TAILLE,tmp);
    }
    else{
        QVector<sprite> tmp;
        tmp.append(newSprite);
        sprites.insert(y/TAILLE,tmp);
    }
}

//SLOT-------
void DisplayManager::moveSecondPlan(QPair<double, double> speedV){
    carte.get_image("third").move(speedV.first*0.1,speedV.second*0.2);
}

void DisplayManager::initSecondPlan(){
    carte.get_image("third").setPosition(0,0);
}
//-----------

void DisplayManager::remove(int ID,int y){
    QVector<sprite> tmp(sprites.value(y/TAILLE));

    for(int i = 0; i < tmp.size(); i++){
        int tmpId = tmp[i].second;
        if(tmpId == ID){
            tmp.remove(i);
            tmp.squeeze();
            if(tmp.isEmpty())
                sprites.remove(y/TAILLE);
            else
                sprites.insert(y/TAILLE,tmp);
            return;
        }
    }
}

void DisplayManager::setEM(QMap<int, Entite *> & em){
    EM = em;
}

Carte& DisplayManager::getCarte(){
    return carte;
}

void DisplayManager::display(TextureManager& TM,AnimatedManager &AM, sf::RenderWindow &App){

    carte.afficher(App,"second");

    carte.afficher(App,"third");

    lightS.draw(App,renderstates);



    for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++  ){

        it.value()->get_trigger().draw(App);
        //AM.get(EM.value(tmp[i].second)->get_nom()).setFrame(EM.value(tmp[i].second)->getFrame());


        //Displays of all entity

        if(it.value()->getState().compare("RIGHT") && AM.get(it.value()->get_nom()).getImage().getScale().x > 0)
            AM.get(it.value()->get_nom()).getImage().setScale(-AM.get(it.value()->get_nom()).getImage().getScale().x
                                                              ,AM.get(it.value()->get_nom()).getImage().getScale().y);
        else if(it.value()->getState().compare("LEFT") && AM.get(it.value()->get_nom()).getImage().getScale().x < 0)
            AM.get(it.value()->get_nom()).getImage().setScale(-AM.get(it.value()->get_nom()).getImage().getScale().x
                                                              ,AM.get(it.value()->get_nom()).getImage().getScale().y);

        AM.get(it.value()->get_nom()).setFrameY(it.value()->getFrame());
        if(it.value()->get_nom().compare("Robot") == 0){
            AM.get(it.value()->get_nom()).setFrameX(((Hero*)it.value())->frameY);

        }

//        AM.get(it.value()->get_nom()).setFrameY(it.value()->getFrameY());

        if(it.value()->get_nom().compare("trigger") == 0 || it.value()->get_nom().compare("triggerOn") == 0){
            if(((BinarySwitch*)it.value())->isActivated()){
                it.value()->set_nom("triggerOn");
                carte.set_Map(TM,"graphics/1srtplan2.png");
            }else it.value()->set_nom("trigger");
        }

        AM.get(it.value()->get_nom()).setPosition(it.value()->get_x(),it.value()->get_y());
        AM.get(it.value()->get_nom()).affichage(App);



    }
    carte.afficher(App,"first");


}

