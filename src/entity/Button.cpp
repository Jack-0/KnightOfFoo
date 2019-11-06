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
        // left click inside button
        if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Button::Left)) {
            m_frame = MOUSE_CLICK;

            // add 100 ms delay, to ensure left click has been released TODO find a more elegant solution
            sf::Clock clock;
            sf::Time c_start = clock.getElapsedTime();
            while(clock.getElapsedTime().asMilliseconds() < c_start.asMilliseconds() + 100 )
            {
            }

            // call the related button press function
            m_callback();
        }
        else{
            // mouse hovering over button
            m_frame = MOUSE_OVER;
        }
    }
    else{
        // mouse not over button
        m_frame = MOUSE_OUT;
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

