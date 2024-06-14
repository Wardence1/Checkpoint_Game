#include "player.h"

Player::Player(TileManager tileM) {

    this->scale = 3.0f;
    
    this->sprite.setPosition({x, y});
    this->sprite.setTexture(PLACEHOLDER_GUY_T);
    this->sprite.scale({3, 3});

    // Default spawn point
    if (tileM.spawnPoint.x == 0 && tileM.spawnPoint.y == 0) {
        tileM.spawnPoint.x = (SCREEN_WIDTH/2)-(PLAYER_WIDTH/2);
        tileM.spawnPoint.y = (SCREEN_HEIGHT/2)-(PLAYER_HEIGHT/2);
    }

    this->x = tileM.spawnPoint.x;
    this->y = tileM.spawnPoint.y;
}

void Player::update(TileManager* tileM) {
    

    yVol += GRAVITY;

    // Controls
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->xVol += -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->xVol += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && grounded) {
        
        yVol = jumpStrength;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && grounded) {
        savePoint.x = x;
        savePoint.y = y;
        savePoint.saved = true;
        savePoint.ghost = sprite;
        savePoint.ghost.setColor({255, 255, 255, 60});
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        if (savePoint.saved) {
            x = savePoint.x;
            y = savePoint.y;
            savePoint.saved = false;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        x = tileM->spawnPoint.x;
        y = tileM->spawnPoint.y;
        savePoint.saved=false;
        tileM->loadMap(2);
    }

    grounded = false;


    // Collision with tiles
    sprite.setPosition(x+xVol, y+yVol); // Sets the position one frame ahead to calculate where you'll be then
    sf::FloatRect playerR = sprite.getGlobalBounds();

    // Goes through all tiles
    for (int i=0; i<tileM->tiles.size(); i++)
        for (int j=0; j<tileM->tiles[i].size(); j++) {

            // Collision
            if (playerR.intersects(tileM->tiles[i][j].sprite.getGlobalBounds())) {
                if (xVol>0 && y < tileM->tiles[i][j].y+TILESIZE && y > tileM->tiles[i][j].y - PLAYER_HEIGHT && tileM->tiles[i][j].solid) { // Right of player
                    x = (tileM->tiles[i][j].x-PLAYER_WIDTH);
                    xVol = 0;
                }
                else if (xVol<0 && y < tileM->tiles[i][j].y+TILESIZE && y > tileM->tiles[i][j].y - PLAYER_HEIGHT && tileM->tiles[i][j].solid) { // Left of player
                    x = tileM->tiles[i][j].x+TILESIZE;
                    xVol = 0;
                }
                else if (yVol>0 && y+PLAYER_HEIGHT <= tileM->tiles[i][j].y && !tileM->tiles[i][j].tileAbove && tileM->tiles[i][j].solid) { // Bottom of player
                    if (tileM->tiles[i][j].breakable && yVol > 25) {

                        tileM->tiles[i].erase(std::next(tileM->tiles[i].begin(), j));

                        for (int k=0; k < tileM->tiles[i].size(); k++) // Destroy all tiles the player is jumping onto.
                            if (playerR.intersects(tileM->tiles[i][k].sprite.getGlobalBounds()))
                                tileM->tiles[i].erase(std::next(tileM->tiles[i].begin(), k));

                        tileM->checkTiles();
                        yVol = 0;
                    }
                    else {
                        y = tileM->tiles[i][j].y-PLAYER_HEIGHT;
                        yVol = 0;
                        grounded = true;
                    }
                }
                else if (yVol<0 && y >= tileM->tiles[i][j].y && !tileM->tiles[i][j].tileBelow && tileM->tiles[i][j].solid) { // Top of player
                    y = tileM->tiles[i][j].y+TILESIZE;
                    yVol = 0;
                }
                if (tileM->tiles[i][j].deadly && y+PLAYER_HEIGHT > tileM->tiles[i][j].y) // Done so you can stand over the lava
                    dead(tileM);
            }
        }



    // Physics calculations

    if (yVol > 35) // Y speed cap
        yVol = 35;
    x+=xVol;
    y+=yVol;

    if (y+PLAYER_HEIGHT>=SCREEN_HEIGHT) {dead(tileM);} // Kills the player when the bottom of the screen is hit
    if (x <= 0) {x = 0; xVol=0;}
    if (x >= SCREEN_WIDTH-PLAYER_WIDTH) {x=SCREEN_WIDTH-PLAYER_WIDTH; xVol=0;}
    this->sprite.setPosition(this->x, this->y);
    xVol=0;
}


void Player::draw(sf::RenderWindow* window) {

    if (savePoint.saved)
        window->draw(savePoint.ghost);

    window->draw(sprite);

}   

void Player::dead(TileManager* tileM) {

    x=tileM->spawnPoint.x;
    y=tileM->spawnPoint.y;
    yVol=0;
    xVol=0;
    savePoint.saved=false;

}