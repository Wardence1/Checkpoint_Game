#pragma once

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int FPS;
extern const float GRAVITY;
extern const int TILESROW;
extern const float TILESIZE;
extern const int TILESCOLUMN;
extern const char *GAME_TITLE;
extern const float PLAYER_WIDTH;
extern const float PLAYER_HEIGHT;

enum GameState {
    START_MENU,
    RUNNING,
    PAUSED
};

enum Maps {
    MAP1,
    MAP2,
    MAP3,
    MAP4,
    MAP5
};

extern Maps& operator++(Maps& map);


extern Maps mapNum;