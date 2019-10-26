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

    World(int w, int h);

    const int tile_w = 256; // pixel width of single tile
    const int tile_h = 128; // pixel height of single tile

    void generate();

    void update();
    void render();
    void clean();

    void selectTile(int i, int j);

private:
    int m_world_w; // width of the world in tiles
    int m_world_h; // height of the world in tiles

    ~World();

    void updateScreenBounds();
    int m_left;
    int m_right;
    int m_bottom;
    int m_top;

    std::map<int, std::map<int, Tile*>> m_tiles;
    //std::vector<Tile*> m_tiles;

};


#endif //TEAPOT_WORLD_H
