#pragma once
#include "entity.h"
#include <iostream>

class Zombie : public Entity{

public:

    Zombie(int x=0, int y=0);

    void update();
    void draw();
};
