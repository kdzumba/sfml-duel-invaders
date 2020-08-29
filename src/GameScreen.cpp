#include "GameScreen.h"
#include "config.h"

GameScreen::GameScreen()
{
    player = std::make_unique<Player>(GAME_WIDTH / 2, 0);
    bullet = std::make_unique<Bullet>(412, BULLET_SPRITE_HEIGHT);
    isPlaying = true;
}

void GameScreen::display(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
        }
    }
}

void GameScreen::handleEvents(sf::RenderWindow &window)
{
}