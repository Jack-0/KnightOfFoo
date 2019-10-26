//
// Created by jack on 31/05/19.
//

#ifndef HELLOSDL_PLAYSTATE_H
#define HELLOSDL_PLAYSTATE_H

#include <iostream>
#include <vector>
#include <random>
#include "GameState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "../entity/Text.h"
#include "../world/World.h"

#include <SFML/Graphics/CircleShape.hpp>

/**
 * This GameState represents the core game.
 * When this state is active;
 *  A player is spawned
 *  Enemies spawn on the left of the screen and float right
 *  The player can shoot down enemy balloons or die via collision
 */
class PlayState : public GameState
{
public:

    virtual void update();
    virtual void render();
    // init and clean
    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {return s_playID;}

private:

    static const std::string s_playID;

    // text that shows debug messages to the screen
    Text* m_debug_text;
    // the world, contains tile map and tile information
    World* m_world;
    // a vector of enemies
    std::vector<GameObject*> m_gameObjects;


};



#endif //HELLOSDL_PLAYSTATE_H
