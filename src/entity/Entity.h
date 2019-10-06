//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_ENTITY_H
#define TEAPOT_ENTITY_H

class Entity
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

protected:
    Entity() {}
    virtual ~Entity(){}

};

#endif //TEAPOT_ENTITY_H
