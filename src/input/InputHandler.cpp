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
    while (Game::Instance()->getRenderWindow()->pollEvent(*event))
    {
        // if the exit button is pressed exit the game
        if (event->type == sf::Event::Closed)
            Game::Instance()->clean();

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

sf::Vector2i InputHandler::getAbsMousePos()
{
    return sf::Vector2i(sf::Mouse::getPosition(*Game::Instance()->getRenderWindow())) + Game::Instance()->getAbsCenter();
}

void InputHandler::clean() {}