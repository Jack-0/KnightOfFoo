//
// Created by jack on 04/10/19.
//

#ifndef TEAPOT_TEXTUREMANAGER_H
#define TEAPOT_TEXTUREMANAGER_H

#include <map>
#include <string>
#include <iostream>
#include <vector>

#include "../Game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

// Manages textures
// Manages sprites
// TODO manage shaders

class GraphicsManager
{
public:

    static  GraphicsManager* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new GraphicsManager();
            return s_pInstance;
        }
    }

    bool addTexture(std::string filename, std::string id);
    void removeTexture(std::string id);

    void addSprite(std::string texture_id, std::string sprite_id, int start_x, int start_y, int width, int height);
    sf::Sprite getSprite(std::string id);
    void removeSprite(std::string id);
    void drawSprite(sf::Sprite sprite);

    void clean();

private:

    static GraphicsManager* s_pInstance;
    ~GraphicsManager();

    std::map<std::string, sf::Texture> m_textureMap;
    std::map<std::string, sf::Sprite> m_spriteMap;
};

typedef GraphicsManager TheGfxManager;

#endif //TEAPOT_TEXTUREMANAGER_H
