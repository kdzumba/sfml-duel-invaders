#include "Position.h"

Position::Position(float x, float y) : x_position{x}, y_position{y} //member initialisation list (C++11)
{
}

void Position::setXPosition(float x)
{
    x_position = x;
}

float Position::getXPosition()
{
    return x_position;
}

void Position::setYPosition(float y)
{
    y_position = y;
}

float Position::getYPosition()
{
    return y_position;
}

void Position::move(float x, float y)
{
    x_position = x;
    y_position = y;
}

void Position::move_x_by(float x_offset)
{
    x_position = x_position + x_offset;
}
    
    
void Position::move_y_by(float y_offset)
{
    y_position = y_position + y_offset; 
}

