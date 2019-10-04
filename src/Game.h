//
// Created by jack on 14/03/19.
//

#ifndef HELLOSDL_GAME_H
#define HELLOSDL_GAME_H

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

    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

    // returns a random number in the range low - high
    int getRandom(int low, int high);

private:

    Game() {}
    static Game* s_pInstance;

    sf::RenderWindow* m_renderWindow;
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


    sf::Event* event;

    int m_fps = 0;
};

typedef Game TheGame;

#endif //HELLOSDL_GAME_H


