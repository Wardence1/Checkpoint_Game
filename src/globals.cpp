#include "globals.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = SCREEN_WIDTH/(16.0f/9.0f); // Ratio of the average screen
const int FPS = 60;
const float GRAVITY = 1.8f;


const int TILESROW = 20; // Amount of tiles that can fit on screen in a row at once
const float TILESIZE = SCREEN_WIDTH/TILESROW;
const int TILESCOLUMN = SCREEN_HEIGHT/TILESIZE; // * NOT EXACT * Amount of tiles that can fit on screen in a column at once
const float BOTTOMOFF = SCREEN_HEIGHT - (TILESCOLUMN*TILESIZE); // The amount of screen left when you place the most amount of tiles you can in a column onto it.


const char *GAME_TITLE = "Game";



