#include "lightsource.h"



void LightSource::onDraw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.shader  = &light;
    target.draw(sf::Sprite(),states);
}

bool LightSource::onLoad(){
    if (!light.loadFromFile("test.vect", sf::Shader::Vertex))
        return false;
//    light.setParameter("texture",sf::Shader::CurrentTexture);

}

void LightSource::onUpdate(float time, float x, float y){

}
