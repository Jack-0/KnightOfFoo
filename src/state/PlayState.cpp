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

    // add the player
    TheGfxManager::Instance()->addTexture("../res/player.png", "player_sheet");
    TheGfxManager::Instance()->addSprites("player_sheet","player_sprites",25,42,16);
    m_player = new Player(new LoaderParams(sf::Vector2f(0,0),25,42,TheGfxManager::Instance()->getSprites("player_sprites")));
    m_gameObjects.push_back(m_player);





    /*
    std::vector<sf::Sprite> player_up = TheGfxManager::Instance()->getSprites("player_sprites",0,3);
    for(int i = 0; i < player_up.size(); i++)
        player_up[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,100),25,42,player_up,true)));
    std::vector<sf::Sprite> player_down = TheGfxManager::Instance()->getSprites("player_sprites",4,7);
    for(int i = 0; i < player_down.size(); i++)
        player_down[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,300),25,42,player_down,true)));
    std::vector<sf::Sprite> player_left = TheGfxManager::Instance()->getSprites("player_sprites",8,11);
    for(int i = 0; i < player_left.size(); i++)
        player_left[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,500),25,42,player_left,true)));
    std::vector<sf::Sprite> player_right = TheGfxManager::Instance()->getSprites("player_sprites",12,15);
    for(int i = 0; i < player_right.size(); i++)
        player_right[i].setScale(4,4);
    m_gameObjects.push_back(new GameObject(new LoaderParams(sf::Vector2f(150,700),25,42,player_right,true)));
     */
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
