////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>

#include "Player.h"
#include "Bullet.h"
#include "Constants.h"
#include "Position.h"
#include "Aliens.h"

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
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH, GAME_HEIGHT, 32), "SFML Pong", // ------> part taken to Game.cpp constructor
                            sf::Style::Titlebar | sf::Style::Close); // ---> not this part
    window.setVerticalSyncEnabled(true);

    // Load the text font
    sf::Font font;
    if (!font.loadFromFile("resources/sansation.ttf"))
        return EXIT_FAILURE;
    
    //Player player;
    auto player = Player{GAME_WIDTH/2, 0}; // constructor ----> all created objects taken to MainGameScreen constructor

    auto bullet = Bullet{412, BULLET_SPRITE_HEIGHT};
    
    auto player1 = Player{GAME_WIDTH/2, GAME_HEIGHT - PLAYER_SPRITE_HEIGHT};
    
    auto alien = Aliens{0, GAME_HEIGHT/2};
    
    auto alien1 = Aliens{ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_SPACING, GAME_HEIGHT/2};
    
    auto alien2 = Aliens{ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_SPACING + ALIEN_SPRITE_SPACING, GAME_HEIGHT/2};
    
    auto alien3 = Aliens{ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_WIDTH + ALIEN_SPRITE_SPACING + ALIEN_SPRITE_SPACING + ALIEN_SPRITE_SPACING , GAME_HEIGHT/2};
    
    // Initialize the pause message
    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::Blue);
    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

    bool isPlaying = false;
    
    sf::Clock clock;
    sf::Clock clock1;
        
    sf::Time bulletReferenceTimer = sf::milliseconds(20);
    sf::Time alienReferenceTimer = sf::milliseconds(20);
    
    while (window.isOpen()) //----> line 66 taken to 
    {   
        // Handle events
        sf::Event event; // ----> line 69 - 76 taken to handleEvents() function in MainGameScreen (excluding the '||' and line 74)
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
            
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //----> line 92 - 111 taken to update() function in MainGameScreen
           {
                player.moveLeft();
                
           }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
           {
                player.moveRight();
                
           }
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
           {
                player.moveUp();
                
           }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
           {
                player.moveDown();
                
           }
           
           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
           {    
               bullet.shoot();
               
           }
           
           if(clock.getElapsedTime() >= bulletReferenceTimer)
           {    
                bullet.move();
                clock.restart();
           }
           
           if(bullet.isFired() == false)
           {
               bullet.reset(player.getX(), player.getY());
           }
           
           if(clock1.getElapsedTime() >= alienReferenceTimer)
           {    
                alien.move();
                
                alien1.move();
                
                alien2.move();
                
                alien3.move();
                
                clock1.restart();
           }

           // Clear the window
           window.clear(sf::Color(50, 200, 50)); //---> line 120 goes to render() function in MainGameScreen
            
           //draw bullet
           window.draw(bullet.bulletSprite());
 
           //draw player
           window.draw(player.playerSprite()); //---> line 126 goes to render() function in MainGameScreen
            
           //draw player1
           //player1.rotate(180.f);
           window.draw(player1.playerSprite());
           
           window.draw(alien.alienSprite());
           
           window.draw(alien1.alienSprite());
           
           window.draw(alien2.alienSprite());
           
           window.draw(alien3.alienSprite());
        }
        else
        {
            // Draw the pause message
            window.draw(pauseMessage);
        }

        // Display things on screen
        window.display(); //---> line 150 goes to render() function in MainGameScreen
    }

    return EXIT_SUCCESS;
}
