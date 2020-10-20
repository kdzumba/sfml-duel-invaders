#include "Game.h"
#include "mainGameScreen.h"
#include "constants.h"

int currentState = 0;

Game::Game() : gameWindow{sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "Duel Invaders"}
{   
    //TODO: use unique pointer for game screens??
    screens.push_back(std::make_shared<MainGameScreen>()); //can also use emplace_back
}

void Game::start()
{
    for (auto screen : screens)
    {
        screen->loop(gameWindow);
    }
}
