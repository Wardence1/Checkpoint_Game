#include "zombie.h"
#include <SFML/Graphics.hpp>

Zombie::Zombie(int x, int y) : Entity(x, y) {

    sf::Texture up1, up2, up3, down1, down2, down3, left1, left2, left3, right1, right2, right3;
    bool status;

    /*status = up1.loadFromFile("df");
    status = up2.loadFromFile("23");
    status = up3.loadFromFile("23");
    status = down1.loadFromFile("23");
    status = down2.loadFromFile("23");
    status = down3.loadFromFile("23");
    status = left1.loadFromFile("23");
    status = left2.loadFromFile("23");
    status = left3.loadFromFile("23");
    status = right1.loadFromFile("23");
    status = right2.loadFromFile("23");
    status = right3.loadFromFile("23");*/
    status = true; // Temporary

    if (!status) {
        std::cout << "Couldn't load a texture for the Zombie.\n";
        exit(-1);
    }
        
}

void Zombie::update() {

    for (Entity e : list) {
        // Update logic
    }

}

void Zombie::draw() {

    for (Entity e : list) {
        // Draw Logic
    }
}
