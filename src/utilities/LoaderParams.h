//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_LOADERPARAMS_H
#define TEAPOT_LOADERPARAMS_H

#include <string>

class LoaderParams
{
public:
    LoaderParams(sf::Vector2f pos, int height, int width, sf::Sprite sprite)
    :
    m_pos(pos),
    m_height(height),
    m_width(width),
    m_sprite(sprite)
    {
    }

    sf::Vector2f getPos() const  {return m_pos; }
    int getHeight() const { return m_height; }
    int getWidth() const { return m_width; }
    sf::Sprite getSprite() const{ return m_sprite; }

private:
    sf::Vector2f m_pos;

    int m_height;
    int m_width;

    sf::Sprite m_sprite;
};


#endif //TEAPOT_LOADERPARAMS_H
