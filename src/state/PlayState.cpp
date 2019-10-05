//
// Created by jack on 31/05/19.
//

#include "PlayState.h"
#include "../Game.h"
#include "../graphics/GraphicsManager.h"


const std::string PlayState::s_playID = "PLAY";


void PlayState::update()
{
    shape->move(0.01f,0.01f);
}


void PlayState::render()
{
   for(int i = 0; i < m_gameObjects.size(); i++)
   {

   }

    TheGame::Instance()->getRenderWindow()->draw(*shape);
    TheGfxManager::Instance()->drawSprite("tile1");
    TheGfxManager::Instance()->drawSprite("tile2");
    TheGfxManager::Instance()->drawSprite("tile3");
    TheGfxManager::Instance()->drawSprite("tile4");

 //       m_gameObjects[i]->draw();
}


bool PlayState::onEnter()
{

    shape = new sf::CircleShape(100.f);
    shape->setFillColor(sf::Color::Green);


    TheGfxManager::Instance()->addTexture("../res/test.png", "ground_tiles");
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile1", 0, 0 , 256, 128);
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile2", 256, 0 , 256, 128);
    TheGfxManager::Instance()->getSprite("tile2")->setPosition(256, 0);
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile3", 256*2, 0 , 256, 128);
    TheGfxManager::Instance()->getSprite("tile3")->setPosition(128, 64);
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile4", 256*3, 0 , 256, 128);
    TheGfxManager::Instance()->getSprite("tile4")->setPosition(256+128, 64 );


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
