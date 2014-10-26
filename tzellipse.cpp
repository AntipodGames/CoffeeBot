#include "tzellipse.h"
#include "cmath"
#include "iostream"
#define PI 3.14159265358979323846

TzEllipse::TzEllipse(){}

TzEllipse::TzEllipse(const TzEllipse & tz){

    centreX = tz.centreX;
    centreY = tz.centreY;
    rayon = tz.rayon;

}

TzEllipse::TzEllipse(float cX,float cY, float Rh){

    centreX = cX;
    centreY = cY;
    rayon = Rh;

}

TzEllipse::TzEllipse(int cX,int cY, int Rh){

    centreX = cX;
    centreY = cY;
    rayon = Rh;
}



float TzEllipse::distance(float x1,float y1,float x2,float y2){

    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

}

int TzEllipse::distance(int x1,int y1,int x2,int y2){

    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

}


bool TzEllipse::isIN(int x, int y){

    if(distance(centreX,centreY,(float)x,(float)y) < get_rayon())
        return true;

    return false;

}

void TzEllipse::move(int x,int y){
    centreX += x;
    centreY += y;
}
void TzEllipse::move(double x,double y){
    centreX = centreX  + x;
    centreY = centreY + y;
}

void TzEllipse::draw(sf::RenderWindow & app){

    sf::CircleShape Circle = sf::CircleShape(rayon);
    Circle.setPosition(centreX,centreY);
    Circle.setOrigin(rayon,rayon);

    Circle.setOutlineColor(sf::Color::Black);
    Circle.setOutlineThickness(1);
    Circle.setFillColor(sf::Color::Transparent);

   // Circle.Scale(*rayonH/(*rayonV),*rayonV/(*rayonH));

    app.draw(Circle);
}

bool* TzEllipse::isColor(sf::Sprite carte, sf::Color color){
//    bool res = false;
    float Cos = 0;
    float Sin = 0;

    bool* tab = new bool[8];
    int j = 0;
    /*
    for(float i = 0; i<=2.0; i = i + 1./6.){
        Cos = *centreX + (*rayonH)*cos(PI*i);
        Sin = *centreY + (*rayonV)*sin(PI*i);
        res = res || (carte.GetPixel((int) Cos ,(int) Sin) == sf::Color::Black);
    }
//*/
    for(float i = 0; i<=2.0; i = i + 1./4.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);

        if(carte.getTexture()->copyToImage().getPixel((int) Cos ,(int) Sin) == color)
            tab[j] = true;
        else tab[j] = false;
        j++;
    }


    return tab;
}

bool TzEllipse::isColor2(sf::Sprite carte,sf::Color color){

    bool* tab = new bool[8];
    bool res = false;

    tab = isColor(carte,color);

    for(int i = 0; i< 8; i++){
        res = res || tab[i];
    }

    return res;

}


bool TzEllipse::intersection(TzEllipse TZ){
    bool res = false;
    float Cos = 0;
    float Sin = 0;

    for(float i = 0; i<=2.0; i = i + 1./32.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);
        res = res || TZ.isIN((int)Cos,(int)Sin);
    }

 /*  for(float i = 0; i<=2.0; i = i + 1./4.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);
        res = res || TZ.isIN((int)Cos,(int)Sin);
    }*/

    return res;
}

bool TzEllipse::intersection(sf::Image * sprt, sf::Color color){
  //  bool res = false;
    float Cos = 0;
    float Sin = 0;
    for(float i = 0; i<=2.0; i = i + 1./32.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);
        if(sprt->getPixel(Cos,Sin) == color){
            currentAngle = i;
            return true;
        }
    }



    return false;
}

bool TzEllipse::isInSprite(sf::Image *sprt, sf::Color color){
      bool res = true;
      float Cos = 0;
      float Sin = 0;
      for(float i = 0; i<=2.0; i = i + 1./32.){
          Cos = centreX + (rayon)*cos(PI*i);
          Sin = centreY + (rayon)*sin(PI*i);
          res = res &&(sprt->getPixel(Cos,Sin) == color);
      }



      return res;
}

float TzEllipse::intersectAngle(sf::Image* sprt, sf::Color color){
    float Cos = 0;
    float Sin = 0;
    QVector<float> itab;
    for(float i = currentAngle-1.; i<=currentAngle+1.; i = i + 1./32.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);
        if(sprt->getPixel(Cos,Sin) == color){
            itab.append(i);

        }

    }

    if(itab.size() == 64.)
        return -100;

    float moy=0;
    for(int i = 0; i < itab.size(); i++){
        moy += itab[i];
    }
    moy = moy/((float)itab.size());
   // std::cout << "nombre de valeurs :" << itab.size() << std::endl;
   // std::cout << "moyenne :" <<  moy << std::endl;
   // std::cout << "angle centrale : " << currentAngle << std::endl << std::endl;
    float result = PI * moy;

    return result;

 /*  for(float i = 0; i<=2.0; i = i + 1./4.){
        Cos = centreX + (rayon)*cos(PI*i);
        Sin = centreY + (rayon)*sin(PI*i);
        res = res || TZ.isIN((int)Cos,(int)Sin);
    }*/

}

TzEllipse TzEllipse::boost(int h){

    TzEllipse TZ(centreX,centreY,rayon+h);

    return TZ;
}

float TzEllipse::get_centreX(){
    return centreX;
}

float TzEllipse::get_centreY(){
    return centreY;
}


float TzEllipse::get_rayon(){
    return rayon;
}

void TzEllipse::set_centre(float x, float y){
    centreX = x;
    centreY = y;
}

void TzEllipse::set_centre(double x, double y){
    centreX = x;
    centreY = y;
}

void TzEllipse::set_centre(int x,int y){
    centreX = x;
    centreY = y;
}

void TzEllipse::set_rayon(float Rh){
    rayon = Rh;
}

