//
// Created by jack on 13/10/19.
//

#include "Tile.h"

Tile::Tile(const LoaderParams *pParams) : GameObject(pParams)
{
}

void Tile::update()
{
    GameObject::update();
}

void Tile::render()
{
    GameObject::render();
}

void Tile::clean()
{
    GameObject::clean();
}
