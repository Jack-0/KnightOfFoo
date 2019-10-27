//
// Created by jack on 14/03/19.
//

#ifndef KNIGHT_OF_FOO_GAME_H
#define KNIGHT_OF_FOO_GAME_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

#include "state/GameStateMachine.h"
#include "state/MainMenuState.h"
#include "state/PlayState.h"
#include "input/InputHandler.h"


class Game
{
public:
    ~Game() {}

    /// Ensure game is a singleton
    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
    }

    sf::RenderWindow* getRenderWindow() { return m_renderWindow; }


    bool init(const char* title, int width, int height);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning() { return running; }
    void quit();

    //void zoom(float x);
    void move(float x, float y);

    sf::Vector2f getCenter()
    {
        return m_view.getCenter();
    }

    sf::Vector2f getAbsCenter()
    {
        return m_view_absolute_center;
    }

    sf::Vector2i getTopLeft()
    {
        //sf::Vector2i res = static_cast<sf::Vector2i>(m_view.getCenter());
        ///sf::Vector2i res =  m_renderWindow->mapCoordsToPixel(m_view.getCenter());
        sf::Vector2i res =  m_renderWindow->mapCoordsToPixel(m_view.getCenter());
        res.x += getAbsCenter().x - (m_screenWidth / 2 ) * zoomVal;
        res.y += getAbsCenter().y - (m_screenHeight / 2) * zoomVal;
        //res.x -= m_view.getSize().x;
        //res.y -= m_view.getSize().y;
        return res;
    }

    int getScreenLeft()   { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).x -  (m_screenWidth / 2) * zoomVal + m_view_absolute_center.x; }
    int getScreenRight()  { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).x +  (m_screenWidth / 2) * zoomVal + m_view_absolute_center.x;  }
    int getScreenTop()    { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).y -  (m_screenHeight / 2) * zoomVal + m_view_absolute_center.y; }
    int getScreenBottom() { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).y +  (m_screenHeight / 2) * zoomVal + m_view_absolute_center.y; }
    ///int getScreenLeft()   { return getCenter().x - (m_screenWidth / 2); }
    ///int getScreenRight()  { return getCenter().x + (m_screenWidth / 2); }
    ///int getScreenTop()    { return getCenter().y - (m_screenHeight / 2); }
    ///int getScreenBottom() { return getCenter().y + (m_screenHeight / 2); }

    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

    // returns a random number in the range low - high
    int getRandom(int low, int high);

    // renders text that displays a debug msg onto the screen
    void debugMsg(std::string msg) { m_debug_text->changeMsg("Debug: (zoom="+ std::to_string(zoomVal) +") " + msg); }

    int getZoomVal() { return zoomVal; }
    float getActualZoom() { return actZoomVal; }

private:

    // used to find the absolute setTopLeft position
    sf::Vector2f m_view_absolute_center;

    Game() {}
    static Game* s_pInstance;

    sf::RenderWindow* m_renderWindow;
    sf::View m_view;

    int m_screenWidth;
    int m_screenHeight;

    bool running;
    GameStateMachine* m_pGameStateMachine;

    // used to generate random numbers
    std::random_device dev;

    // create text that will show debug messages
    Text* m_debug_text;
    int m_fps = 0;

    // camera
    void updateCamera();
    void zoom(float amount);
    float actZoomVal = 0;
    float zoomVal = 1;
    float lastZoomVal;
    const int MAX_ZOOM = 8;
    const int MIN_ZOOM = -1;


};

//typedef Game Game;

#endif //KNIGHT_OF_FOO_GAME_H


