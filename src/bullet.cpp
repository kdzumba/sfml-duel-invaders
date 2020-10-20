#include "Bullet.h"
#include "Constants.h" //including where you'll use it

#include <iostream>

Bullet::Bullet(float x_position, float y_position):bounding_region{0.5, x_position, y_position}, bullet_position{x_position, y_position}
{   
    x_pos = x_position;
    y_pos = y_position;
    bullet_texture.loadFromFile("resources/laser.png");
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setPosition(x_pos, y_pos);
    fired = false;
}

/*Code should be open for extension but closed for modification*/

void Bullet::shoot()
{
    fired = true;
}

void  Bullet::deactivate()
{
    fired = false;
}

void Bullet::reset(float x_pos, float y_pos)
{
    setPosition(x_pos, y_pos);
}

bool Bullet::isFired() const 
{
    return fired;
}

void Bullet::move()
{   
    if(y_pos < GAME_HEIGHT && fired == true)
    {
        y_pos += BULLET_SPEED;
        bounding_region.move(x_pos + BULLET_SPRITE_WIDTH/2 , y_pos + BULLET_SPRITE_HEIGHT/2);
        bullet_sprite.setPosition(x_pos, y_pos);
    }
        else{
                deactivate();
            }
}

void Bullet::setPosition(float x, float y)
{ 
    x_pos = x;
    y_pos = y;
}

const sf::Sprite& Bullet::bulletSprite()
{   
    return bullet_sprite;
}

const Circle& Bullet::getBoundingRegion() const
{       
    return bounding_region;
    
}

Position Bullet::getPosition(float x_pos, float y_pos)
{       
    return bullet_position;
}