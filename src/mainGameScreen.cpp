#include "MainGameScreen.h"
#include "constants.h"

//???? Put auto infront of variables???

MainGameScreen::MainGameScreen()
{
    player = std::make_unique<Player>(GAME_WIDTH / 2, 0); //Create player at the top center of the screen
    //player1 = std::make_unique<Player>(GAME_WIDTH/2, GAME_HEIGHT - PLAYER_SPRITE_HEIGHT);
    bullet = std::make_unique<Bullet>(413, BULLET_SPRITE_HEIGHT);
    
    for(auto i = 0; i < 4; i++)
    {
        auto alien = std::make_shared<Aliens>((i * ALIEN_SPRITE_WIDTH) + i*ALIEN_SPRITE_SPACING, GAME_HEIGHT / 2); // x and y positions on screen
        aliens.push_back(alien);
    }
}

//void MainGameScreen::begin(sf::RenderWindow &window)
//{   
//    sf::Font font;
//    if (!font.loadFromFile("resources/sansation.ttf"))
//        return EXIT_FAILURE;
//        
//    // Initialize the pause message
//    sf::Text pauseMessage;
//    pauseMessage.setFont(font);
//    pauseMessage.setCharacterSize(40);
//    pauseMessage.setPosition(170.f, 150.f);
//    pauseMessage.setFillColor(sf::Color::Blue);
//    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");
//}

void MainGameScreen::loop(sf::RenderWindow &window)
{
    while (window.isOpen())
    {
        handleEvents(window); 
        update();
        render(window); 
    }
}

void MainGameScreen::handleEvents(sf::RenderWindow &window)
{
    sf::Event event;
    
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}

void MainGameScreen::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        player->moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        player->moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        player->moveUp();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        player->moveDown();
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {    
        bullet->shoot();
    }
    
    if(clock.getElapsedTime() >= bulletReferenceTimer)
    {    
        bullet->move();
        clock.restart();
    }
    
    if(bullet->isFired() == false)
    {
        bullet->reset(player->getX() + PLAYER_SPRITE_WIDTH/2, player->getY() + PLAYER_SPRITE_HEIGHT/2);
    }
    
    if(clock1.getElapsedTime() >= alienReferenceTimer)
    {    
        for(auto & alien : aliens)
        {
            alien -> move();
        }
                
        clock1.restart();
    }
}

void MainGameScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color(50, 200, 50));
    
    window.draw(bullet->bulletSprite());
    window.draw(player->playerSprite());
    
    for(auto & alien : aliens)
    {
        window.draw(alien -> alienSprite());
    }
    
    window.display();
}

void MainGameScreen::end(sf::RenderWindow &window)
{
    window.clear(sf::Color(50, 200, 50));
}