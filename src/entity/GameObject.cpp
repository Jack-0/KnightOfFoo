//
// Created by jack on 03/10/19.
//

#include "GameObject.h"
#include "../graphics/GraphicsManager.h"

GameObject::GameObject(const LoaderParams *pParams)
{
    // assign loader parameters
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_sprites = pParams->getSprites();
    m_animated = pParams->getAnimated();
    m_anim_speed = pParams->getAnimationSpeed();
    m_num_frames = pParams->getNumFrames();
    m_frame = pParams->getCurrentFrame() + pParams->getStartFrame();
    m_pos = pParams->getPos();
    m_start_frame = pParams->getStartFrame();
    m_end_frame = pParams->getEndFrame();
    // set default velocity and acceleration to zero
    m_vel = sf::Vector2f(0,0);
    m_acc = sf::Vector2f(0,0);
}

void GameObject::update()
{
    if(m_animated)
    {
        if(m_anim_clock.getElapsedTime().asMilliseconds() > m_anim_speed)
        {
            m_frame++;
            if(m_frame > m_end_frame || m_frame > m_num_frames)
                m_frame = m_start_frame;

            m_anim_clock.restart();
        }
    }

    m_vel += m_acc;
    m_pos += m_vel;
    m_sprites[m_frame].setPosition(m_pos);
}

void GameObject::render()
{
    TheGfxManager::Instance()->drawSprite(m_sprites[m_frame]);
}

void GameObject::clean()
{

}

