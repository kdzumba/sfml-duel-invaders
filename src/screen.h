#ifndef SCREEN_H
#define SCREEN_H

#include <SFML/Graphics.hpp>
class Screen
{
public:
    virtual void loop(sf::RenderWindow &window) = 0;
    virtual void handleEvents(sf::RenderWindow &window) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
};
#endif //SCREEN_H