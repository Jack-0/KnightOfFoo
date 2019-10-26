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



    //void setSelected(bool b) {selected = b;}
    void mouseIntersect();

private:

    sf::ConvexShape shape;

    sf::Vector2f pos_a;
    sf::Vector2f pos_b;
    sf::Vector2f pos_c;
    sf::Vector2f pos_d;

    bool isLeft(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c);

    bool selected = false;

};


#endif //TEAPOT_TILE_H
