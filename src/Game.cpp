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
    // center window on monitor
    auto desktop = sf::VideoMode::getDesktopMode();
    m_renderWindow->setPosition(sf::Vector2i(desktop.width/2 - m_renderWindow->getSize().x/2, desktop.height/2 - m_renderWindow->getSize().y/2));
    // configure view
    m_view = m_renderWindow->getDefaultView();
    m_view.setSize(width, height);
    m_view_absolute_center = sf::Vector2f(0,0);
    m_renderWindow->setView(m_view);
    m_renderWindow->setFramerateLimit(60); // TODO switch out for better game loop (fixed time-step)

    // Game state
    m_pGameStateMachine = new GameStateMachine();
    ///m_pGameStateMachine->changeState(new MainMenuState());
    m_pGameStateMachine->changeState(new MainMenuState());

    // create text that will show debug messages
    m_debug_text = new Text(sf::Vector2f(0, 0), "Debug:"); // maybe text should be a GameObject
    // game is now running
    running = true;
    return true;
}

void Game::render()
{
    m_renderWindow->clear();         // clear screen
    m_pGameStateMachine->render();   // draw pixels
    m_debug_text->render();          // TODO debug text
    m_renderWindow->display();       // show pixels
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
    updateCamera();

    // update debug message
    m_debug_text->setTopLeftAndScale();
    m_debug_text->update();

    // update game states and set active window
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
}

void Game::move(float x, float y)
{
    m_view_absolute_center.x += x;
    m_view_absolute_center.y += y;
    m_view.move(x, y);
}

void Game::updateCamera()
{
    // set zoom_last
    zoom_last = zoom_current;
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::Key::Up)){
        zoom_current--;
        zoom(0.5f); // half to zoom in
    }
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::Key::Down)){
        zoom_current++;
        zoom(2.0f); // double to zoom out
    }
}

void Game::zoom(float amount)
{
    // if zoom is invalid zoom will revert to last zoom value, and we return
    if(zoom_current >= MAX_ZOOM || zoom_current <= MIN_ZOOM ){
            zoom_current = zoom_last;
            return;
    }
    // set zoom value to the current zoom amount, then zoom
    zoom_value *= amount;
    m_view.zoom(amount);
}
