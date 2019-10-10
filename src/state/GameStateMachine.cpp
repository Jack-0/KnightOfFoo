//
// Created by jack on 01/06/19.
//

#include "GameStateMachine.h"

#include <iostream>

void GameStateMachine::pushState(GameState *pState)
{
    m_gameStates.push_back(pState);
    m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->onExit())
        {
            delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }
}

void GameStateMachine::changeState(GameState *pState)
{

    if(!m_gameStates.empty())
    {
        if(m_gameStates.back()->getStateID() == pState->getStateID())
        {
            std::cout << "***Game State == " << pState->getStateID() << "\n";
            return;
        }

        //  TODO Deleting unused game state causes a problem...
        //  TODO The problem maybe that delete removes state from heap but we still have a reference
        //  TODO that is then called and looks to empty memory?
        if(m_gameStates.back()->onExit())
        {
            //delete m_gameStates.back();
            m_gameStates.pop_back();
        }
    }

    m_gameStates.push_back(pState);

    std::cout << "[STATE CHANGED]\n";

    // init it
    m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->update();
    }
}

void GameStateMachine::render()
{
    if(!m_gameStates.empty())
    {
        m_gameStates.back()->render();
    }
}
