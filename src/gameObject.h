#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Circle.h"
#include "Position.h"

class GameObject
{
public:
    GameObject();
    virtual void setPosition(float x, float y) = 0;
    virtual const Circle &getBoundingRegion() const = 0;
};
#endif //GAMEOBJECT_H