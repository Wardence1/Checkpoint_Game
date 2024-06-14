#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tileManager.h"
#include "globals.h"
#include "textures.h"


class Player {
    
public:
    Player(TileManager tileM);
    float x, y, xVol=0, yVol=0, scale;
    float speed = 8;
    float jumpStrength = -22;
    bool grounded = false;


    void update(TileManager* tileM);
    void draw(sf::RenderWindow* window);
    void dead(TileManager* tileM);

    struct {
        float x=0;
        float y=0;
        bool saved = false;
        sf::Sprite ghost;
    } savePoint;


    sf::Sprite sprite;
};