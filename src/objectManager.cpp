#include "objectManager.h"

ObjectManager::ObjectManager() {


}

void ObjectManager::update(Player* player) {

    for (int i=0; i<key.list.size(); i++)
        key.list[i].update(player);
}

void ObjectManager::draw(sf::RenderWindow* window) {

    for (int i=0; i<key.list.size(); i++) {
        window->draw(key.list[i].sprite);
    }
}

