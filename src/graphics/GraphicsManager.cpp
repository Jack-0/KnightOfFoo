//
// Created by jack on 04/10/19.
//

#include "GraphicsManager.h"


GraphicsManager* GraphicsManager::s_pInstance = 0;

void GraphicsManager::drawSprite(sf::Sprite sprite)
{
    TheGame::Instance()->getRenderWindow()->draw(sprite);
}

bool GraphicsManager::addTexture(std::string filename, std::string id)
{
    sf::Texture temp_texture;
    if(!temp_texture.loadFromFile(filename.c_str()))
        std::cout << "TheGraphicsManager: Failed to load (" << filename << ")\n";

    m_textureMap[id] = temp_texture;
}


void GraphicsManager::removeTexture(std::string id)
{
    m_textureMap.erase(id);
}

void GraphicsManager::addSprite(std::string texture_id, std::string sprite_id, int start_x, int start_y, int width, int height)
{
    m_spriteMap[sprite_id] = sf::Sprite(m_textureMap[texture_id], sf::IntRect(start_x, start_y, width, height));
}

sf::Sprite GraphicsManager::getSprite(std::string id)
{
    return m_spriteMap[id];
}

void GraphicsManager::removeSprite(std::string id)
{
    m_spriteMap.erase(id);
}

void GraphicsManager::clean()
{
    m_spriteMap.clear();
    m_textureMap.clear();
}

GraphicsManager::~GraphicsManager()
{
    clean();
}

