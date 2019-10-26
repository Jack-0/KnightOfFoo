//
// Created by jack on 13/10/19.
//

#include <iostream>
#include "Tile.h"
#include "../input/InputHandler.h"
#include "../Game.h"
#include "../graphics/GraphicsManager.h"

Tile::Tile(const LoaderParams *pParams) : GameObject(pParams)
{

    int tile_width  = pParams->getWidth();
    int tile_height = pParams->getHeight();
    int x = pParams->getPos().x;
    int y = pParams->getPos().y;
    /*
     *       [A]
     *      /   \
     *   [B]     [D]
     *      \   /
     *       [C]
     */

    pos_a = sf::Vector2f(x + (tile_width / 2), y                    ); // [A]
    pos_b = sf::Vector2f(x                   , y + (tile_height / 2) ); // [B]
    pos_c = sf::Vector2f(x + (tile_width / 2), y + tile_height      ); // [C]
    pos_d = sf::Vector2f(x + tile_width      , y + (tile_height / 2)); // [D]

    shape = sf::ConvexShape();
    shape.setPointCount(4);
    shape.setPoint(0, pos_a);
    shape.setPoint(1, pos_b);
    shape.setPoint(2, pos_c);
    shape.setPoint(3, pos_d);
    shape.setFillColor(sf::Color::Blue);

}

void Tile::mouseIntersect()
{
    // get mouse position and cast to float
    sf::Vector2f mouse = static_cast<sf::Vector2f>(TheInputHandler::Instance()->getAbsMousePos());

    // reset mouse over
    m_bMouseOver = false;

    // check if the mouse intersects the tile
    if(pointIsRight(pos_a, pos_b, mouse))
        if(pointIsRight(pos_b, pos_c, mouse))
            if(pointIsLeft(pos_a, pos_d, mouse))
                if(pointIsLeft(pos_d, pos_c, mouse))
                    m_bMouseOver = true;

}

/**
 * Checks if a point if left of a line
 * @param point1
 * @param point2
 * @param check
 * @return true if point is left of a line
 */
bool Tile::pointIsLeft(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f check)
{
    return ((point2.x - point1.x) * (check.y - point1.y) - (point2.y - point1.y) * (check.x - point1.x)) > 0;
}

/**
 * Check if a point is right of a line
 * @param point1
 * @param point2
 * @param check
 * @return true if point is right of a line
 */
bool Tile::pointIsRight(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f check)
{
    return !pointIsLeft(point1, point2, check);
}


void Tile::update()
{
    mouseIntersect();

    // TODO debugging change tile colour depending on selection
    if(m_bMouseOver)
        shape.setFillColor(sf::Color::Yellow);
    else
        shape.setFillColor(sf::Color::Blue);

    if(m_bTileSelected)
        shape.setFillColor(sf::Color::Red);

    GameObject::update();
}

void Tile::render()
{
    GameObject::render();
    Game::Instance()->getRenderWindow()->draw(shape);
}

void Tile::clean()
{
    GameObject::clean();
}
