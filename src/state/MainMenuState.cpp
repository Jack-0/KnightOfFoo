//
// Created by jack on 31/05/19.
//

#include "MainMenuState.h"
#include "../Game.h"
#include "../entity/Button.h"
#include "../graphics/GraphicsManager.h"
#include <iostream>

const std::string MainMenuState::s_menuID = "MENU";

void MainMenuState::update()
{
    //m_play_btn->setCentered( -(m_btn_w / 2), -((m_btn_h / 1.5)*2) );
    //m_exit_btn->setCentered( -(m_btn_w / 2), 0);

    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MainMenuState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->render();
    }
}

bool MainMenuState::onEnter()
{
    //Game::Instance()->menuView();

    m_callbacks.push_back(0); // to start from 1...
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    // set the callbacks from menu items
    setCallbacks(m_callbacks);

    // variables for buttons
    int center_x = Game::Instance()->getCenter().x;
    int center_y = Game::Instance()->getCenter().y;
    // add button texture
    TheGfxManager::Instance()->addTexture("../res/buttons.png", "buttons");
    TheGfxManager::Instance()->addSprites("buttons", "btns", m_btn_w, m_btn_h, 15);
    // create buttons
    m_play_btn = new Button(new LoaderParams(sf::Vector2f(center_x - m_btn_w / 2, center_y - (m_btn_h / 1.5)*2 )
            ,m_btn_w, m_btn_h,TheGfxManager::Instance()->getSprites("btns", 0, 3), false), 1);
    m_exit_btn = new Button(new LoaderParams(sf::Vector2f(center_x - m_btn_w / 2, center_y)
            ,m_btn_w, m_btn_h,TheGfxManager::Instance()->getSprites("btns", 3, 6), false), 2);
    // add button callbacks
    m_play_btn->setCallBack(m_callbacks[m_play_btn->getCallbackID()]);
    m_exit_btn->setCallBack(m_callbacks[m_exit_btn->getCallbackID()]);
    // add buttons
    m_gameObjects.push_back(m_play_btn);
    m_gameObjects.push_back(m_exit_btn);

    std::cout << "Entering menu state\n";
    return true;
}

void MainMenuState::setCallbacks(const std::vector<MenuState::Callback> &callbacks)
{
    // go through game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        if(dynamic_cast<Button*>(m_gameObjects[i]))
        {
            Button* pButton = dynamic_cast<Button*>(m_gameObjects[i]);
            pButton->setCallBack(callbacks[pButton->getCallbackID()]);
        }
    }
}

bool MainMenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }

    m_gameObjects.clear();

    for (int i = 0; i < m_textureIDs.size(); i++)
    {
        //TheTextureManager::Instance()->clearFromTextureMap(m_textureIDs[i]);
    }

    std::cout << "Exiting menu state\n";
    return true;
}

void MainMenuState::s_menuToPlay()
{
    std::cout << "Play btn clicked!\n";
    // TODO playstate is causing the problem works with new MenuState?? seg fault
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu()
{
    std::cout << "Exit btn clicked!\n";
    Game::Instance()->quit();
}


