#ifndef COLLISION_H
#define COLLISION_H

#include "Bullet.h"
#include "Aliens.h"
#include "Circle.h"
#include "Position.h"
#include "MainGameScreen.h"

#include <SFML/Graphics.hpp>

class Collision
{
public:
    Collision(float x_position, float y_position);
    void object_collision();
    
private:
    float x_pos;
    float y_pos;
    Circle bounding_region;
    Position alien_position;
    Position bullet_position;
    MainGameScreen game;
};
#endif