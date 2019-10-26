//
// Created by jack on 05/06/19.
//

#ifndef KNIGHT_OF_FOO_PAUSESTATE_H
#define KNIGHT_OF_FOO_PAUSESTATE_H

#include <vector>
#include "GameState.h"
#include "MenuState.h"
#include "../entity/GameObject.h"
#include "../entity/Button.h"

class PauseState : public MenuState
{
public:
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_pauseID; }

private:
    virtual void setCallbacks(const std::vector<Callback>& callbacks);

    // button variables
    int m_btn_w = 256;
    int m_btn_h = 99;
    // buttons
    Button* m_menu_btn;
    Button* m_resume_btn;
    // functions used with button callbacks

    static void s_pauseToMain();
    static void s_resumePlay();

    static const std::string s_pauseID;

    std::vector<GameObject*> m_gameObjects;
};


#endif //KNIGHT_OF_FOO_PAUSESTATE_H
