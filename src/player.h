#ifndef PLAYER_H
#define PLAYER_H

#include "GameObjects.h" // no need to include 'Circle.h'
#include "Bullet.h"
#include "Position.h"

#include <SFML/Graphics.hpp>
//#include <Transformable.hpp>

class Player: public GameObjects
{
public:
    Player(float x_pos = 0.f, float y_pos = 0.f); //default constructor with default parameters
    void setPosition(float x, float y) override;
    const sf::Sprite& playerSprite(); //returns the sprite associated with player object
    Position getPosition(float x_pos, float y_pos);
    float getX() const;
    float getY() const;
    //void resetBulletPosition();
    //void rotate(float angle);
    //void sf::Transform setRotation(float angle);
    //float getRotation() const;
//    void move();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    virtual const Circle& getBoundingRegion() const override;
    
private:
    float x_position;
    float y_position;
    //float angle;
    Circle bounding_region; //composition (bounding region which accounts for radius and center points x and y)
    Bullet bullet; //composition
    Position player_position; //composition
    sf::Texture player_texture;
    sf::Sprite player_sprite;
    
};
#endif

/*
 * getPosition implementation:
 * Position player_pos(x_position, y_position);
 * return player_pos;
 *  return Position(x_position, y_Position);;
 * */