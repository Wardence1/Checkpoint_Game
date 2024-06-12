#include "tile.h"

Tile::Tile(float x, float y, unsigned type, float slickness, bool deadly, bool solid, bool climbable) : 
x(x), y(y), type(type), slickness(slickness), deadly(deadly), solid(solid), climbable(climbable) {


    switch (type) {
        case 0: // Rock
            this->sprite.setTexture(BASIC_TILE_T);
            break;
        case 1: // Lava
            this->sprite.setTexture(BASIC_TILE_T);
            break;
        default:    
            std::cout << "Unsupported tile type chosen: " << type << "\n";
            exit(1);
    }

    int width = sprite.getTextureRect().width;

    this->sprite.setScale({TILESIZE/width, TILESIZE/width});
    sprite.setPosition({x, y});


}

void Tile::addTile(int x, int y) {

    tiles.push_back(Tile(x, y, type, slickness, deadly, solid, climbable));
}

void Tile::draw(sf::RenderWindow* window) {

    window->draw(sprite);
}