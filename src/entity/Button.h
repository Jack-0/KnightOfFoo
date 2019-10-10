//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_BUTTON_H
#define TEAPOT_BUTTON_H


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Text.h"
#include "GameObject.h"
#include "../utilities/LoaderParams.h"

class Button : public GameObject
{
public:
    Button(const LoaderParams *pParams, int callbackID);

    virtual void update();
    virtual void render();
    virtual void clean();

    void setCallBack(void(*callback) ()) {m_callback = callback; }
    int getCallbackID() { return m_callback_id; }

    void setCentered(int xOffset, int yOffset);

private:


    void (*m_callback) ();

    int m_callback_id;

    enum frame_state
    {
        MOUSE_OUT = 0,
        MOUSE_OVER = 1,
        MOUSE_CLICK = 2
    };
};


#endif //TEAPOT_BUTTON_H
