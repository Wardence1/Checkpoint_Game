#include "textures.h"


sf::Texture ROCK_T;
sf::Texture ROCK_BOTTOM_T;
sf::Texture ROCK_BOTTOM_RIGHT_T;
sf::Texture ROCK_BOTTOM_LEFT_T;
sf::Texture ROCK_BOTTOM_TOP_T;
sf::Texture ROCK_BOTTOM_TOP_RIGHT_T;
sf::Texture ROCK_BOTTOM_TOP_LEFT_T;
sf::Texture ROCK_BOTTOM_RIGHT_TOP_T;
sf::Texture ROCK_BOTTOM_RIGHT_LEFT_T;
sf::Texture ROCK_RIGHT_TOP_LEFT_T;
sf::Texture ROCK_TOP_T;
sf::Texture ROCK_TOP_RIGHT_T;
sf::Texture ROCK_TOP_LEFT_T;
sf::Texture ROCK_LEFT_T;
sf::Texture ROCK_LEFT_RIGHT_T;
sf::Texture ROCK_RIGHT_T;
sf::Texture ROCK_ALL_T;

sf::Texture LAVA_TILE_T;
sf::Texture BREAKABLE_TILE_T;
sf::Texture SPAWNER_TILE_T;
sf::Texture PLACEHOLDER_GUY_T;

sf::Texture KEY_T;
sf::Texture LOCKED_DOOR_T;

void loadTextures() {

    ROCK_T.loadFromFile("res/tiles/rock/rock.png");
    ROCK_TOP_T.loadFromFile("res/tiles/rock/rock_top.png");
    ROCK_BOTTOM_T.loadFromFile("res/tiles/rock/rock_bottom.png");
    ROCK_BOTTOM_LEFT_T.loadFromFile("res/tiles/rock/rock_bottom_left.png");
    ROCK_BOTTOM_RIGHT_T.loadFromFile("res/tiles/rock/rock_bottom_right.png");
    ROCK_BOTTOM_RIGHT_TOP_T.loadFromFile("res/tiles/rock/rock_bottom_right_top.png");
    ROCK_TOP_LEFT_T.loadFromFile("res/tiles/rock/rock_top_left.png");
    ROCK_TOP_RIGHT_T.loadFromFile("res/tiles/rock/rock_top_right.png");
    ROCK_BOTTOM_TOP_T.loadFromFile("res/tiles/rock/rock_bottom_top.png");
    ROCK_BOTTOM_TOP_LEFT_T.loadFromFile("res/tiles/rock/rock_top_bottom_left.png");
    ROCK_BOTTOM_RIGHT_LEFT_T.loadFromFile("res/tiles/rock/rock_right_bottom_left.png");
    ROCK_RIGHT_TOP_LEFT_T.loadFromFile("res/tiles/rock/rock_right_top_left.png");
    ROCK_LEFT_RIGHT_T.loadFromFile("res/tiles/rock/rock_left_right.png");

    ROCK_LEFT_T.loadFromFile("res/tiles/rock/rock_left.png");
    ROCK_RIGHT_T.loadFromFile("res/tiles/rock/rock_right.png");

    ROCK_ALL_T.loadFromFile("res/tiles/rock/rock_bottom_top_left_right.png");

    LAVA_TILE_T.loadFromFile("res/tiles/lava_top.png");
    BREAKABLE_TILE_T.loadFromFile("res/tiles/breakable_tile.png");
    SPAWNER_TILE_T.loadFromFile("res/tiles/spawner_tile.png");
    PLACEHOLDER_GUY_T.loadFromFile("res/player.png");

    KEY_T.loadFromFile("res/key.png");
    LOCKED_DOOR_T.loadFromFile("res/tiles/lock_tile.png");
}