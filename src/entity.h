#pragma once
#include <vector>

class Entity {

public:
    Entity(int x, int y);
    ~Entity();
    void update();
    void draw();
    void addE(Entity);

    //SDL_Rect rect;
    
    std::vector<Entity> list;

};