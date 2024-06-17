#pragma once
#include "object.h"
#include "player.h"

class Key : Object {

public:
    Key(int type, float x, float y);
    void update(Player* p);
    virtual void addO(float x, float y);
    sf::Sprite sprite;
    float scaleWidth, scaleHeight;
    float width, height;
    float x, y;
    int moveTimer=0;
    bool goingUp=false;
    std::vector<Key> list;
};