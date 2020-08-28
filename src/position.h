#ifndef POSITION_H
#define POSITION_H

#include "Position.h"

class Position{
    
public:
    Position(float x_pos, float y_pos);
    void setXPosition(float x);
    float getXPosition();
    void setYPosition(float y);
    float getYPosition();
    void move(float x, float y);
    void move_x_by(float x_offset);
    void move_y_by(float y_offset);
    
private:
    float x_position;
    float y_position;
};
#endif