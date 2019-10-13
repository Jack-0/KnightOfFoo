//
// Created by jack on 13/10/19.
//

#include "World.h"
#include "../graphics/GraphicsManager.h"

World::World(int w, int h)
{
    m_world_w = w;
    m_world_h = h;

    // load texture and create sprites from it
    TheGfxManager::Instance()->addTexture("../res/test.png", "ground_tiles");    // load texture
    TheGfxManager::Instance()->addSprites("ground_tiles", "tiles", 256, 128, 4); // create sprites

    generate();
}

void World::generate()
{
    int x_offset = 0;
    int tile_x_pos = 0;
    int tile_y_pos = 0;

    for(int i = 0; i < m_world_h; i++)
    {
        if(i % 2 != 0 )
            x_offset = tile_w / 2;
        else
            x_offset = 0;

        for(int j = 0; j < m_world_w; j++)
        {
            tile_x_pos = ( j * tile_w) + x_offset;
            tile_y_pos = i * tile_h / 2;

            // add a new tile to vector m_tiles
            m_tiles.push_back( new Tile( new LoaderParams(sf::Vector2f(tile_x_pos, tile_y_pos), tile_w, tile_h,
                                    TheGfxManager::Instance()->getSprites("tiles"), false,
                                    Game::Instance()->getRandom(0,3))));
        }
    }
}

void World::update()
{
    for(int i = 0; i < m_tiles.size(); i++)
        m_tiles[i]->update();
}

void World::render()
{
    for(int i = 0; i < m_tiles.size(); i++)
        m_tiles[i]->render();
}

void World::clean()
{}

World::~World()
{
    // TODO remove used textures.... and clean
}