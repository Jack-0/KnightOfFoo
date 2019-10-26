//
// Created by jack on 13/10/19.
//

#ifndef TEAPOT_TILE_H
#define TEAPOT_TILE_H


#include <SFML/Graphics/ConvexShape.hpp>
#include "GameObject.h"

class Tile : public GameObject
{
public:
    Tile(const LoaderParams* pParams);

    virtual void update();
    virtual void render();
    virtual void clean();

private:

    // variables for checking intersection
    sf::Vector2f pos_a;
    sf::Vector2f pos_b;
    sf::Vector2f pos_c;
    sf::Vector2f pos_d;
    // used for debugging
    sf::ConvexShape shape;

    // check for mouse intersection on tile
    void mouseIntersect();
    // static methods to check if a point is on the left or right side of a line used for intersection checks
    static bool pointIsLeft(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f check);
    static bool pointIsRight(sf::Vector2f point1, sf::Vector2f point2, sf::Vector2f check);

    // booleans for tile selection
    bool m_bMouseOver = false;
    bool m_bTileSelected = false;
};


#endif //TEAPOT_TILE_H
