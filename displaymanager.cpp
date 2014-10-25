#include "displaymanager.h"

DisplayManager::DisplayManager(){}

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

void DisplayManager::display(AnimatedManager &AM, sf::RenderWindow &App){

    for(QMap<int,Entite*>::iterator it = EM.begin(); it != EM.end(); it++  ){

        it.value()->get_trigger().draw(App);
        //AM.get(EM.value(tmp[i].second)->get_nom()).setFrame(EM.value(tmp[i].second)->getFrame());

        //affichage de la trainee derriere la mouche
        if(it.key() == 1){//!(((Fly*) EM.value(tmp[i].second))->getPos().isEmpty()) ){
            QPoint tmpPoint;
            // AM.get(EM.value(tmp[i].second)->get_nom()).setAngle(-EM.value(tmp[i].second)->getAngle());
            for(int k = 0; k < ((Fly*) it.value())->getPos().size()-5; k++){
                tmpPoint = ((Fly*) it.value())->getPos()[k];
                AM.get("Circle").resize(k/4+TAILLE,k/4+TAILLE);
                AM.get("Circle").setPosition(tmpPoint.x(),tmpPoint.y());
                AM.get("Circle").affichage(App);

            }
        }

        //Displays of all entity

        AM.get(it.value()->get_nom()).setFrame(it.value()->getFrame());
        AM.get(it.value()->get_nom()).setPosition(it.value()->get_x(),it.value()->get_y());
        AM.get(it.value()->get_nom()).affichage(App);

    }


}

