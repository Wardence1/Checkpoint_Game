#include "key.h"

Key::Key(int type, float x, float y) : x(x), y(y) {

    sprite.setTexture(KEY_T);
    this->type = type;
    sprite.setScale((scaleWidth = TILESIZE/sprite.getTextureRect().width)/2, scaleHeight = (TILESIZE/sprite.getTextureRect().height)/2);
    sprite.setPosition(x, y);
    width = sprite.getTextureRect().width*scaleWidth;
    height = sprite.getTextureRect().height*scaleHeight;
}

void Key::update(Player* p) {

    if (sprite.getGlobalBounds().intersects(p->sprite.getGlobalBounds())) {
        p->hasKey = true;
        sprite.scale(0, 0);
    }

    if (moveTimer % 9 == 0) {
        if (goingUp)
            y--;
        else
            y++;
        moveTimer++;
    }
    else if (moveTimer > 120) {
        moveTimer = 1;
        goingUp ? goingUp=false : goingUp=true;
    }
    else {
        moveTimer++;
    }

    sprite.setPosition(x, y);

}

void Key::addO(float x, float y) {

    list.push_back(Key(type, x, y));
}

