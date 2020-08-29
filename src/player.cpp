#include "Player.h"
#include "Config.h" //including where you'll use it

#include <iostream>

Player::Player(float x_pos, float y_pos) : x_position{x_pos}, y_position{y_pos},
                                           bounding_region{PLAYER_SPRITE_WIDTH / 2, x_pos + PLAYER_SPRITE_WIDTH / 2, y_pos + PLAYER_SPRITE_HEIGHT / 2},
                                           bullet{x_pos, y_pos}
{
    player_texture.loadFromFile("resources/player_top.png");
    player_sprite.setTexture(player_texture);
    player_sprite.setPosition(x_position, y_position);
}

void Player::setPosition(float x, float y)
{
    x_position = x;
    y_position = y;
}

const sf::Sprite &Player::playerSprite()
{
    return player_sprite;
}

void Player::moveLeft()
{
    if (x_position > 0)
    {
        x_position -= PLAYER_SPEED;
    }
}

void Player::moveRight()
{
    if (x_position + PLAYER_SPRITE_WIDTH < GAME_WIDTH)
    {
        x_position += PLAYER_SPEED;
    }
}

void Player::moveUp()
{
    if (y_position > 0)
    {
        y_position += PLAYER_SPEED;
    }
}

//TODO: Move event handling stuff from this method
// void Player::move()
// {
//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//     {
//         if (y_position > 0)
//         {
//             y_position -= PLAYER_SPEED;
//         }
//     }

//     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//     {
//         if (y_position + PLAYER_SPRITE_HEIGHT < GAME_HEIGHT)
//         {
//             if (y_position + PLAYER_SPRITE_HEIGHT < GAME_HEIGHT / HEIGHT_RESTRICTION)
//             {
//                 y_position += PLAYER_SPEED;
//             }
//         }
//     }

//     player_sprite.setPosition(x_position, y_position);                                                 //include this to make sure object moves
//     bounding_region.move(x_position + PLAYER_SPRITE_WIDTH / 2, y_position + PLAYER_SPRITE_HEIGHT / 2); // moving circle with rectangular object (sprite) (radius constant)
// }

const Circle &Player::getBoundingRegion() const
{
    return bounding_region;
}