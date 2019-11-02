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

    bool init(const char* title, int width, int height);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning() { return running; }
    void quit();

    void focusOnPlayer(Player* p);

    //void zoom(float x);
    void move(float x, float y);

    // get pointer to render window
    sf::RenderWindow* getRenderWindow() { return m_renderWindow; }
    // get pointer to game state machine
    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
    // get value of screen center
    sf::Vector2f getCenter() { return m_view.getCenter(); }
    // get value of screen center plus offset
    sf::Vector2f getAbsCenter() { return m_view_absolute_center; }

    // get screen bounds (factoring in zoom and absolute position)

    int getScreenLeft()   { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).x - (m_screenWidth / 2) * zoom_value + m_view_absolute_center.x; }
    int getScreenRight()  { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).x + (m_screenWidth / 2) * zoom_value + m_view_absolute_center.x;  }
    int getScreenTop()    { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).y - (m_screenHeight / 2) * zoom_value + m_view_absolute_center.y; }
    int getScreenBottom() { return m_renderWindow->mapCoordsToPixel(m_view.getCenter()).y + (m_screenHeight / 2) * zoom_value + m_view_absolute_center.y; }

    // get the scalar for camera zoom
    float getZoomVal() { return zoom_value; }

    // returns a random number in the range low - high
    int getRandom(int low, int high);

    // renders text that displays a debug msg onto the screen
    void debugMsg(std::string msg) { m_debug_text->changeMsg("Debug: (zoom="+ std::to_string(zoom_value) +") " + msg); }

private:

    // used to find the absolute setTopLeftAndScale position
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

    // camera variables
    float zoom_current = 0;
    float zoom_value = 1;
    float zoom_last;
    const int MAX_ZOOM = 3;
    const int MIN_ZOOM = -2;
    // camera methods
    void updateCamera();
    void zoom(float amount);

};

//typedef Game Game;

#endif //KNIGHT_OF_FOO_GAME_H


