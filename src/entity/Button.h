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

class Button : GameObject
{
public:
    Button(const LoaderParams *pParams);

    void update();
    void render();
    void clean();

    void setCallBack(void(*callback) ()) {m_callback = callback; }

private:

    void (*m_callback) ();
};


#endif //TEAPOT_BUTTON_H
