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

    void zoom(float x);
    void move(float x, float y);

    sf::Vector2f getCenter()
    {
        return m_view.getCenter();
    }

    sf::Vector2i getAbsCenter()
    {
        return static_cast<sf::Vector2i>(m_view_absolute_center);
    }

    // move the camera/view to menu position or last game position
    // todo add a shader to obscure this transition
    //void menuView();
    //void gameView();

    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

    // returns a random number in the range low - high
    int getRandom(int low, int high);


private:

    // used to save last game camera/view position
    //int m_last_view_x;
    //int m_last_view_y;

    // used to find the absolute setTopLeft position
    sf::Vector2f m_view_absolute_center;

    Game() {}
    static Game* s_pInstance;

    sf::RenderWindow* m_renderWindow;
    sf::View m_view;
    //sf::VideoMode* m_videoMode;

    int m_screenWidth;
    int m_screenHeight;

    bool running;
    std::vector<GameObject*> m_gameObjects;
    //SDL_Window* window;
    //SDL_Renderer* renderer;
    GameStateMachine* m_pGameStateMachine;

    // used to generate random numbers
    std::random_device dev;



    int m_fps = 0;
};

//typedef Game Game;

#endif //KNIGHT_OF_FOO_GAME_H


