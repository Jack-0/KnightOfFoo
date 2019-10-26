#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Game::Instance()->init("SFML", 1200, 900);

    while (Game::Instance()->isRunning())
    {
        Game::Instance()->handleEvents();
        Game::Instance()->update();
        Game::Instance()->render();
    }

    return 0;
}