#ifndef BULLET_H
#define BULLET_H

#include "GameObjects.h"
//#include "Player.h" cicrular dependencies i.e 'bullet depends on player'
#include "Position.h"

#include <SFML/Graphics.hpp>

class Bullet: public GameObjects
{
public:
    Bullet(float x_position = 0.f, float y_position = 0.f);
    void shoot();
    void move();
    void deactivate();
    void reset(float x_pos, float y_pos);
    bool isFired() const;
    void setPosition(float x, float y) override;
    Position getPosition(float x_pos, float y_pos);
    const sf::Sprite& bulletSprite(); //returns the sprite associated with bullet object
    virtual const Circle& getBoundingRegion() const override;
    
private:
    float x_pos;
    float y_pos;
    bool fired;
    Circle bounding_region;
    Position bullet_position;
    //MainGameScreen game;
    sf::Texture bullet_texture;
    sf::Sprite bullet_sprite;
};
#endif