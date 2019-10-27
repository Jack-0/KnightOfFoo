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

    TheGfxManager::Instance()->addTexture("../res/player.png", "player_sheet");
    TheGfxManager::Instance()->addSprites("player_sheet","player_sprites",25,42,16);
    // TODO TEST player up sprites
    std::vector<sf::Sprite> player_up = TheGfxManager::Instance()->getSprites("player_sprites",0,3);
    for(int i = 0; i < player_up.size(); i++)
        player_up[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,100),25,42,player_up,true)));
    // TODO TEST player up sprites
    std::vector<sf::Sprite> player_down = TheGfxManager::Instance()->getSprites("player_sprites",4,7);
    for(int i = 0; i < player_down.size(); i++)
        player_down[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,300),25,42,player_down,true)));
    // TODO TEST player up sprites
    std::vector<sf::Sprite> player_left = TheGfxManager::Instance()->getSprites("player_sprites",8,11);
    for(int i = 0; i < player_left.size(); i++)
        player_left[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,500),25,42,player_left,true)));
    // TODO TEST player up sprites
    std::vector<sf::Sprite> player_right = TheGfxManager::Instance()->getSprites("player_sprites",12,15);
    for(int i = 0; i < player_right.size(); i++)
        player_right[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,700),25,42,player_right,true)));

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
