//
// Created by jack on 24/12/2019.
//

#ifndef KNIGHT_OF_FOO_ENEMY_H
#define KNIGHT_OF_FOO_ENEMY_H


#include "../GameObject.h"

class Enemy : public GameObject {
public:
    Enemy(const LoaderParams* pParams);

    virtual void update();
    virtual void render();
    virtual void clean();

private:
    int health = 100;
};


#endif //KNIGHT_OF_FOO_ENEMY_H
