////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "player.h"
#include "bullet.h"
#include "Constants.h"
#include "Position.h"

using namespace std;

////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    // Create the window of the application
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "SFML Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;

    //Player player;
    auto player = Player{GAME_WIDTH / 2, 0}; // constructor

    auto bullet = Bullet{412, BULLET_SPRITE_HEIGHT};

    auto player1 = Player{GAME_WIDTH / 2, GAME_HEIGHT - PLAYER_SPRITE_HEIGHT};

    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::Blue);
    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

    bool isPlaying = false;

    sf::Clock bulletClock;
    sf::Time bulletReferenceTimer = sf::milliseconds(20);

    while (window.isOpen())
    {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Window closed or escape key pressed: exit
            if ((event.type == sf::Event::Closed) ||
                ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
            {
                window.close();
                break;
            }

            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
            {
                isPlaying = true;
            }
        }

        if (isPlaying)
        {
            player.move();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                bullet.shoot();
            }

            if (bulletClock.getElapsedTime() >= bulletReferenceTimer)
            {
                bullet.move();
                bulletClock.restart();
            }
            // Clear the window
            window.clear(sf::Color(0, 0, 0));

            //draw bullet
            window.draw(bullet.bulletSprite());

            //draw player
            window.draw(player.playerSprite());

            //draw player1
            //player1.rotate(180.f);
            window.draw(player1.playerSprite());
        }

        else
        {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
