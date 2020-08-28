#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

#include "Circle.h"
#include "Position.h"

class GameObjects
{
public:
    GameObjects();
    virtual void setPosition(float x, float y) = 0;
    virtual const Circle &getBoundingRegion() const = 0;
};
#endif