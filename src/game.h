#ifndef GAME_H
#define GAME_H

#include "screen.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Game
{
public:
    Game();
    void start();

private:
    static int currentState;
    std::vector<std::shared_ptr<Screen>> screens;
    sf::RenderWindow gameWindow;
};

#endif