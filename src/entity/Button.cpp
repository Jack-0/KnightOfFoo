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
    int mx = TheInputHandler::Instance()->getMousePos().x;
    int my = TheInputHandler::Instance()->getMousePos().y;

    // if mouse pos intersects button sprite
    if(mx < (m_pos.x + m_width)
       && mx > m_pos.x
       && my < (m_pos.y + m_height)
       && my > m_pos.y )
    {
        //std::cout << "mouse inside\n";
        if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::Key::E))
        {
            std::cout << "[MOUSE X=" << mx << " Y=" << my << "]"
                         "[BTN X=" << m_pos.x << " Y=" << m_pos.y <<"]"
                         "[SPRITE X="<< m_sprites[0].getPosition().x << " Y=" << m_sprites[0].getPosition().y << "]"
                         "[VIEW X="<< TheGame::Instance()->getRenderWindow()->getView().getCenter().x << " Y=" << TheGame::Instance()->getRenderWindow()->getView().getCenter().x << "]\n";
        }

        if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Button::Left)) {
            m_frame = MOUSE_CLICK;
            m_callback();
        }
        else
            m_frame = MOUSE_OVER;
    }
    else
        m_frame = MOUSE_OUT;

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

void Button::setCentered(int xOffset, int yOffset)
{
    m_pos.x = TheGame::Instance()->getCenter().x + xOffset;
    m_pos.y = TheGame::Instance()->getCenter().y + yOffset;
}

