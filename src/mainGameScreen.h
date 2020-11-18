#ifndef MAIN_GAMESCREEN_H
#define MAIN_GAMESCREEN_H

#include "Screen.h"
#include "player.h"
#include "Bullet.h"
#include "Aliens.h"
#include "Collision.h"
#include "constants.h"

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

class MainGameScreen : public Screen
{
public:
    MainGameScreen();
    //void begin(sf::RenderWindow &window) override; 
    void loop(sf::RenderWindow &window) override;
    void handleEvents(sf::RenderWindow &window) override;
    void render(sf::RenderWindow &window) override;
    void update();
    void end(sf::RenderWindow &window);
    bool isAlienDead(const Aliens& alien) {return !alien.isAlive();};

private:
    std::unique_ptr<Player> player;
    //std::unique_ptr<Player> player1;
    std::unique_ptr<Bullet> bullet;
    std::vector<std::shared_ptr<Aliens>> aliens;
    std::vector<std::shared_ptr<Aliens>> aliens1;
    sf::Clock clock;
    sf::Clock clock1;
    sf::Clock clock2;
    sf::Time bulletReferenceTimer = sf::milliseconds(20);
    sf::Time alienReferenceTimer = sf::milliseconds(20);
    sf::Time alienReferenceTimer1 = sf::milliseconds(20);
};
#endif