#include "textures.h"

sf::Texture BASIC_TILE_T;
sf::Texture PLACEHOLDER_GUY_T;

void loadTextures() {

    BASIC_TILE_T.loadFromFile("res/Basic_Tile.png");
    PLACEHOLDER_GUY_T.loadFromFile("res/playerWalk3.png");
}