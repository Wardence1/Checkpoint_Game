#include "game.h"
#include <iostream>


void Game::start() {
    loadTextures();

    this->running = true;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE, sf::Style::Close);
    window.setPosition({(int)(sf::VideoMode::getDesktopMode().width/2)-SCREEN_WIDTH/2, (int)(sf::VideoMode::getDesktopMode().height/2)-SCREEN_HEIGHT/2});
    window.setFramerateLimit(FPS);
    sf::Event event;

    EntityManager eManager = EntityManager();
    TileManager tManager = TileManager();
    Player player = Player(SCREEN_WIDTH/2, 20.0f);

    while (running) {
        
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) {
                window.close();
                running = false;
                break;
            }


        // Update
        player.update(tManager);
        tManager.update();
        eManager.update();

        // Render
        window.clear({85, 85, 85, 0});

        tManager.draw(&window);
        eManager.draw(&window);
        player.draw(&window);

        window.display();
    }
}
