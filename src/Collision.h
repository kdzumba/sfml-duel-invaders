#ifndef COLLISION_H
#define COLLISION_H

#include "Aliens.h"
#include "Bullet.h"
#include "Circle.h"

#include <SFML/Graphics.hpp>

class Collision
{
public:
    Collision(float x_position, float y_position);
    void check_collision();
    
private:
    float x_pos;
    float y_pos;
    Circle bounding_region;
    Aliens alien;
    Bullet bullet;
};
#endif