//
// Created by jack on 13/10/19.
//

#ifndef TEAPOT_TILE_H
#define TEAPOT_TILE_H


#include "GameObject.h"

class Tile : public GameObject
{
public:
    Tile(const LoaderParams* pParams);

    virtual void update();
    virtual void render();
    virtual void clean();

private:

    bool selected = false;

};


#endif //TEAPOT_TILE_H
