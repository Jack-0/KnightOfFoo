//
// Created by jack on 14/03/19.
//

#ifndef HELLOSDL_GAME_H
#define HELLOSDL_GAME_H

#include <vector>

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



    bool init(const char* title, int x, int y, int width, int height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool isRunning() { return running; }
    void quit();

    int updateFps(int fps) {m_fps = fps;}
    int getFps() { return  m_fps; }

    GameStateMachine* getStateMachine() { return m_pGameStateMachine; }
    //SDL_Renderer* getRenderer() const { return renderer; }
    int getScreenWidth() { return m_screenWidth; }
    int getScreenHeight() { return m_screenHeight; }
    //Vector2D getScreenCenter() { return m_screenCenter; }

    // returns a random number in the range low - high
    int getRandom(int low, int high);

private:

    Game() {}
    void draw();

    int m_screenWidth;
    int m_screenHeight;
    //Vector2D m_screenCenter = Vector2D(0,0);


    static Game* s_pInstance;
    bool running;
    std::vector<GameObject*> m_gameObjects;
    //SDL_Window* window;
    //SDL_Renderer* renderer;
    GameStateMachine* m_pGameStateMachine;

    // used to generate random numbers
    std::random_device dev;

    int m_fps = 0;
};

typedef Game TheGame;

#endif //HELLOSDL_GAME_H


