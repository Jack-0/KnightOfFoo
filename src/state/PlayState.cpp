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
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::Escape))
        Game::Instance()->getStateMachine()->pushState(new PauseState());

    m_world->update();

    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->update();

    // move the map with keys TODO move to PLayer
    int speed = 10;
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::W))
        Game::Instance()->move(0,-1 * speed);
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::S))
        Game::Instance()->move(0,1 * speed);
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::A))
        Game::Instance()->move(-1 * speed,0);
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::D))
        Game::Instance()->move(1 * speed,0);

}


void PlayState::render()
{
   m_world->render();

   for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->render();

}


bool PlayState::onEnter()
{

    // variables to make world only as wide and high as the screen
    int w = Game::Instance()->getRenderWindow()->getSize().x / 256; // 256 is tile width
    int h = (Game::Instance()->getRenderWindow()->getSize().y / 128) * 2; // 128 is tile height (multiplied by 2 due to isometric depth)
    w = 100;
    h = 200;

    // create a new world
    m_world = new World(w, h);

    std::cout << "Entering play state\n";
    return true;
}


bool PlayState::onExit()
{
    // clean all game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->clean();

    // remove all game objects from the vector
    m_gameObjects.clear();

    m_world->clean();

    std::cout << "Exiting play state\n";
    return true;
}
