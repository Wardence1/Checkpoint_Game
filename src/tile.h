#pragma once
#include <SFML/Graphics.hpp>
#include "globals.h"
#include "textures.h"
#include <iostream>

class Tile {

public:
    Tile(float x, float y, unsigned type, float slickness=0, bool deadly=false, bool solid=true, bool climbable=false, bool breakable=false);
    void deleteT();


    float x, y, slickness;
    bool deadly, solid, climbable, breakable;
    bool tileBelow = false, tileAbove=false, tileLeft=false, tileRight=false;
    unsigned type;

    sf::Sprite sprite;
    std::string filePath;
    std::vector<Tile> tiles;


    void addTile(int x, int y);
    void draw(sf::RenderWindow* window);

};