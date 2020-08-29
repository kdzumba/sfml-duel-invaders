#ifndef MAIN_GAMESCREEN_H
#define MAIN_GAMESCREEN_H

#include "screen.h"
#include "player.h"
#include <memory>
#include <SFML/Graphics.hpp>

class MainGameScreen : public Screen
{
public:
    MainGameScreen();
    void loop(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    void update();

private:
    std::unique_ptr<Player> player;
};
#endif //MAIN_GAMESCREEN_H