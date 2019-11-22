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

    Game::Instance()->focusOnPlayer(m_player);

}


void PlayState::render()
{
   m_world->render();

   for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->render();

}


bool PlayState::onEnter()
{
    // create a new world
    m_world = new World();

    // add the player
    TheGfxManager::Instance()->addTexture("../res/player.png", "player_sheet");
    TheGfxManager::Instance()->addSprites("player_sheet","player_sprites",25,46,16);
    int player_start_x = m_world->getCenterTilePos().x + (m_world->TILE_W / 2) - (25 * 2);
    int player_start_y = m_world->getCenterTilePos().y - (46 * 2);
    m_player = new Player(new LoaderParams(sf::Vector2f(player_start_x, player_start_y),25,46,TheGfxManager::Instance()->getSprites("player_sprites")));
    m_gameObjects.push_back(m_player);

    TheGfxManager::Instance()->addTexture("../res/tower.png", "tower_sheet");
    TheGfxManager::Instance()->addSprites("tower_sheet","tower",222,219, 180);
    GameObject* gameObject = new GameObject(
            new LoaderParams(sf::Vector2f(player_start_x,player_start_y),222,219,TheGfxManager::Instance()->getSprites("tower"),true,0,20));
    m_gameObjects.push_back(gameObject);
    GameObject* gameObject2 = new GameObject(
            new LoaderParams(sf::Vector2f(player_start_x+222,player_start_y),222,219,TheGfxManager::Instance()->getSprites("tower"),true,80,200));
    m_gameObjects.push_back(gameObject2);

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
