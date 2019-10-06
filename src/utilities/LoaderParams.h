//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_LOADERPARAMS_H
#define TEAPOT_LOADERPARAMS_H

#include <string>

class LoaderParams
{
public:
    LoaderParams(sf::Vector2f pos, int height, int width, std::string spriteID)
    :
    m_pos(pos),
    m_height(height),
    m_width(width),
    m_sprite_id(spriteID)
    {
    }

    sf::Vector2f getPos() const  {return m_pos; }
    int getHeight() const { return m_height; }
    int getWidth() const { return m_width; }
    std::string getSpriteID() const{ return m_sprite_id; }

private:
    sf::Vector2f m_pos;

    int m_height;
    int m_width;

    std::string m_sprite_id;
};


#endif //TEAPOT_LOADERPARAMS_H
