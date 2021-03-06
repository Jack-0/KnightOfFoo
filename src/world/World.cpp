//
// Created by jack on 13/10/19.
//

#include "World.h"
#include "../graphics/GraphicsManager.h"
#include "../input/InputHandler.h"

// TODO fix code readability as i = is height in cells but is width in tiles... doesn't matter for now

World* World::s_pInstance = 0; // singleton


World::World()
{
    // load texture and create sprites from it
    TheGfxManager::Instance()->addTexture("../res/ground_tiles.png", "ground_tiles");    // load textures
    TheGfxManager::Instance()->addSprites("ground_tiles", "tiles", 256, 128, 4);         // create tile sprites
    //TheGfxManager::Instance()->addSprites("ground_tiles", "half_tiles", 256/2, 128, 4*2);     // create half tile sprites


    // add floating rock stuff
    TheGfxManager::Instance()->addTexture("../res/float_rock.png", "rock");    // load textures
    TheGfxManager::Instance()->addSprites("rock", "tile_edge", 256, 256, 4);         // create tile sprites

    generate();
}

void World::generateStep()
{
    for(int i = 0; i < m_world_h; i++)
        for(int j = 0; j < m_world_w; j++)
            last_cells[i][j] = cells[i][j];

    //Loop over each row and column of the map
    for(int x = 0; x <= m_world_h; x++){
        for(int y = 0; y <= m_world_w; y++){
            int nbs = countNeighbours(x, y);
            // new value is based on our simulation rules
            // if a cell is alive but has too few neighbours, kill it.
            if(last_cells[x][y]){
                if(nbs < m_death_limit){
                    cells[x][y] = false;
                }
                else{
                    cells[x][y] = true;
                }
            }
            // if the cell is dead now, check if it has the right number of neighbours to be 'born'
            else{
                if(nbs > m_birth_limit){
                    cells[x][y] = true;
                }
                else{
                    cells[x][y] = false;
                }
            }
        }
    }
}

int World::countNeighbours(int x, int y)
{
    int count = 0;
    for(int i =- 1; i < 2; i++){
        for(int j =- 1; j < 2; j++){
            int neighbour_x = x+i;
            int neighbour_y = y+j;
            // middle point
            if(i == 0 && j == 0){
                // do nothing middle point
            }
            // index is off the edge of the map (counts as alive)
            else if(neighbour_x < 0 || neighbour_y < 0 || neighbour_x >= m_world_h || neighbour_y >= m_world_w){
                count = count + 1;
            }
            // check if neighbour is alive
            else if(cells[neighbour_x][neighbour_y]){
                count = count + 1;
            }
        }
    }
    return count;
}

void World::generate()
{
    /// init cells with a chance to start alive
    // true = dead, false = alive
    for(int i = 0; i <= m_world_h; i++)
        for(int j = 0; j <= m_world_w; j++)
            if(Game::Instance()->getRandom(0,10) < m_chance_to_start_alive)
                cells[i][j] = true;
            else
                cells[i][j] = false;

    /// center tiles must be occupied
    m_center_tile_pos = sf::Vector2i( (m_world_w / 2) * TILE_W, (m_world_h / 2) * TILE_H / 2);
    int center_tile_x = m_world_h / 2;
    int center_tile_y = m_world_w / 2;
    cells[center_tile_x][center_tile_y] = false;

    int r = 2; // radius of center tiles
    // set tiles around center to be alive
    for(int i = center_tile_x - r; i <= center_tile_x + r; i++) {
        for (int j = center_tile_y - r; j <= center_tile_y + r; j++) {
            cells[i][j] = false;
        }
    }

    /// generate map using cellular automata
    for(int i=0; i < m_steps; i++)
        generateStep();

    /// create tiles
    int x_offset   = 0; // due to the nature of isometric tiles even rows are offset
    int tile_x_pos = 0;
    int tile_y_pos = 0;



    // generates a grid of tiles m_world_h high and m_world_w wide
    for(int i = 0; i < m_world_h; i++)
    {
        // if the height is an even number then the isometric tile has a x offset
        if(i % 2 != 0 )
            x_offset = TILE_W / 2;
        else
            x_offset = 0;

        for(int j = 0; j < m_world_w; j++)
        {
            // set the correct tile position
            tile_x_pos = ( j * TILE_W) + x_offset;
            tile_y_pos = i * TILE_H / 2;

            // generate all other tiles based on cellular automa results
            if(cells[i][j]){
                m_tiles[i][j] = new Tile( new LoaderParams(sf::Vector2f(tile_x_pos, tile_y_pos), TILE_W, TILE_H,
                                                           TheGfxManager::Instance()->getSprites("tiles"), false,
                                                           0), VOID, i, j);
            }
            else{
                m_tiles[i][j] = new Tile( new LoaderParams(sf::Vector2f(tile_x_pos, tile_y_pos), TILE_W, TILE_H,
                                                           TheGfxManager::Instance()->getSprites("tiles"), false,
                                                           0), Game::Instance()->getRandom(GRASS, WATER), i, j);
            }
        }
    }
    m_tiles[m_world_h / 2][m_world_w / 2]->select();

    updateEdgeTiles();
}

