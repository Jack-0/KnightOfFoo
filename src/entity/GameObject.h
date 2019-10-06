//
// Created by jack on 03/10/19.
//

#ifndef TEAPOT_GAMEOBJECT_H
#define TEAPOT_GAMEOBJECT_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../utilities/LoaderParams.h"
#include "Entity.h"

class GameObject : public Entity
{
public:
    GameObject(const LoaderParams *pParams);

    void update() override;
    void render() override;
    void clean()  override;

    void setXVelocity(float x) { m_vel.x = x; }
    void setYVelocity(float y) { m_vel.y = y; }
    void setXAcceleration(float x) { m_acc.x = x; }
    void setYAcceleration(float y) { m_acc.y = y; }


private:
    // movement
    float m_x;
    float m_y;

    // position, velocity and acceleration
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::Vector2f m_acc;

    // sprite details
    int m_height;
    int m_width;
    //std::string m_sprite_id;
    sf::Sprite m_sprite;
};


#endif //TEAPOT_GAMEOBJECT_H
