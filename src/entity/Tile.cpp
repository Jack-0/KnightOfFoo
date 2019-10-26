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
    /*
     *       [A]
     *      /   \
     *   [B]     [D]
     *      \   /
     *       [C]
     *
     *  ... where A == diamond.getPoint(0), B == 1, C == 2 and D == 3
     */

    sf::Vector2f mouse = static_cast<sf::Vector2f>(TheInputHandler::Instance()->getMousePos());
    selected = false;



    if( !isLeft(pos_a, pos_b, mouse))
    {
        if( !isLeft(pos_b, pos_c, mouse))
        {
            if( isLeft(pos_a, pos_d, mouse))
            {
                if( isLeft(pos_d, pos_c, mouse))
                {
                    selected = true;
                }
            }
        }
    }

    // simple test
    /*
    if(pos.x > m_pos.x && (pos.x < m_pos.x + tile_width) ) // inside x
    {
        if( pos.y > m_pos.y && (pos.y < m_pos.y + tile_height) )  // inside y
        {
            selected = true;
        }
    }
     */

}

// a = line point 1, b = line point 2, c = check against
bool Tile::isLeft(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c)
{
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}


void Tile::update()
{
    mouseIntersect();

    if(selected)
        shape.setFillColor(sf::Color::Yellow);
    else
        shape.setFillColor(sf::Color::Blue);

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
