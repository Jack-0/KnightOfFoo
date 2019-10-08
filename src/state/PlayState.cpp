//
// Created by jack on 31/05/19.
//

#include "PlayState.h"
#include "../Game.h"
#include "../graphics/GraphicsManager.h"
#include "../input/InputHandler.h"
#include "../entity/Button.h"

const std::string PlayState::s_playID = "PLAY";


void PlayState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
    text->update();

    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::W))
        std::cout << "W key pressed\n";
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::S))
        std::cout << "S key pressed\n";

    //if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Left))
    //    std::cout << "Mouse x=" << TheInputHandler::Instance()->getMousePos().x << " y=" << TheInputHandler::Instance()->getMousePos().y << "\n";
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
    // TODO this should probably happen in one action... or maybe not
    TheGfxManager::Instance()->addTexture("../res/test.png", "ground_tiles");
    TheGfxManager::Instance()->addSprites("ground_tiles", "tiles", 256, 128, 4);
    TheGfxManager::Instance()->addTexture("../res/buttons.png", "buttons");
    TheGfxManager::Instance()->addSprites("buttons", "btns", 256, 99, 15);

    text = new Text(sf::Vector2f(0,0), "hello world");

    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,0),128,256, TheGfxManager::Instance()->getSprites("tiles"), true)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(500,500),128,256,TheGfxManager::Instance()->getSprites("btns"))));

    /*
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(500,500),128,256,TheGfxManager::Instance()->getSprites("btns", 0, 3), false)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(500,600),128,256,TheGfxManager::Instance()->getSprites("btns", 3, 6), true)));
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(500,700),128,256,TheGfxManager::Instance()->getSprites("btns", 6, 9), true)));
    */

    //m_gameObjects.push_back(new Button(new LoaderParams(sf::Vector2f(0,0),128,256,TheGfxManager::Instance()->getSprites("btns", 0, 3), false)));

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
