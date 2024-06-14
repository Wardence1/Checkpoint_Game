#include "textures.h"

sf::Texture BASIC_TILE_T;
sf::Texture LAVA_TILE_T;
sf::Texture BREAKABLE_TILE_T;
sf::Texture SPAWNER_TILE_T;
sf::Texture PLACEHOLDER_GUY_T;

void loadTextures() {

    BASIC_TILE_T.loadFromFile("res/Basic_Tile.png");
    LAVA_TILE_T.loadFromFile("res/lava_tile.png");
    BREAKABLE_TILE_T.loadFromFile("res/breakable_tile.png");
    SPAWNER_TILE_T.loadFromFile("res/spawner_tile.png");
    PLACEHOLDER_GUY_T.loadFromFile("res/playerWalk3.png");
}