/**
 * update edge tiles based on current position
 *
 * Tiles can have edges currently we only focus on the bottom two edges of the isometric tile A and B as shown below
 *
 *    A / \ B
 *
 * A even x position (i - in our loop) iso tile will have a different position for A and B in comparision to a non-even
 * iso tile.
 * For example:
 *      with even tiles, A = [i-1][j-1] B = [i-1][j]
 *      with odd tiles,  A = [i-i][j]   B = [i-1][j+1]
 *
 * this is due to even tiles being offset from odd to to create a lattice of isometric tiles
 */
void World::updateNeighbours(int i, int j)
{
    if(i > 0) {
        /// valid tile
        if (i % 2 == 0) {
            /// even tile
            // set A to edge
            m_tiles[i-1][j-1]->setEdge();
            // set B to edge
            m_tiles[i-1][j]->setEdge();

        } else {
            /// odd tile
            // set A to edge
            m_tiles[i-1][j]->setEdge();
            // set B to edge
            m_tiles[i-1][j+1]->setEdge();

        }
    }
}


/**
 * update edge tiles based on cells[][]
 *
 * Tiles can have edges currently we only focus on the bottom two edges of the isometric tile A and B as shown below
 *
 *    / \
 *   A\ /B
 *
 * A even x position (i - in our loop) iso tile will have a different position for A and B in comparision to a non-even
 * iso tile.
 * For example:
 *      with even tiles, A = [i+1][j-1] B = [i+1][j]
 *      with odd tiles,  A = [i+i][j]   B = [i+1][j+1]
 *
 * this is due to even tiles being offset from odd to to create a lattice of isometric tiles
 */
void World::updateEdgeTiles()
{
    for(int i = 0; i < m_world_h; i++){
        for(int j = 0; j < m_world_w; j++){

            // start all as false
            edgeTiles[i][j] = false;

            // check if tiles are edge tiles by comparing them to their neighbours
            if(i % 2 == 0)
            {
                // even tiles
                // check bounds to prevent array index errors
                if(i + 1 <= m_world_h && j - 1 >= 0)
                {
                    // if the selected tile is ground but the surrounding are empty we are indexed at an edge tile
                    if(!cells[i][j] && (cells[i+1][j-1] || cells[i+1][j]) )
                        edgeTiles[i][j] = true;
                }
                // check if the neighbours are out of bounds but the current tile is in bounds
                else if(!cells[i][j] && (j <= 0 || i >= m_world_h) )
                    edgeTiles[i][j] = true;
            }
            else
            {
                //odd tiles
                // check bounds to prevent array index errors
                if(i + 1 <= m_world_h && j + 1 < m_world_w)
                {
                    // if the selected tile is ground but the surrounding are empty we are indexed at an edge tile
                    if(!cells[i][j] && (cells[i+1][j] || cells[i+1][j+1]) )
                        edgeTiles[i][j] = true;
                }
                else if(!cells[i][j])
                    edgeTiles[i][j] = true;
            }


            if(edgeTiles[i][j])
                m_tiles[i][j]->setEdge();
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
    for(int i = m_top; i < m_bottom; i++)
        for(int j = m_left; j < m_right; j++)
            m_tiles[i][j]->render();
}

/**
 * Ensure that only tiles on the screen are within the screen bounds.
 * This is done for performance.
 */
void World::updateScreenBounds()
{
    // calculate what tiles are on the screen
    m_left   = Game::Instance()->getScreenLeft()   / TILE_W;
    m_right  = Game::Instance()->getScreenRight()  / TILE_W;
    m_bottom = Game::Instance()->getScreenBottom() / (TILE_H / 2);
    m_top    = Game::Instance()->getScreenTop()    / (TILE_H / 2);

    // offset each bound by +/-1 to... this renders tiles that are half inside the screen bounds
    m_left--;
    m_right++;
    m_top -= 3; // 3 to ensure tile edge is rendered on screen (a tile edge is under a tile, hence rendering 2 extra tiles above screen bounds; to ensure tile edge is shown in-game)
    m_bottom++;

    // check that the tile bound is not invalid, due to scrolling the screen further than the tile map
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