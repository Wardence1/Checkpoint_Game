#include "entityManager.h"



void EntityManager::update() {

    zombie.update();
}

void EntityManager::draw(sf::RenderWindow* window) {

    zombie.draw();
}

