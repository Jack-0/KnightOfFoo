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
    // parse the state
    //StateParser stateParser;
    //stateParser.parseState("../res/xml/test.xml", s_menuID, &m_gameObjects, &m_textureIDs);

    m_callbacks.push_back(0); // to start from 1...
    m_callbacks.push_back(s_menuToPlay);
    m_callbacks.push_back(s_exitFromMenu);

    // set the callbacks from menu items
    setCallbacks(m_callbacks);
    // add buttons
    TheGfxManager::Instance()->addTexture("../res/buttons.png", "buttons");
    TheGfxManager::Instance()->addSprites("buttons", "btns", 256, 99, 15);

    Button* play_btn = new Button(new LoaderParams(sf::Vector2f(0,0),128,256,TheGfxManager::Instance()->getSprites("btns", 0, 3), false),1);
    Button* exit_btn = new Button(new LoaderParams(sf::Vector2f(0,100),128,256,TheGfxManager::Instance()->getSprites("btns", 0, 3), false),2);

    play_btn->setCallBack(m_callbacks[play_btn->getCallbackID()]);
    exit_btn->setCallBack(m_callbacks[exit_btn->getCallbackID()]);
    m_gameObjects.push_back(play_btn);
    m_gameObjects.push_back(exit_btn);

    ///TheProjectileHandler::Instance()->clean();
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
    TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MainMenuState::s_exitFromMenu()
{
    std::cout << "Exit btn clicked!\n";
    TheGame::Instance()->quit();
}


