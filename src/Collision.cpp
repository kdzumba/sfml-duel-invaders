#include "Collision.h"

Collision::Collision(float x_position, float y_position):bounding_region{, x_position, y_position}, bullet_position{5.0, x_position, y_position}, alien_position{12.5, x_position, y_position} //initialisation
{   
    x_pos = x_position;
    y_pos = y_position;
    
}

//can you have two constructors???

void Collision::check_collision()
{   
    while(bounding_region.move(alien.move_x_by(), alien.move_y_by()) && bounding_region.move(bullet.move(),bullet.move())
    {    
        if(bounding_region.intersects(alien.getBoundingRegion()) == bounding_region.intersects(bullet.getBoundingRegion())) //variables for intersects
        {
            //end game;
        }
            else{
                    //continue game;
                }
    }
}