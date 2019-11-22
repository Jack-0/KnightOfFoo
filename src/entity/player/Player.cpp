//
// Created by jack on 27/10/19.
//

#include "Player.h"
#include "../../input/InputHandler.h"

/**
 *  Create the player and scale by a factor of 4; ensures the sprite looks right in the game world
 */
Player::Player(const LoaderParams *pParams) : GameObject(pParams)
{
    // increase sprite size
    int scalar = 4;
    for(int i = 0; i < m_sprites.size(); i++){
        m_sprites[i].scale(scalar, scalar);
    }
    m_width *= scalar;
    m_height *= scalar;
}

/**
 * Alias to shorten InputHandler Singleton call
 */
bool Player::isDown(sf::Keyboard::Key key)
{
    return TheInputHandler::Instance()->isKeyDown(key);
}

/**
 * Change the players state based on current keyboard input
 */
void Player::handleInput()
{
    // shift to run
    if(isDown(sf::Keyboard::LShift)){
        m_speed = SPEED * 2;
    }
    else{
        m_speed = SPEED;
    }
    // default state is stationary
    m_state = STATIONARY;
    // change state on input; order matters here
    if(isDown(sf::Keyboard::W) && isDown(sf::Keyboard::D)){
        m_state = NORTH_EAST;
    }
    else if(isDown(sf::Keyboard::D) && isDown(sf::Keyboard::S)){
        m_state = SOUTH_EAST;
    }
    else if(isDown(sf::Keyboard::S) && isDown(sf::Keyboard::A)){
        m_state = SOUTH_WEST;
    }
    else if(isDown(sf::Keyboard::A) && isDown(sf::Keyboard::W)){
        m_state = NORTH_WEST;
    }
    else if(isDown(sf::Keyboard::W)){
        m_state = NORTH;
    }
    else if(isDown(sf::Keyboard::A)){
        m_state = WEST;
    }
    else if(isDown(sf::Keyboard::S)){
        m_state = SOUTH;
    }
    else if(isDown(sf::Keyboard::D)){
        m_state = EAST;
    }
}

/**
 *  Change player position and sprite based on current state.
 *  Also ensures the players movement is isometric (2.5D) not directly 2D
 */
void Player::handleState()
{
    switch(m_state)
    {
        case STATIONARY:
            break;
        case NORTH:
            m_sprite_sheet_ref = 0; // 0 is the index of walking up
            m_pos.y -= m_speed;
            break;
        case NORTH_EAST:
            m_sprite_sheet_ref = 12; // 12 is the index of the walking right sprite
            m_pos.y -= m_speed / 2;
            m_pos.x += m_speed;
            break;
        case EAST:
            m_sprite_sheet_ref = 12; // 12 is the index of the walking right sprite
            m_pos.x += m_speed;
            break;
        case SOUTH_EAST:
            m_sprite_sheet_ref = 12; // 12 is the index of the walking right sprite
            m_pos.y += m_speed / 2;
            m_pos.x += m_speed;
            break;
        case SOUTH:
            m_sprite_sheet_ref = 4; // 4 is the index of the walking down sprite
            m_pos.y += m_speed;
            break;
        case SOUTH_WEST:
            m_sprite_sheet_ref = 8; // 8 is the index of the walking left sprite
            m_pos.y += m_speed / 2;
            m_pos.x -= m_speed;
            break;
        case WEST:
            m_sprite_sheet_ref = 8; // 8 is the index of the walking left sprite
            m_pos.x -= m_speed;
            break;
        case NORTH_WEST:
            m_sprite_sheet_ref = 8; // 8 is the index of the walking left sprite
            m_pos.y -= m_speed / 2;
            m_pos.x -= m_speed;
            break;
        default:
            break;
    }
}

void Player::update()
{
    // change state dependent on input
    handleInput();
    handleState();

    // clock operations
    // restart the clock if time elapsed is m_anim_speed * n ... where n is animation frames in each state
    if(m_anim_clock.getElapsedTime().asMilliseconds() > m_anim_speed * 2){
        m_anim_clock.restart();
    }
    // change m_anim_stage to allow for animations within each state
    if(m_anim_clock.getElapsedTime().asMilliseconds() > m_anim_speed){
        m_anim_stage = 1;
    }
    else{
        m_anim_stage = 0;
    }

    // reset animation speed
    m_anim_speed = 150;

    if(m_state == STATIONARY){
        m_anim_speed *= 2;                               // slow down animation speed by a factor of 2
        m_frame = m_sprite_sheet_ref + m_anim_stage + 2; // add 2 to display stationary sprite for current state
    }
    else{
        m_frame = m_sprite_sheet_ref + m_anim_stage;
    }

    GameObject::update();
}

void Player::render()
{
    GameObject::render();
}

void Player::clean()
{
    GameObject::clean();
}