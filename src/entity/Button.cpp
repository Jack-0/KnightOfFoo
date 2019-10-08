//
// Created by jack on 06/10/19.
//

#include "Button.h"
#include "../Game.h"
#include "../input/InputHandler.h"

Button::Button(const LoaderParams *pParams, int callbackID) : GameObject(pParams)
{
    m_callback_id = callbackID;
}

void Button::update()
{
    GameObject::update();

    int mx = TheInputHandler::Instance()->getMousePos().x;
    int my = TheInputHandler::Instance()->getMousePos().y;

    // if mouse pos intersects button sprite
    if(mx < (m_pos.x + m_width)
       && mx > m_pos.x
       && my < (m_pos.y + m_height)
       && my > m_pos.y )
    {
        std::cout << "mouse inside\n";

        if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Button::Left)) {
            m_frame = MOUSE_CLICK;
            m_callback();
            std::cout << "button clicked\n";
        }
        else
            m_frame = MOUSE_OVER;
    }
    else
        m_frame = MOUSE_OUT;
}

void Button::render()
{
    GameObject::render();
}

void Button::clean()
{
    GameObject::clean();
}

