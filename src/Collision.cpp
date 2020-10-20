#include "Collision.h"

Collision::Collision(float x_position, float y_position):bounding_region{GAME_HEIGHT/2, x_position, y_position}, bullet_position{x_position, y_position}, alien_position{x_position, y_position}
{   
    x_pos = x_position;
    y_pos = y_position;
    
}

void Collision::object_collision()
{
    if(bounding_region.intersects(bullet_position) == bounding_region.intersects(alien_position)) //variables for intersects
    {
        game.end(); //variable
    }
        else{
                continue;
            }
}