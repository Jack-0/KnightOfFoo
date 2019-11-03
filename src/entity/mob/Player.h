//
// Created by jack on 27/10/19.
//

#ifndef TEAPOT_PLAYER_H
#define TEAPOT_PLAYER_H


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

    int m_state = 0;
    int m_sprite_sheet_ref = 4;

    int m_anim_stage = 0;

    enum state
    {
        STATIONARY = 0,
        UP = 1,
        DOWN = 2,
        LEFT = 3,
        RIGHT = 4
    };

    void handleInput();
};


#endif //TEAPOT_PLAYER_H
