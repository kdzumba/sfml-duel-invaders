#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h" // no need to include 'Circle.h'
#include "Bullet.h"

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
    float xPosition;
    float yPosition;
    Circle boundingRegion; //composition
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif