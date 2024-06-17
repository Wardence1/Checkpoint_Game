#pragma once
#include <vector>
#include "textures.h"
#include <SFML/Graphics.hpp>

class Object {

public:
    Object();
    virtual void update();

    int x, y, type;

};