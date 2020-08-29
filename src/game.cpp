#include "game.h"
#include "mainGameScreen.h"
#include "config.h"

int currentState = 0;

Game::Game() : gameWindow{sf::VideoMode(GAMEWIDTH, GAMEHEIGHT, 32), "Duel Invaders"}
{
    //TODO: use unique pointer for game screens??
    screens.emplace_back(std::make_shared<MainGameScreen>());
}

void Game::start()
{
    for (auto screen : screens)
    {
        screen->loop(gameWindow);
    }
}