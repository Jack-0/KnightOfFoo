//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_TEXT_H
#define TEAPOT_TEXT_H


#include <SFML/System.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Entity.h"

class Text : Entity
{
public:
    Text(sf::Vector2f position, std::string message, sf::Color colour = sf::Color::White, int fontSize = 24);

    void update();
    void render();
    void clean();

    void changeMsg(std::string newMsg) {m_msg = newMsg;}

private:
    sf::Vector2f m_pos;
    std::string m_msg;
    sf::Text m_text;
    int m_size;
    sf::Font m_font;

};


#endif //TEAPOT_TEXT_H
