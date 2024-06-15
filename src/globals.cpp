#include "globals.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = (SCREEN_WIDTH/(16.0f/9.0f))-15; // Ratio of the average screen * The -15 is there so there isn't a gap cause the tile size won't fit.
const int FPS = 60;
const float GRAVITY = 1.4f;


const int TILESROW = 20; // Amount of tiles that can fit on screen in a row at once
const float TILESIZE = SCREEN_WIDTH/TILESROW;
const int TILESCOLUMN = SCREEN_HEIGHT/TILESIZE; // * NOT EXACT * Amount of tiles that can fit on screen in a column at once

const float PLAYER_WIDTH = 30; // const float PLAYER_WIDTH = sprite.getTextureRect().width*scale;
const float PLAYER_HEIGHT = 30; // const float PLAYER_HEIGHT = sprite.getTextureRect().height*scale;


const char *GAME_TITLE = "Game";



