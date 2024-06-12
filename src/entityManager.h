#pragma once
#include "entity.h"
#include "zombie.h"
#include <SFML/Graphics.hpp>
#include <vector>

class EntityManager {

public:

    void draw(sf::RenderWindow* window);
    void update();

    // Entities
    Zombie zombie = Zombie(20, 20);

};