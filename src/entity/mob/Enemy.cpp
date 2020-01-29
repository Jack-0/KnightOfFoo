//
// Created by jack on 24/12/2019.
//

#include "Enemy.h"

Enemy::Enemy(const LoaderParams *pParams) : GameObject(pParams)
{
    // increase sprite size
    int scalar = 4;
    for(int i = 0; i < m_sprites.size(); i++){
        m_sprites[i].scale(scalar, scalar);
        m_sprites[i].setColor(sf::Color::Red);
    }
}

void Enemy::render(){
    GameObject::render();
}

void Enemy::update() {
    GameObject::update();
}

void Enemy::clean() {
    GameObject::clean();
}