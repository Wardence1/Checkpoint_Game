#include "game.h"
#include <iostream>


void Game::start() {
    loadTextures();

    this->running = true;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), GAME_TITLE, sf::Style::Close);
    window.setPosition({(int)(sf::VideoMode::getDesktopMode().width/2)-SCREEN_WIDTH/2, (int)(sf::VideoMode::getDesktopMode().height/2)-SCREEN_HEIGHT/2});
    window.setFramerateLimit(FPS);
    sf::Event event;

    TileManager tManager = TileManager();
    Player player = Player();
    tManager.loadMap(mapNum, &player);
    while (running) {
        
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) {
                window.close();
                running = false;
                break;
            }


        // Update
        player.update(&tManager);
        tManager.oManager.update(&player);

        // Render
        window.clear({48, 25, 34, 0});

        tManager.draw(&window);
        tManager.oManager.draw(&window);
        player.draw(&window);

        window.display();
    }
}
