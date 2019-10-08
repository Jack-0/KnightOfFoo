#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    TheGame::Instance()->init("SFML",900,900);

    while (TheGame::Instance()->isRunning())
    {
        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();
    }

    return 0;
}