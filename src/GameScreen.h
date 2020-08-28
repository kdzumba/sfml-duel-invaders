#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "screen.h"
#include "player.h"
#include "bullet.h"

#include <memory>

class GameScreen : public Screen
{
public:
    GameScreen();
    void display(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window) override;

private:
    std::unique_ptr<Player> player;
    std::unique_ptr<Bullet> bullet;
    bool isPlaying;
};
#endif //GAMESCREEN_H