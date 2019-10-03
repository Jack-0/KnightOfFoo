//
// Created by jack on 03/10/19.
//

#ifndef TEAPOT_ENTITY_H
#define TEAPOT_ENTITY_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

class GameObject
{
public:
    GameObject(const sf::Texture& texture);

    void update();
    void render();

private:
    int m_x;
    int m_y;

    sf::Sprite m_sprite;
};


#endif //TEAPOT_ENTITY_H
