#include "Aliens.h"
#include "Constants.h"

Aliens::Aliens(float x_position, float y_position):bounding_region{ALIEN_SPRITE_WIDTH/2, x_pos + ALIEN_SPRITE_WIDTH/2 , y_pos + ALIEN_SPRITE_HEIGHT/2}, alien_position{x_position, y_position}
{   
    x_pos = x_position;
    y_pos = y_position;
    direction = Direction::RIGHT;
    alien_texture.loadFromFile("resources/images/alien.png");
    alien_sprite.setTexture(alien_texture);
    alien_sprite.setPosition(x_pos, y_pos);
    alien_texture1.loadFromFile("resources/images/alien1.png");
    alien_sprite1.setTexture(alien_texture1);
    alien_sprite1.setPosition(x_pos, y_pos);
    alive = true;
}


void Aliens::move()
{
    if(direction == Direction::RIGHT && x_pos + ALIEN_SPRITE_WIDTH < GAME_WIDTH)
    {
        x_pos += ALIEN_SPEED;
    }
    else if(direction == Direction::LEFT && x_pos > 0)
    {
        x_pos += -1 * ALIEN_SPEED;
    }
    else if(x_pos + ALIEN_SPRITE_WIDTH >= GAME_WIDTH)
    {
        direction = Direction::LEFT;
        move_y_by();
    }
    else if(x_pos <= 0)
    {
        move_y_by();
        direction = Direction::RIGHT;
    }
  
    alien_sprite.setPosition(x_pos, y_pos); //include this to make sure object moves
    bounding_region.move(x_pos + ALIEN_SPRITE_WIDTH/2 , y_pos + ALIEN_SPRITE_WIDTH/2); // moving circle with rectangular object (sprite) (radius constant)
}

void Aliens::move1()
{
    if(direction == Direction::UP && y_pos + ALIEN_SPRITE_HEIGHT > HEIGHT_RESTRICTION)
    {
        y_pos += -1*ALIEN_SPEED;
    }
    else if(direction == Direction::RIGHT && x_pos + ALIEN_SPRITE_WIDTH < GAME_WIDTH)
    {
        direction = Direction::RIGHT;
        move_x_by();
    }
    else if(y_pos + ALIEN_SPRITE_HEIGHT > HEIGHT_RESTRICTION)
    {
        direction = Direction::UP;
        y_pos += -1*ALIEN_SPEED;
    }
    else if(x_pos >= 0)
    {
        x_pos += 1*ALIEN_SPEED;
        direction = Direction::LEFT;
    }
    
    alien_sprite1.setPosition(x_pos, y_pos); //include this to make sure object moves
    bounding_region.move(x_pos + ALIEN_SPRITE_WIDTH/2 , y_pos + ALIEN_SPRITE_WIDTH/2); // moving circle with rectangular object (sprite) (radius constant)
}

void Aliens::move_x_by()
{
    x_pos = x_pos + ALIEN_SPRITE_WIDTH;
}

void Aliens::move_y_by()
{
    y_pos = y_pos - ALIEN_SPRITE_HEIGHT; 
}

void Aliens::setPosition(float x, float y)
{
    x_pos = x;
    y_pos = y;
}

void Aliens::isDead() 
{
    alive = false;
}

bool Aliens::isAlive() const
{
    return alive;
}

const sf::Sprite& Aliens::alienSprite()
{   
    return alien_sprite;
}

const sf::Sprite& Aliens::alienSprite1()
{   
    return alien_sprite1;
}

const Circle& Aliens::getBoundingRegion() const
{       
    return bounding_region;
    
}

Position Aliens::getPosition(float x_pos, float y_pos)
{       
    return alien_position;
}