//
// Created by jack on 31/05/19.
//

#include "PlayState.h"
#include "../Game.h"
#include "../graphics/GraphicsManager.h"


const std::string PlayState::s_playID = "PLAY";


void PlayState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}


void PlayState::render()
{
   m_gameObjects[0]->setXVelocity(0.01f);

   for(int i = 0; i < m_gameObjects.size(); i++)
   {
        m_gameObjects[i]->render();
   }
   text->render();
}


bool PlayState::onEnter()
{
    TheGfxManager::Instance()->addTexture("../res/test.png", "ground_tiles");
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile1", 0, 0 , 256, 128);
    TheGfxManager::Instance()->addSprite("ground_tiles", "tile2", 256*3, 0 , 256, 128);
    sf::Sprite copyiedSprite = TheGfxManager::Instance()->getSprite("tile1");
    sf::Sprite copyiedSprite2 = TheGfxManager::Instance()->getSprite("tile2");

    text = new Text(sf::Vector2f(0,0), "hello world");

    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,0),128,256, copyiedSprite)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(64,0),128,256,copyiedSprite)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(64,128),128,256,copyiedSprite2)));

    std::cout << "Entering play state\n";
    return true;
}


bool PlayState::onExit()
{
    // clean all game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    // remove all game objects from the vector
    m_gameObjects.clear();

    // TODO

    std::cout << "Exiting play state\n";
    return true;
}
