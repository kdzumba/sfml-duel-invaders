#include "bullet.h"
#include "config.h"

#include <iostream>

Bullet::Bullet(float x_position, float y_position) : bounding_region{0.5, x_position, y_position}
{
    x_pos = x_position;
    y_pos = y_position;

    bullet_texture.loadFromFile("../../resources/images/laser.png");
    bullet_sprite.setTexture(bullet_texture);
    bullet_sprite.setPosition(x_pos, y_pos);
}

void Bullet::shoot()
{
    fired = true;
}

void Bullet::deactivate()
{
    fired = false;
}

void Bullet::move()
{
    if (y_pos < GAMEHEIGHT && fired == true)
    {
        y_pos += BULLETSPEED;
        bounding_region.move(x_pos + BULLETWIDTH / 2, y_pos + BULLETHEIGHT / 2);
        bullet_sprite.setPosition(x_pos, y_pos);
    }
    else
    {
        deactivate();
    }
}

void Bullet::setPosition(float x, float y)
{
    x_pos = x;
    y_pos = y;
}

const sf::Sprite &Bullet::bulletSprite()
{
    return bullet_sprite;
}

const Circle &Bullet::getBoundingRegion() const
{
    return bounding_region;
}