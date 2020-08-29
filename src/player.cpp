#include "Player.h"
#include "Config.h" //including where you'll use it

#include <iostream>

Player::Player(float xPos, float yPos) : xPosition{xPos}, yPosition{yPos},
                                         boundingRegion{PLAYERWIDTH / 2, xPos + PLAYERWIDTH, yPos + PLAYERHEIGHT / 2}
{
    texture.loadFromFile("../../resources/images/cannon.png");
    sprite.setTexture(texture);
    sprite.setPosition(xPosition, yPosition);
}

void Player::setPosition(float x, float y)
{
    xPosition = x;
    yPosition = y;
}

const sf::Sprite &Player::playerSprite()
{
    return sprite;
}

void Player::moveLeft()
{
    if (xPosition > 0)
    {
        xPosition -= PLAYERSPEED;
        sprite.setPosition(xPosition, yPosition);
    }
}

void Player::moveRight()
{
    if (xPosition + PLAYERWIDTH < GAMEWIDTH)
    {
        xPosition += PLAYERSPEED;
        sprite.setPosition(xPosition, yPosition);
    }
}

void Player::moveUp()
{
    if (yPosition > 0)
    {
        yPosition -= PLAYERSPEED;
        sprite.setPosition(xPosition, yPosition);
    }
}

void Player::moveDown()
{
    if (yPosition < 100)
    {
        yPosition += PLAYERSPEED;
        sprite.setPosition(xPosition, yPosition);
    }
}

const Circle &Player::getBoundingRegion() const
{
    return boundingRegion;
}