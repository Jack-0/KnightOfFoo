//
// Created by jack on 03/10/19.
//

#include "GameObject.h"
#include "../graphics/GraphicsManager.h"

GameObject::GameObject(const LoaderParams *pParams)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_sprite_id = pParams->getSpriteID();

    m_pos = pParams->getPos();
    m_vel = sf::Vector2f(0,0);
    m_acc = sf::Vector2f(0,0);
}

void GameObject::update()
{
    m_vel += m_acc;
    m_pos += m_vel;
    TheGfxManager::Instance()->getSprite(m_sprite_id)->setPosition(m_pos);
}

void GameObject::render()
{
    TheGfxManager::Instance()->drawSprite(m_sprite_id);
}

void GameObject::clean()
{

}

