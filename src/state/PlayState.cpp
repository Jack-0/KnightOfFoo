//
// Created by jack on 31/05/19.
//

#include "PlayState.h"
#include "../Game.h"


const std::string PlayState::s_playID = "PLAY";


void PlayState::update()
{
    shape->move(0.001,0.001);
}


void PlayState::render()
{
   for(int i = 0; i < m_gameObjects.size(); i++)
   {

   }


   shape->setFillColor(sf::Color::Green);
   TheGame::Instance()->getRenderer()->draw(*shape);

 //       m_gameObjects[i]->draw();
}


bool PlayState::onEnter()
{

    shape = new sf::CircleShape(100.f);

    std::cout << "Entering play state\n";
    return true;
}


bool PlayState::onExit()
{
    // clean all game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {

    }
        //m_gameObjects[i]->clean();

    // remove all game objects from the vector
    m_gameObjects.clear();

    std::cout << "Exiting play state\n";
    return true;
}
