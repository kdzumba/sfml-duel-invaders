#ifndef BULLET_H
#define BULLET_H

#include "GameObjects.h"
//#include "Player.h" cicrular dependencies i.e 'bullet depends on player'
#include "Position.h"

#include <SFML/Graphics.hpp>

class Bullet : public GameObjects
{
public:
    Bullet(float x_position = 0.f, float y_position = 0.f);
    void setPosition(float x, float y) override;
    virtual const Circle &getBoundingRegion() const override;
    void move();
    void deactivate();
    void shoot();

    const sf::Sprite &bulletSprite(); //returns the sprite associated with bullet object

private:
    float x_pos;
    float y_pos;
    bool fired;
    Circle bounding_region;

    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
};
#endif