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

void GraphicsManager::addSprites(std::string texture_id, std::string sprite_id, int sprite_w, int sprite_h,
                                 int sprite_count)
{
    std::vector<sf::Sprite> sprites;
    int row = 0;
    int column = 0;

    for(int i = 0; i < sprite_count; i++)
    {
        sprites.push_back(sf::Sprite(m_textureMap[texture_id],
                sf::IntRect(column * sprite_w, row * sprite_h, sprite_w, sprite_h)));

        column++;

        if(column * sprite_w >= m_textureMap[texture_id].getSize().x)
        {
            column = 0;
            row++;
        }

        std::cout << "Texture=" << texture_id <<" pushed back sprite " << i << "(row=" << row << " col=" << column <<") texture.x =" << m_textureMap[texture_id].getSize().x <<"\n";
    }

    m_spriteMap[sprite_id] = sprites;
}

sf::Sprite GraphicsManager::getSprite(std::string id, int index)
{
    if(m_spriteMap[id].size() > index)
        return m_spriteMap[id][index];
    else
        std::cout << "GraphicsManager: getSprite( string= "<< id << ", index= " << index <<") Failed\n";
}

std::vector<sf::Sprite> GraphicsManager::getSprites(std::string id)
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

