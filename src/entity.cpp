#include "entity.h"

Entity::Entity(int x, int y) {

    //this->rect.x = x;
    //this->rect.y = y;
}

Entity::~Entity() {

    
}

void Entity::update() {


}

void Entity::draw() {


}

void Entity::addE(Entity e) {

    Entity::list.push_back(e);
}

