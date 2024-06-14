#pragma once
#include <vector>

class Entity {

public:
    Entity(int x, int y);
    ~Entity();
    virtual void update();
    virtual void draw();
    virtual void addE(Entity);

    //SDL_Rect rect;
    
    std::vector<Entity> list;

};