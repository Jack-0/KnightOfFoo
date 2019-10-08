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
    {
        std::cout << "W key pressed\n";
        TheGame::Instance()->zoom(-.001f);
    }
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::S))
    {
        std::cout << "S key pressed\n";
        TheGame::Instance()->zoom(.001f);
    }

    TheGame::Instance()->move(0.001f, 0.001f);
    //if(TheInputHandler::Instance()->isMouseKeyDown(sf::Mouse::Left))
    //    std::cout << "Mouse x=" << TheInputHandler::Instance()->getMousePos().x << " y=" << TheInputHandler::Instance()->getMousePos().y << "\n";
}


void PlayState::render()
{
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


    text = new Text(sf::Vector2f(0,0), "Hello SFML World!"); // maybe text should be a GameObject
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(0,0),128,256, TheGfxManager::Instance()->getSprites("tiles"), true)));

    // add some tiles
    for(int i = 0; i < 10; i ++)
        for(int j = 0; j < 10; j++)
            m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(i*128,j*128),128,256, TheGfxManager::Instance()->getSprites("tiles"), true, TheGame::Instance()->getRandom(0,3))));
    // test ^^^

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
