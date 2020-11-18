#ifndef ALIENS_H
#define ALIENS_H

#include "GameObjects.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

enum class Direction{LEFT, RIGHT, UP};

class Aliens: public GameObjects
{
public:
    Aliens(float x_position, float y_position);
    void move();
    void move1();
    void move_x_by();
    void move_y_by();
    void setPosition(float x, float y);
    Position getPosition(float x_pos, float y_pos);
    void isDead();
    bool isAlive() const;
    const sf::Sprite& alienSprite();
    const sf::Sprite& alienSprite1();
    virtual const Circle& getBoundingRegion() const override;
    
private:
    float x_pos;
    float y_pos;
    bool alive;
    Circle bounding_region;
    Position alien_position;
    Direction direction;
    sf::Texture alien_texture;
    sf::Sprite alien_sprite;
    sf::Texture alien_texture1;
    sf::Sprite alien_sprite1;
};
#endif