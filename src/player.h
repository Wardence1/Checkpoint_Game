#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "globals.h"
#include "textures.h"

class TileManager;

class Player {
    
public:
    Player();
    float x, y, xVol=0, yVol=0;
    float speed = 8;
    float jumpStrength = -22;
    bool grounded = false, hasKey = false;


    void update(TileManager* tileM);
    void draw(sf::RenderWindow* window);
    void dead(TileManager* tileM);

    struct {
        float x=0;
        float y=0;
        bool saved = false;
        sf::Sprite ghost;
    } savePoint;

    struct {
        float x=0;
        float y=0;
    } spawnPoint;


    sf::Sprite sprite;
};