#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    ///sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    //sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");

    TheGame::Instance()->init("SFML",900,900);


    sf::Event event;

    while (TheGame::Instance()->isRunning())
    //    while (window.isOpen())
    {
        while (TheGame::Instance()->getRenderWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                TheGame::Instance()->clean();
            }
        }

        TheGame::Instance()->handleEvents();
        TheGame::Instance()->update();
        TheGame::Instance()->render();



        // TODO delay time

        /*
        sf::Event event;

        window.clear();
        window.draw(shape);
        window.display();
         */
    }

    return 0;
}