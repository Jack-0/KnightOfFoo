//
// Created by jack on 13/10/19.
//

#ifndef TEAPOT_WORLD_H
#define TEAPOT_WORLD_H

#include <vector>
#include <map>
#include "../entity/Tile.h"

class World
{
public:

    World();

    const int TILE_W = 256; // pixel width of single tile
    const int TILE_H = 128; // pixel height of single tile

    void generate();

    void update();
    void render();
    void clean();

    void selectTile(int i, int j);

    enum TILE_TYPES{
        VOID       = -1,
        GRASS      = 0,
        GRASS_DARK = 1,
        WATER      = 2,
    };

    sf::Vector2i getCenterTilePos() { return m_center_tile_pos; }

private:
    static const int m_world_w = 16; // width of the world in tiles
    static const int m_world_h = 64; // height of the world in tiles

    ~World();

    void updateScreenBounds();
    int m_left = 0;
    int m_right = 0;
    int m_bottom = 0;
    int m_top = 0;

    sf::Vector2i m_center_tile_pos;

    std::map<int, std::map<int, Tile*>> m_tiles;


    // cellular automata methods and variables for map generation
    bool cells[m_world_h][m_world_w];
    bool last_cells[m_world_h][m_world_h];

    int m_chance_to_start_alive = 4; // 40%
    int m_steps = 10;
    int m_death_limit = 4;
    int m_birth_limit = 4;

    void generateStep();
    int countNeighbours(int x, int y);

};


#endif //TEAPOT_WORLD_H
