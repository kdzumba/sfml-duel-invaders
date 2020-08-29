#include "mainGameScreen.h"
#include "config.h"
#include <iostream>

MainGameScreen::MainGameScreen()
{
    //Create player at the top center of the screen
    player = std::make_unique<Player>(GAMEWIDTH / 2, 0);
}

void MainGameScreen::loop(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        handleEvents(window);
        update();
        render(window);
    }
}

void MainGameScreen::handleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void MainGameScreen::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->moveDown();
    }
}

void MainGameScreen::render(sf::RenderWindow &window)
{
    window.clear();
    window.draw(player->playerSprite());
    window.display();
}