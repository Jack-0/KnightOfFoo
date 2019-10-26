//
// Created by jack on 01/06/19.
//

#ifndef KNIGHT_OF_FOO_GAMESTATEMACHINE_H
#define KNIGHT_OF_FOO_GAMESTATEMACHINE_H

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

    void update();
    void render();

private:
    std::vector<GameState*> m_gameStates;
};


#endif //KNIGHT_OF_FOO_GAMESTATEMACHINE_H
