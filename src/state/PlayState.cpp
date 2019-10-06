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
    text->update();
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
    TheGfxManager::Instance()->addTexture("../res/buttons.png", "buttons");
    std::cout << "a\n";
    TheGfxManager::Instance()->addSprites("ground_tiles", "tiles", 256, 128, 4);
    TheGfxManager::Instance()->addSprites("buttons", "btns", 256, 99, 15);
    std::cout << "b\n";


    /*
    sf::Sprite copyiedSprite = TheGfxManager::Instance()->getSprite("tiles", 1);

    sf::Sprite btnsThing1 = TheGfxManager::Instance()->getSprite("bs", 0);
    sf::Sprite btnsThing2 = TheGfxManager::Instance()->getSprite("bs", 1);
    sf::Sprite btnsThing3 = TheGfxManager::Instance()->getSprite("bs", 2);
    sf::Sprite btnsThing4 = TheGfxManager::Instance()->getSprite("bs", 3);
    sf::Sprite btnsThing5 = TheGfxManager::Instance()->getSprite("bs", 4);
    sf::Sprite btnsThing6 = TheGfxManager::Instance()->getSprite("bs", 5);
     */

    std::cout << "c\n";

    text = new Text(sf::Vector2f(0,0), "hello world");

    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,0),128,256, TheGfxManager::Instance()->getSprites("tiles"),0,3)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(500,500),128,256,TheGfxManager::Instance()->getSprites("btns"),0,14, true, 14-2, 14)));

    /*
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*0),128,256,btnsThing1)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*1),128,256,btnsThing2)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*2),128,256,btnsThing3)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*3),128,256,btnsThing4)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*4),128,256,btnsThing5)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,100*5),128,256,btnsThing6)));
    */
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

    text->clean();
    delete(text);

    // TODO

    std::cout << "Exiting play state\n";
    return true;
}
