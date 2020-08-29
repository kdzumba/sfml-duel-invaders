#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h" // no need to include 'Circle.h'
#include "Bullet.h"
#include "Position.h"

#include <SFML/Graphics.hpp>

class Player : public GameObject
{
public:
    Player(float x, float y);
    void setPosition(float x, float y) override;
    const Circle &getBoundingRegion() const;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    const sf::Sprite &playerSprite();

private:
    float x_position;
    float y_position;
    Circle bounding_region; //composition
    Bullet bullet;          //composition
    sf::Texture player_texture;
    sf::Sprite player_sprite;
};
#endif