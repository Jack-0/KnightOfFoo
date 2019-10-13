//
// Created by jack on 13/10/19.
//

#ifndef TEAPOT_WORLD_H
#define TEAPOT_WORLD_H

#include <vector>
#include "../entity/Tile.h"

class World
{
public:

    World(int w, int h);

    const int tile_w = 256; // pixel width of single tile
    const int tile_h = 128; // pixel height of single tile

    void generate();

    void update();
    void render();
    void clean();

private:
    int m_world_w; // width of the world in tiles
    int m_world_h; // height of the world in tiles

    ~World();

    std::vector<Tile*> m_tiles;

};


#endif //TEAPOT_WORLD_H
