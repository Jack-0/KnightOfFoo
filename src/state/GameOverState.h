//
// Created by jack on 20/07/19.
//

#ifndef HELLOSDL_GAMEOVERSTATE_H
#define HELLOSDL_GAMEOVERSTATE_H

#include <vector>
#include "GameState.h"
#include "MenuState.h"
#include "../entity/GameObject.h"

class GameObject;

class GameOverState : public MenuState
{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {return s_gameOverID;}

private:
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    // functions used with button callbacks
    static void s_gameOverToMain();
    static void s_restartPlay();

    static const std::string s_gameOverID;

    std::vector<GameObject*> m_gameObjects;
};


#endif //HELLOSDL_GAMEOVERSTATE_H
