//
// Created by jack on 28/07/19.
//

#ifndef KNIGHT_OF_FOO_MENUSTATE_H
#define KNIGHT_OF_FOO_MENUSTATE_H

#include <vector>
#include "GameState.h"

class MenuState : public GameState
{
protected:
    typedef void(*Callback) ();
    virtual void setCallbacks(const std::vector<Callback>& callbacks) = 0;

    std::vector<Callback> m_callbacks;
};


#endif //KNIGHT_OF_FOO_MENUSTATE_H
