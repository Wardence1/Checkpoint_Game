#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "tileManager.h"
#include "globals.h"
#include "textures.h"

class Player {
    
public:
    Player(float x, float y);
    float x, y, xVol=0, yVol=0, scale;
    float speed = 8;
    float jumpStrength = -30;
    float height, width;
    bool grounded = false;


    void update(TileManager tileM);
    void draw(sf::RenderWindow* window);

    struct {
        int x=0;
        int y=0;
        bool saved = false;
    } savePoint;

    sf::Sprite sprite;
};