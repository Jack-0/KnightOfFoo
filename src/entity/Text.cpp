//
// Created by jack on 06/10/19.
//

#include "Text.h"
#include "../Game.h"

Text::Text(sf::Vector2f position, std::string message, sf::Color colour, int fontSize)
: m_pos(position), m_msg(message), m_size(fontSize)
{
    if(!m_font.loadFromFile("../res/fonts/OpenSans-Regular.ttf"))
        std::cout << "Text: Error loading font\n";

    m_text.setFont(m_font);
    m_text.setString(m_msg);
    m_text.setCharacterSize(m_size);
    m_text.setFillColor(colour);
}

void Text::update()
{
    m_text.setPosition(m_pos);
}

void Text::render()
{
    Game::Instance()->getRenderWindow()->draw(m_text);
}

void Text::clean()
{

}


void Text::center(){m_pos = Game::Instance()->getCenter(); }
