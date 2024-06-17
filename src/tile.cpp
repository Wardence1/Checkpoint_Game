#include "tile.h"

Tile::Tile(float x, float y, unsigned type, float slickness, bool deadly, bool solid, bool climbable, bool breakable, bool bouncy) : 
x(x), y(y), type(type), slickness(slickness), deadly(deadly), solid(solid), climbable(climbable), breakable(breakable), bouncy(bouncy) {

    // Breakable just mean the tile could break at some point so tiles around it don't draw acting like it's there. So key doors would be breakable.

    switch (type) {
        case 1: // Rock
            this->sprite.setTexture(ROCK_T);
            break;
        case 2: // Lava
            this->sprite.setTexture(LAVA_TILE_T);
            break;
        case 3: // Breakable
            this->sprite.setTexture(BREAKABLE_TILE_T);
            break;
        case 4:
            this->sprite.setTexture(LOCKED_DOOR_T);
            break;
        case 9: // Spawn Point
            this->sprite.setTexture(SPAWNER_TILE_T);
            break;
        default:    
            std::cout << "Unsupported tile type chosen: " << type << "\n";
            exit(1);
    }

    width = sprite.getTextureRect().width;

    this->sprite.setScale({TILESIZE/width, TILESIZE/width});
    sprite.setPosition({x, y});


}

void Tile::addTile(int x, int y) {

    tiles.push_back(Tile(x, y, type, slickness, deadly, solid, climbable, breakable));
}

void Tile::draw(sf::RenderWindow* window) {

    window->draw(sprite);
}

void Tile::deleteT() {

    delete this;
}