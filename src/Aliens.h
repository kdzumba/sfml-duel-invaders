#ifndef ALIENS_H
#define ALIENS_H

#include "GameObjects.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

enum class Direction{LEFT, RIGHT};

class Aliens: public GameObjects
{
public:
    Aliens(float x_position, float y_position);
    void move();
    void move_x_by();
    void move_y_by();
    void setPosition(float x, float y);
    Position getPosition(float x_pos, float y_pos);
    const sf::Sprite& alienSprite();
    virtual const Circle& getBoundingRegion() const override;
    
private:
    float x_pos;
    float y_pos;
    Circle bounding_region;
    Position alien_position;
    Direction direction;
    sf::Texture alien_texture;
    sf::Sprite alien_sprite;
};
#endif