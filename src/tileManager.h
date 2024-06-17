#pragma once
#include "globals.h"
#include "SFML/Graphics.hpp"
#include <vector>
#include "player.h"
#include "textures.h"
#include <iostream>
#include "objectManager.h"
#include "tile.h"
#include "object.h"
#include "key.h"

class TileManager {

public:
    // Tiles * These are all just made for the list, the positions don't matter.
    Tile rock = Tile(0, 0, 1);
    Tile lava = Tile(0, 0, 2, 0.0f, true, false);
    Tile breakable = Tile(0, 0, 3, 0.0f, false, true, false, true);
    Tile lockedDoor = Tile(0, 0, 4, 0.0f, false, true, false, true);
    Tile spawner = Tile(0, 0, 9, 0.0, false, false); // The player is automatically put here and the save point is saved when the map itself has loaded.


public:
    TileManager();

    void draw(sf::RenderWindow *window);

    void loadMap(int type, Player* p/*, bool alreadyLoaded=false*/);
    void checkTiles(); // Checks to see if tiles sides are covered to prevent physics errors.
    ObjectManager oManager = ObjectManager();

    std::vector<std::vector <Tile>> tiles;


private:
    // 220 is the max tile in a row(20) times the max tiles in a column(11) and the Bottom off placed on top.

    /*
    1: Rock
    2: Lava
    3: Breakable
    4: Locked Door
    8: Key
    9: Spawner
    */


    int map1[11][20] = {{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                        {1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1},
                        {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
                        {1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
                        {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
                        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

    int map2[11][20] = {{1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
                        {1,1,1,0,0,0,1,1,0,0,0,1,1,3,3,1,1,1,1,1},
                        {1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
                        {1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
                        {1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
                        {1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1}};


                        // Template
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        //  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
                        

};