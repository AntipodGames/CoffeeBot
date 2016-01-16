#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "gleffect.hpp"


class LightSource : public GlEffect
{
public:
    LightSource() :
    GlEffect("LightSource"){}

    bool onLoad();
    void onDraw( sf::RenderTarget &target, sf::RenderStates states) const;
    void onUpdate(float, float x, float y);

private:
    int x,y;
    float range;
    float intensity;
    sf::Shader light;

};

#endif // LIGHTSOURCE_H
