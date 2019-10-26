//
// Created by jack on 13/10/19.
//

#include "World.h"
#include "../graphics/GraphicsManager.h"
#include "../input/InputHandler.h"

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
    int x_offset   = 0; // due to the nature of isometric tiles even rows are offset
    int tile_x_pos = 0;
    int tile_y_pos = 0;

    // generates a grid of tiles m_world_h high and m_world_w wide
    for(int i = 0; i < m_world_h; i++)
    {
        // if the height is an even number then the isometric tile has a x offset
        if(i % 2 != 0 )
            x_offset = tile_w / 2;
        else
            x_offset = 0;

        for(int j = 0; j < m_world_w; j++)
        {
            // set the correct tile position
            tile_x_pos = ( j * tile_w) + x_offset;
            tile_y_pos = i * tile_h / 2;

            // add a new tile to vector m_tiles
            m_tiles[i][j] = new Tile( new LoaderParams(sf::Vector2f(tile_x_pos, tile_y_pos), tile_w, tile_h,
                                    TheGfxManager::Instance()->getSprites("tiles"), false,
                                    Game::Instance()->getRandom(0,3)));
            //m_tiles.push_back( new Tile( new LoaderParams(sf::Vector2f(tile_x_pos, tile_y_pos), tile_w, tile_h,
             //                       TheGfxManager::Instance()->getSprites("tiles"), false,
             //                       Game::Instance()->getRandom(0,3))));
        }
    }
}

void World::update()
{
    updateScreenBounds();

    for(int i = m_top; i < m_bottom; i++)
        for(int j = m_left; j < m_right; j++)
        {
            m_tiles[i][j]->update();
            if(m_tiles[i][j]->mouseOver())
                Game::Instance()->debugMsg(std::string(" i="+std::to_string(i)+" j="+std::to_string(j)));
        }
}

void World::render()
{
    updateScreenBounds();

    for(int i = m_top; i < m_bottom; i++)
        for(int j = m_left; j < m_right; j++)
            m_tiles[i][j]->render();

}

void World::updateScreenBounds()
{
    m_left   = Game::Instance()->getScreenLeft()   / tile_w;
    m_right  = Game::Instance()->getScreenRight()  / tile_w;
    m_bottom = Game::Instance()->getScreenBottom() / (tile_h / 2);
    m_top    = Game::Instance()->getScreenTop()    / (tile_h / 2);

    if(m_left < 0)
        m_left = 0;
    if(m_top < 0)
        m_top = 0;
    if(m_right > m_world_w)
        m_right = m_world_w;
    if(m_bottom > m_world_h)
        m_bottom = m_world_h;
}

void World::selectTile(int i, int j)
{
    m_tiles[i][j]->select();
}

void World::clean()
{
    // TODO remove used textures.... and clean
}


World::~World()
{
}