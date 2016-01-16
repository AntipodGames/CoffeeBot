#ifndef GLEFFECT_H
#define GLEFFECT_H
#include "SFML/Graphics.hpp"
#include "animatedsprite.h"
#include <assert.h>     /* assert */

class GlEffect : public sf::Drawable
{
public:

    virtual ~GlEffect()
    {
    }


    void load()
    {
        m_isLoaded = sf::Shader::isAvailable() && onLoad();
    }


    void update(float time, float x, float y)
    {
        if (m_isLoaded)
            onUpdate(time, x, y);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (m_isLoaded)
        {
            onDraw(target, states);
        }

    }
protected :

    GlEffect(const std::string& name) :
        m_name(name),
        m_isLoaded(false)
    {
    }



private :

    // Virtual functions to be implemented in derived effects
    virtual bool onLoad() = 0;
    virtual void onUpdate(float time, float x, float y) = 0;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

private :

    std::string m_name;
    bool m_isLoaded;

};

#endif // GLEFFECT_H
