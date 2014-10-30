#include "animatedsprite.h"
#include "QString"
#include "QTextStream"


/*void AnimatedSprite::dataAnalyser(int width,std::string str){
    QFile QF(QString(str.data()));
    int nbrChar = (width*width+width-1);
    matrix = new int*[width];
    for(int i; i<width; i++)
        matrix[i] = new int[width];
    if(!QF.open(QIODevice::ReadOnly)){
        std::cerr << "Impossible d'ouvrir le fichier " << str << std::endl;
        return;
    }


    QTextStream in(&QF);
    QString data = in.readLine();

    int j = 0;
    int k = 0;

    for(int i; i < nbrChar; i++){

        if(data.toStdString().data()[i] != ' '){
            matrix[k][j] = data.toStdString().data()[i];
            k++;
        }
        else if (data[i] == ' '){
            j++;
            k=0;
        }
    }
}*/

AnimatedSprite::AnimatedSprite(){}

/**
 * Constructeur d'image animé
 * @brief AnimatedSprite::AnimatedSprite
 * @param IM
 * @param adr
 * @param nbrF
 * @param width
 * @param height
 * @param centreX
 * @param centreY
 * @param vit
 */
AnimatedSprite::AnimatedSprite(TextureManager & TM, std::string adr,int nbrFX,int size, int centreX, int centreY,int vit)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");

    image.setTexture(*(TM.GetTexture(imAdr)));

    frameX = 1;
    frameY = 1;
    cpt = 0;
    vitesse  = vit;
    nbrFrameX = nbrFX;
    nbrFrameY = 1;
    scale = size;

    image.setScale(image.getScale().x/size,image.getScale().y/size);
    image.setOrigin(image.getTexture()->getSize().x/(centreX*nbrFrameX),image.getTexture()->getSize().y/(centreY*nbrFrameY));
    image.setTextureRect(sf::IntRect(0,0,image.getTexture()->getSize().x/nbrFrameX,image.getTexture()->getSize().y/nbrFrameY));
   // dataAnalyser(width,dataAdr);

}

AnimatedSprite::AnimatedSprite(TextureManager & TM, std::string adr,int nbrFX,int nbrFY,int size, int centreX, int centreY,int vit)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");

    image.setTexture(*(TM.GetTexture(imAdr)));

    frameX = 1;
    frameY = 1;
    cpt = 0;
    vitesse  = vit;
    nbrFrameX = nbrFX;
    nbrFrameY = nbrFY;

    scale = size;

    image.setScale(image.getScale().x/size,image.getScale().y/size);
    image.setOrigin(image.getTexture()->getSize().x/(centreX*nbrFrameX),image.getTexture()->getSize().y/centreY*nbrFrameY);
    image.setTextureRect(sf::IntRect(0,0,image.getTexture()->getSize().x/nbrFrameX,image.getTexture()->getSize().y/nbrFrameY/nbrFrameX));
   // dataAnalyser(width,dataAdr);

}

AnimatedSprite::AnimatedSprite(TextureManager & TM, std::string adr,int nbrFX,int nbrFY,int size,int vit,bool centrer)
{
    std::string imAdr(adr);
    imAdr.append(".png");
    std::string dataAdr(adr);
    dataAdr.append(".data");

    image.setTexture(*(TM.GetTexture(imAdr)));

    frameX = 1;
    frameY = 1;

    cpt = 0;
    vitesse  = vit;
    nbrFrameX = nbrFX;
    nbrFrameY = nbrFY;

    scale = size;
    image.setTextureRect(sf::IntRect(0,0,image.getTexture()->getSize().x/nbrFrameX,image.getTexture()->getSize().y/nbrFrameY));

    image.setScale((((float)size*nbrFrameX)/((float)image.getTexture()->getSize().x)),
                   (((float)size*nbrFrameY)*(((float)image.getTexture()->getSize().y)/((float)image.getTexture()->getSize().x)))
                   /((float)image.getTexture()->getSize().y));
    if(centrer){
     //   if(nbrFrame == 1)
       //     image.SetCenter(0,image.GetImage()->GetHeight()/2);
       // else
        image.setOrigin(image.getTexture()->getSize().x/(2*(nbrFrameX)),image.getTexture()->getSize().y/(2*nbrFrameY));
    }
   // dataAnalyser(width,dataAdr);

}

/**
 * @brief AnimatedSprite::AnimatedSprite
 * @param as
 */
AnimatedSprite::AnimatedSprite(const AnimatedSprite & as){
    image = as.image;
    nbrFrameX = as.nbrFrameX;
    nbrFrameY = as.nbrFrameY;
    vitesse = as.vitesse;
    cpt = as.cpt;
    frameX = as.frameX;
    frameY = as.frameY;
    scale = as.scale;

}

void AnimatedSprite::affichage(sf::RenderWindow& App){
    App.draw(image);
}

sf::Vector2f AnimatedSprite::TransformToLocal(const sf::Vector2f & Pt){
    return TransformToLocal(Pt);
}

void AnimatedSprite::setFrameX(int i){
    frameX = i%nbrFrameX+1;
    image.setTextureRect(sf::IntRect((image.getTexture()->getSize().x/nbrFrameX)*(frameX-1)
                                     ,(image.getTexture()->getSize().y/nbrFrameY)*(frameY-1)
                                     ,(image.getTexture()->getSize().x/nbrFrameX)
                                     ,image.getTexture()->getSize().y/nbrFrameY));

}

void AnimatedSprite::setFrameY(int i){
    frameY = i%nbrFrameY+1;
    image.setTextureRect(sf::IntRect((image.getTexture()->getSize().x/nbrFrameX)*(frameX-1)
                                     ,(image.getTexture()->getSize().y/nbrFrameY)*(frameY-1)
                                     ,(image.getTexture()->getSize().x/nbrFrameX)
                                     ,image.getTexture()->getSize().y/nbrFrameY));

}

int AnimatedSprite::getFrameX(){
    return frameX;
}
int AnimatedSprite::getFrameY(){
    return frameY;
}

int AnimatedSprite::getNbrFrameX(){
    return nbrFrameX;
}

int AnimatedSprite::getNbrFrameY(){
    return nbrFrameY;
}


void AnimatedSprite::Rotate(float angle){
    image.rotate(angle/PI*180);

}

void AnimatedSprite::setAngle(float angle){
    image.setRotation(angle/PI*180);
}

float AnimatedSprite::getAngle(){
    return image.getRotation()/180*PI;
}

void AnimatedSprite::setPosition(int x, int y){
    image.setPosition(x,y);
}

sf::Sprite& AnimatedSprite::getImage(){
    return image;
}

int AnimatedSprite::getScale(){
    return scale;
}

void AnimatedSprite::resize(int x, int y){
    image.setScale((float)(x*nbrFrameX)/((float)image.getTexture()->getSize().x)
                   ,(float)(y*nbrFrameY)/((float)image.getTexture()->getSize().y));
}
