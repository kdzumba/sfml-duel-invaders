#ifndef GAME_H
#define GAME_H

#include "Screen.h"
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

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