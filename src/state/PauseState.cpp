//
// Created by jack on 05/06/19.
//

#include "PauseState.h"
#include "../Game.h"
#include "../graphics/GraphicsManager.h"
#include "../entity/Button.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
    std::cout <<"Pause to main\n\n\n!!!!!";
    TheGame::Instance()->getStateMachine()->changeState(new MainMenuState());
}

void PauseState::s_resumePlay()
{
    std::cout <<"Resume play\n\n\n!!!!!!";
    TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
    m_resume_btn->setCentered( -(m_btn_w / 2), -((m_btn_h / 1.5)*2) );
    m_menu_btn->setCentered( -(m_btn_w / 2), 0);

    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PauseState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
        m_gameObjects[i]->render();
}

bool PauseState::onEnter()
{
    TheGame::Instance()->menuView(); // TODO this is a bit of a hack

    m_callbacks.push_back(0); // to start from 1...
    m_callbacks.push_back(s_resumePlay);
    m_callbacks.push_back(s_pauseToMain);


    // set the callbacks from menu items
    setCallbacks(m_callbacks);

    // variables for buttons
    int center_x = TheGame::Instance()->getCenter().x;
    int center_y = TheGame::Instance()->getCenter().y;
    // add button texture
    //TheGfxManager::Instance()->addTexture("../res/buttons.png", "buttons");
    //TheGfxManager::Instance()->addSprites("buttons", "btns", m_btn_w, m_btn_h, 15);
    // create buttons
    std::cout << "drawing sprites from x=" << center_x << " y=" << center_y << "!!!\n";
    m_resume_btn = new Button(new LoaderParams(sf::Vector2f(center_x - m_btn_w / 2, center_y - (m_btn_h / 1.5)*2 )
            ,m_btn_w, m_btn_h,TheGfxManager::Instance()->getSprites("btns", 9, 12), false), 1);
    m_menu_btn = new Button(new LoaderParams(sf::Vector2f(center_x - m_btn_w / 2, center_y)
            ,m_btn_w, m_btn_h,TheGfxManager::Instance()->getSprites("btns", 6, 9), false), 2);
    // add button callbacks
    m_resume_btn->setCallBack(m_callbacks[m_resume_btn->getCallbackID()]);
    m_menu_btn->setCallBack(m_callbacks[m_menu_btn->getCallbackID()]);
    // add buttons
    m_gameObjects.push_back(m_resume_btn);
    m_gameObjects.push_back(m_menu_btn);

    std::cout << "Entering pause state\n";
    return true;
}

void PauseState::setCallbacks(const std::vector<MenuState::Callback> &callbacks)
{
    // go through game objects
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        // if they are type button then set callback
        if(dynamic_cast<Button*>(m_gameObjects[i]))
        {
            Button* pButton = dynamic_cast<Button*>(m_gameObjects[i]);
            pButton->setCallBack(callbacks[pButton->getCallbackID()]);
        }
    }
}

bool PauseState::onExit()
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

    TheGame::Instance()->gameView();

    std::cout << "Exiting pause state\n";
    return true;
}
