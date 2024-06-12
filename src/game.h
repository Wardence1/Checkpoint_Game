#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "globals.h"
#include "entityManager.h"
#include "tileManager.h"
#include "player.h"
#include "textures.h"

class Game {

public:

    void start();
    
    bool running;

};