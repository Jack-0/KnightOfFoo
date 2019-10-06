//
// Created by jack on 03/10/19.
//

#ifndef TEAPOT_GAMEOBJECT_H
#define TEAPOT_GAMEOBJECT_H

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <SFML/System/Clock.hpp>
#include "../utilities/LoaderParams.h"
#include "Entity.h"

class GameObject : public Entity
{
public:
    GameObject(const LoaderParams *pParams);

    virtual void update() override;
    virtual void render() override;
    virtual void clean()  override;

    void setXVelocity(float x) { m_vel.x = x; }
    void setYVelocity(float y) { m_vel.y = y; }
    void setXAcceleration(float x) { m_acc.x = x; }
    void setYAcceleration(float y) { m_acc.y = y; }

protected:

    // position, velocity and acceleration
    sf::Vector2f m_pos;
    sf::Vector2f m_vel;
    sf::Vector2f m_acc;

    // sprite details
    int m_height;
    int m_width;

    // animation
    bool m_animated;
    int m_frame; // current frame
    int m_num_frames;
    int m_anim_speed;
    int m_start_frame;
    int m_end_frame;
    sf::Clock m_anim_clock; // TODO a clock for each game object? should this be in a singleton?

    // state
    bool m_alive = true;

    // sprites
    std::vector<sf::Sprite> m_sprites;
};


#endif //TEAPOT_GAMEOBJECT_H
