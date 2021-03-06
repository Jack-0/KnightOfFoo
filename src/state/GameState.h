//
// Created by jack on 31/05/19.
//

#ifndef KNIGHT_OF_FOO_GAMESTATE_H
#define KNIGHT_OF_FOO_GAMESTATE_H

#include <string>

/**
 * Abstract class
 */
class GameState
{
public:
    virtual void update() =0;
    virtual void render() = 0;

    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;

    virtual std::string getStateID() const = 0;

protected:
    std::vector<std::string> m_textureIDs;
};

#endif //KNIGHT_OF_FOO_GAMESTATE_H
