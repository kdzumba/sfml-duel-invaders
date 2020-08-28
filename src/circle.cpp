#include "Circle.h"

#include <cmath>
#include <iostream>

Circle::Circle(float rad, float x_cent, float y_cent):radius{rad}, x_center{x_cent}, y_center{y_cent}
{   
}

bool Circle::intersects(const Circle& other_circle) const
{   
    float center_distance = sqrt(pow(other_circle.x_center - x_center,2) + pow(other_circle.y_center - y_center,2));
    float radius_dictance = other_circle.radius + radius; // addition of radii from two circles
    
    if(center_distance > radius_dictance){
        return false;
    }
    else{
        return true;
    }
}

void Circle::move(float x, float y)
{
    x_center = x;
    y_center = y;
}