//
// Created by jack on 07/10/19.
//

#include "InputHandler.h"
#include "../Game.h"

InputHandler* InputHandler::s_pInstance = 0; // singleton

InputHandler::InputHandler()
{
}

void InputHandler::update()
{
    // poll all events
    while (TheGame::Instance()->getRenderWindow()->pollEvent(*event))
    {
        // if the exit button is pressed exit the game
        if (event->type == sf::Event::Closed)
            TheGame::Instance()->clean();

    }
}

bool InputHandler::isKeyDown(sf::Keyboard::Key key)
{
    if(sf::Keyboard::isKeyPressed(key))
        return true;
    return false;
}

bool InputHandler::isMouseKeyDown(sf::Mouse::Button btn)
{
    if(sf::Mouse::isButtonPressed(btn))
        true;
    false;

}

sf::Vector2i InputHandler::getMousePos()
{
    // get mouse position relative to the render window
    return sf::Mouse::getPosition(*TheGame::Instance()->getRenderWindow());
}

void InputHandler::clean() {}