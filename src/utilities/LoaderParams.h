//
// Created by jack on 06/10/19.
//

#ifndef TEAPOT_LOADERPARAMS_H
#define TEAPOT_LOADERPARAMS_H

#include <string>

class LoaderParams
{
public:
    LoaderParams(sf::Vector2f pos, int height, int width,
            std::vector<sf::Sprite>sprites,
            int currentFrame=0, int numFrames=0,
            bool animated = false, int startFrame=0, int endFrame=0, float anim_speed = 200)
    :
    m_pos(pos),
    m_height(height),
    m_width(width),
    m_sprites(sprites),
    m_current_frame(currentFrame),
    m_num_frames(numFrames),
    m_start_frame(startFrame),
    m_end_frame(endFrame),
    m_animated(animated),
    m_anim_speed(anim_speed)
    {
        if(startFrame > endFrame)
            m_end_frame = startFrame;
    }

    // getters
    sf::Vector2f getPos() const  {return m_pos; }

    int getHeight() const { return m_height; }
    int getWidth() const { return m_width; }

    std::vector<sf::Sprite> getSprites() const{ return m_sprites; }

    bool getAnimated() const { return m_animated; }
    int getAnimationSpeed() const { return m_anim_speed;}

    int getCurrentFrame() const { return m_current_frame; }
    int getNumFrames() const { return m_num_frames; }
    int getStartFrame() const {return m_start_frame; }
    int getEndFrame() const {return m_end_frame; }

private:
    // position
    sf::Vector2f m_pos;

    // width and height of each sprite/object
    int m_height;
    int m_width;

    // animation variables
    int m_current_frame;
    int m_num_frames;
    bool m_animated;
    int m_anim_speed;
    int m_start_frame;
    int m_end_frame;
    std::vector<sf::Sprite> m_sprites;
};


#endif //TEAPOT_LOADERPARAMS_H
