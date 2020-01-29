//
// Created by jack on 27/10/19.
//

#ifndef KNIGHT_OF_FOO_PLAYER_H
#define KNIGHT_OF_FOO_PLAYER_H


#include <SFML/Window.hpp>
#include "../GameObject.h"

class Player : public GameObject
{
public:

    Player(const LoaderParams* pParams);

    virtual void update();
    virtual void render();
    virtual void clean();

    // return the center of the players sprite
    sf::Vector2f playerSpriteCenter() { return sf::Vector2f(m_pos.x + m_width / 2, m_pos.y + m_height / 2); }

private:

    int m_sprite_sheet_ref = 4;

    int m_anim_stage = 0;

    int m_state = 0;

    enum state
    {
        STATIONARY = 0,
        NORTH = 1,
        NORTH_EAST = 2,
        EAST = 3,
        SOUTH_EAST = 4,
        SOUTH = 5,
        SOUTH_WEST = 6,
        WEST = 7,
        NORTH_WEST = 8
    };

    static const int SPEED = 6;
    int m_speed = SPEED;
    void handleInput();
    void handleState();
    bool isDown(sf::Keyboard::Key);
};


#endif //KNIGHT_OF_FOO_PLAYER_H
