#include "player.h"

Player::Player(float x, float y) {

    this->x = x;
    this->y = y;
    this->scale = 3.0f;

    
    this->sprite.setPosition({x, y});
    this->sprite.setTexture(PLACEHOLDER_GUY_T);
    this->sprite.scale({3, 3});

    width = sprite.getTextureRect().width*scale;
    height = sprite.getTextureRect().height*scale;
}

void Player::update(TileManager tileM) {
    
    yVol += GRAVITY;

    // Controls
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->xVol += -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->xVol += speed;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && grounded) {

        yVol = jumpStrength;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        savePoint.x = x;
        savePoint.y = y;
        savePoint.saved = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        if (savePoint.saved) {
            x = savePoint.x;
            y = savePoint.y;
            savePoint.saved = false;
        }
    }

    grounded = false;


    // Collision with tiles
    sprite.setPosition(x+xVol, y+yVol); // Sets the position one frame ahead to calculate where you'll be then
    sf::FloatRect playerR = sprite.getGlobalBounds();

    // Goes through all tiles
    for (int i=0; i<tileM.tiles.size(); i++)
        for (int j=0; j<tileM.tiles[i].size(); j++) {

            // Collision
            if (playerR.intersects(tileM.tiles[i][j].sprite.getGlobalBounds())) {
                if (xVol>0 && y < tileM.tiles[i][j].y+TILESIZE && y > tileM.tiles[i][j].y - height) { // Right of player
                    x = (tileM.tiles[i][j].x-width);
                    xVol = 0;
                }
                else if (xVol<0 && y < tileM.tiles[i][j].y+TILESIZE && y > tileM.tiles[i][j].y - height) { // Left of player
                    x = tileM.tiles[i][j].x+TILESIZE;
                    xVol = 0;
                }
                else if (yVol>0 && y+height <= tileM.tiles[i][j].y && !tileM.tiles[i][j].tileAbove) { // Bottom of player
                    y = tileM.tiles[i][j].y-height;
                    yVol = 0;
                    grounded = true;
                }
                else if (yVol<0 && !tileM.tiles[i][j].tileBelow) { // Top of player
                    y = tileM.tiles[i][j].y+TILESIZE;
                    yVol = 0;
                }
            }
        }



    // Physics calculations
    x+=xVol;
    y+=yVol;

    if (y+height>=SCREEN_HEIGHT) {y=SCREEN_HEIGHT-height; grounded = true; yVol=0;} // Makes sure you don't fall off the bottom
    this->sprite.setPosition(this->x, this->y);
    xVol=0;
}

void Player::draw(sf::RenderWindow* window) {

    window->draw(sprite);
}   