//
// Created by jack on 14/03/19.
//

#include <iostream>

#include "Game.h"

Game* Game::s_pInstance = 0; // singleton


bool Game::init(const char* title, int width, int height)
{
    event = new sf::Event;
    m_screenWidth = width;
    m_screenHeight = height;

    // create window
    m_renderWindow = new sf::RenderWindow(sf::VideoMode(m_screenWidth, m_screenHeight), title);

    /*
    TheGameObjectFactory::Instance()->registerType("MenuButton", new ButtonCreator());
    TheGameObjectFactory::Instance()->registerType("Player", new PlayerCreator());
    TheGameObjectFactory::Instance()->registerType("Enemy", new EnemyCreator());
    TheGameObjectFactory::Instance()->registerType("AnimatedGraphic", new AnimatedGraphicCreator());

    TheSoundManager::Instance()->load("../res/sound/bang.wav", "bang");
    TheSoundManager::Instance()->load("../res/sound/beep.wav", "beep");
     */

    // Game state
    m_pGameStateMachine = new GameStateMachine();
    ///m_pGameStateMachine->changeState(new MainMenuState());
    m_pGameStateMachine->changeState(new PlayState());


    // game is now running
    running = true;
    return true;
}

void Game::render()
{
    //SDL_RenderClear(renderer);
    /// render start
    m_renderWindow->clear();

    m_pGameStateMachine->render();

    m_renderWindow->display();

    /// render end
    //SDL_RenderPresent(renderer);
}

/**
 * returns a random number in the range low - high
 * @param low is the lowest possible int
 * @param high is the highest possible int
 * @return random value between low and high
 */
int Game::getRandom(int low, int high)
{
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> rand(low, high);
    return rand(rng);
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::clean()
{
    m_renderWindow->close();
    quit();
    std::cout << "Cleaning game" << std::endl;

    //SDL_DestroyWindow(window);
    //SDL_DestroyRenderer(renderer);
    //SDL_Quit();
}

void Game::quit()
{
    running = false;
}

void Game::handleEvents()
{
    while (TheGame::Instance()->getRenderWindow()->pollEvent(*event))
        {
            if (event->type == sf::Event::Closed)
            {
                TheGame::Instance()->clean();
            }
        }
    /*
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
     */
}