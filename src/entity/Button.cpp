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
    int mx = TheInputHandler::Instance()->getAbsMousePos().x;// + Game::Instance()->getAbsCenter().x;
    int my = TheInputHandler::Instance()->getAbsMousePos().y;// + Game::Instance()->getAbsCenter().y;

    // if mouse pos intersects button sprite
    if(mx < (m_pos.x + m_width)
       && mx > m_pos.x
       && my < (m_pos.y + m_height)
       && my > m_pos.y )
    {


        if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Button::Left)) {
            m_frame = MOUSE_CLICK;
            m_callback();
        }
        else
            m_frame = MOUSE_OVER;
    }
    else
        m_frame = MOUSE_OUT;

    //std::cout << "mouse inside\n";

    // TODO debug
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::Key::E))
    {
        std::cout << "[MOUSE X=" << mx << " Y=" << my << "]"
                     "\n\t[LEFT_BTN  X=" << m_pos.x << " Y=" << m_pos.y <<"]"
                     "\n\t[RIGHT_BTN X=" << m_pos.x + m_width << " Y=" << m_pos.y + m_height <<"]\n";
    }

    GameObject::update();
}

void Button::render()
{
    GameObject::render();
}

void Button::clean()
{
    GameObject::clean();
}

/*
void Button::setCentered(int xOffset, int yOffset)
{
    //m_pos.x = Game::Instance()->getCenter().x + xOffset;
    //m_pos.y = Game::Instance()->getCenter().y + yOffset;
}
 */

