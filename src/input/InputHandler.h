//
// Created by jack on 07/10/19.
//

#ifndef TEAPOT_INPUTHANDLER_H
#define TEAPOT_INPUTHANDLER_H


#include <SFML/Window/Event.hpp>

class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
            s_pInstance = new InputHandler();

        return s_pInstance;
    }

    void update();
    void clean();

    // query if a key is down
    bool isKeyDown(sf::Keyboard::Key key);

    // query mouse input
    sf::Vector2i getMousePos();
    bool isMouseKeyDown(sf::Mouse::Button btn);

private:
    static InputHandler* s_pInstance;

    sf::Event* event = new sf::Event;

    InputHandler();
    ~InputHandler() {}

};

typedef InputHandler TheInputHandler;

#endif //TEAPOT_INPUTHANDLER_H
