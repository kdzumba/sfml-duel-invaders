#include "Player.h"
#include "Constants.h" //including where you'll use it

#include <iostream>

Player::Player(float x_pos, float y_pos):bounding_region{PLAYER_SPRITE_WIDTH/2, x_pos + PLAYER_SPRITE_WIDTH/2 , y_pos + PLAYER_SPRITE_HEIGHT/2}, bullet{x_pos, y_pos}, player_position{x_pos, y_pos} //composition
{
    x_position = x_pos;
    y_position = y_pos;
    player_texture.loadFromFile("resources/player.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(x_position, y_position);
}

void Player::setPosition(float x, float y)
{
    x_position = x;
    y_position = y;
}

const sf::Sprite& Player::playerSprite()
{   
    return player_sprite;
}

//void Player::rotate(float angle)
//{
//    _angle = angle;
//}

//void sf::Transform Player::setRotation(float angle)
//{
//    _angle = angle;
//}
//
//float Player::getRotation() const
//{
//    return _angle;
//}

void Player::moveLeft()
{
     if(x_position > 0)
    {
        x_position -= PLAYER_SPEED;
        player_sprite.setPosition(x_position, y_position); //include this to make sure object moves on screen
        bounding_region.move(x_position + PLAYER_SPRITE_WIDTH/2 , y_position + PLAYER_SPRITE_HEIGHT/2); //moving circle with rectangular object (sprite) (radius constant)
    }
}

void Player::moveRight()
{
       
    if(x_position + PLAYER_SPRITE_WIDTH < GAME_WIDTH)
    {
        x_position += PLAYER_SPEED;
        player_sprite.setPosition(x_position, y_position);
        bounding_region.move(x_position + PLAYER_SPRITE_WIDTH/2 , y_position + PLAYER_SPRITE_HEIGHT/2); //moving circle with rectangular object (sprite) (radius constant)
    }
}

void Player::moveUp()
{
    if(y_position > 0)
    {
        y_position -= PLAYER_SPEED;
        player_sprite.setPosition(x_position, y_position);
        bounding_region.move(x_position + PLAYER_SPRITE_WIDTH/2 , y_position + PLAYER_SPRITE_HEIGHT/2); //moving circle with rectangular object (sprite) (radius constant)
    }
}

void Player::moveDown()
{
   if(y_position + PLAYER_SPRITE_HEIGHT < GAME_HEIGHT)
   {   
      if(y_position + PLAYER_SPRITE_HEIGHT < GAME_HEIGHT/HEIGHT_RESTRICTION)
      {
          y_position += PLAYER_SPEED;
          player_sprite.setPosition(x_position, y_position);
          bounding_region.move(x_position + PLAYER_SPRITE_WIDTH/2 , y_position + PLAYER_SPRITE_HEIGHT/2); //moving circle with rectangular object (sprite) (radius constant)
        }
    }
}

const Circle& Player::getBoundingRegion() const
{       
    return bounding_region;
}

Position Player::getPosition(float x_pos, float y_pos)
{       
    return player_position;
}

float Player::getX() const 
{
    return x_position;
}

float Player::getY() const 
{
    return y_position;
}
