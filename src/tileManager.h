#pragma once
#include "globals.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include "tile.h"

class TileManager {

private:
    // Tiles * These are all just made for the list, the positions don't matter.
    Tile rock = Tile(0, 0, 0);
    Tile lava = Tile(0, 0, 1, 0.0f, true, true);


public:
    TileManager();

    void draw(sf::RenderWindow *window);
    void update();

    std::vector<std::vector <Tile>> tiles;


};