//
// Created by jack on 31/05/19.
//

#ifndef KNIGHT_OF_FOO_MAINMENUSTATE_H
#define KNIGHT_OF_FOO_MAINMENUSTATE_H

#include <vector>
#include "GameState.h"
#include "MenuState.h"
#include "../entity/GameObject.h"
#include "../entity/Button.h"

class MainMenuState : public MenuState
{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const {return s_menuID;}

private:
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    // functions used with button callbacks
    static void s_menuToPlay();
    static void s_exitFromMenu();

    // button variables
    int m_btn_w = 256;
    int m_btn_h = 99;
    // buttons
    Button* m_play_btn;
    Button* m_exit_btn;

    static const std::string s_menuID;
    std::vector<GameObject*> m_gameObjects;

};


#endif //KNIGHT_OF_FOO_MAINMENUSTATE_H
