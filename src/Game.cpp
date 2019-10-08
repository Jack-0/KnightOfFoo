//
// Created by jack on 14/03/19.
//

#include <iostream>

#include "Game.h"
#include "input/InputHandler.h"

Game* Game::s_pInstance = 0; // singleton


bool Game::init(const char* title, int width, int height)
{
    m_screenWidth = width;
    m_screenHeight = height;

    // create window

    m_renderWindow = new sf::RenderWindow(sf::VideoMode(m_screenWidth, m_screenHeight), title);
    m_view = m_renderWindow->getDefaultView();
    m_view.setSize(width, height);
    m_renderWindow->setView(m_view);

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
    m_pGameStateMachine->changeState(new MainMenuState());

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
    //m_view.move(0,0.1);
    m_renderWindow->setView(m_view);
    m_pGameStateMachine->update();
}

void Game::clean()
{
    m_renderWindow->close();
    quit();
    std::cout << "Cleaning game" << std::endl;
}

void Game::quit()
{
    running = false;
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();
    /*
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
     */
}

void Game::zoom(float x)
{
    // TODO zoom is a mess as it is called multiple times per frame if a key is pressed the issue is state and keypress
    //m_view.setRotation(x);
    std::cout << "\ttransform before zoom" << m_view.getRotation() << "\n";
    //m_view.setCenter(m_renderWindow->getSize().x / 2, m_renderWindow->getSize().y / 2);


    if(x > 1)
        m_zoom_value += .00001f;
    else
        m_zoom_value -= .00001f;

    if(m_zoom_value >= 1.00005)
        return;

    if(m_zoom_value <=  .90005)
        return;

    //TODO zoom is a mess

    m_view.zoom(m_zoom_value);
    std::cout << "\ttransform after zoom" << m_view.getRotation() << "\n\n\n\n";
}

void Game::move(float x, float y)
{
    m_view.move(x,y);
}