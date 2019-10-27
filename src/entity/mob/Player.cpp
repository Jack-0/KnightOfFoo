//
// Created by jack on 27/10/19.
//

#include "Player.h"
#include "../../input/InputHandler.h"
#include "../../Game.h"

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

void Player::handleInput()
{
    // TODO note player m_pos is not altered

    int speed = 10;
    m_state = STATIONARY;

    // get keyboard input and map that to state
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::W)){
        m_sprite_sheet_ref = 0; // 0 is the index of the walking up sprite
        m_state = UP;
        Game::Instance()->move(0,-1 * speed); // move the game camera... TODO ?should camera point to player pos?
    }
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::S)){
        m_sprite_sheet_ref = 4; // 4 is the index of the walking down sprite
        m_state = DOWN;
        Game::Instance()->move(0,1 * speed);
    }
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::A)){
        m_sprite_sheet_ref = 8; // 8 is the index of the walking left sprite
        m_state = LEFT;
        Game::Instance()->move(-1 * speed,0);
    }
    if(TheInputHandler::Instance()->isKeyDown(sf::Keyboard::D)){
        m_sprite_sheet_ref = 12; // 12 is the index of the walking right sprite
        m_state = RIGHT;
        Game::Instance()->move(1 * speed,0);
    }
}

void Player::update()
{
    // center the player on screen
    m_pos = Game::Instance()->getCenter();
    m_pos.x = m_pos.x - m_width / 2;
    m_pos.y = m_pos.y - m_height / 2;

    // change state dependent on input
    handleInput();


    // clock operations
    // restart the clock if time elapsed is m_anim_speed * n ... where n is animation frames in each state
    if(m_anim_clock.getElapsedTime().asMilliseconds() > m_anim_speed * 2){
        m_anim_clock.restart();
    }
    // change m_anim_stage to allow for animations within each state
    if(m_anim_clock.getElapsedTime().asMilliseconds() > m_anim_speed)
        m_anim_stage = 1;
    else
        m_anim_stage = 0;

    // reset animation speed
    m_anim_speed = 150;

    // depending on state change player sprites
    switch(m_state)
    {
        case STATIONARY:
            m_anim_speed *= 2; // slow down animation speed by a factor of 2
            m_frame = m_sprite_sheet_ref + m_anim_stage + 2; // add 2 to display stationary sprite for current state
            break;
        case UP:
            m_frame = m_sprite_sheet_ref + m_anim_stage;
            break;
        case DOWN:
            m_frame = m_sprite_sheet_ref + m_anim_stage;
            break;
        case LEFT:
            m_frame = m_sprite_sheet_ref + m_anim_stage;
            break;
        case RIGHT:
            m_frame = m_sprite_sheet_ref + m_anim_stage;
            break;
        default:
            break;
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