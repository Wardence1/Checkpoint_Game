#pragma once
#include "object.h"
#include <SFML/Graphics.hpp>
#include "key.h"
#include <vector>

class ObjectManager {

public:

    Key key = Key(8, -50, -50);

    ObjectManager();
    void draw(sf::RenderWindow* window);
    void update(Player* player);

};