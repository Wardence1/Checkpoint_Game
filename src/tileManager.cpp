#include "tileManager.h"

TileManager::TileManager() {


}

void TileManager::draw(sf::RenderWindow* window) {

    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++)
            window->draw(tiles[i][j].sprite);
}


void TileManager::loadMap(int type) {

    bool spawnPointSet = false;
    int tempMap[11][20];

    // Clears previous map
    for (int i=0; i<tiles.size(); i++) 
        tiles[i].clear();

    rock.tiles.clear();
    lava.tiles.clear();
    breakable.tiles.clear();
    spawner.tiles.clear();

    for (int i=0; i<TILESCOLUMN; i++)
        for (int j=0; j<TILESROW; j++)
            switch (type) { // Which Map?
                    case 1:
                        tempMap[i][j] = map1[i][j];
                        break;
                    case 2:
                        tempMap[i][j] = map2[i][j];
                        break;
            }


    for (int i=0; i<TILESCOLUMN; i++) 
        for (int j=0; j<TILESROW; j++) {
            switch (tempMap[i][j]) { // Which Tile?
                case 0: // Air
                    break;
                case 1: // Rock
                    rock.addTile(j*TILESIZE, i*TILESIZE);
                    break;
                case 2: // Lava
                    lava.addTile(j*TILESIZE, i*TILESIZE);
                    break;
                case 3: // Breakable
                    breakable.addTile(j*TILESIZE, i*TILESIZE);
                    break;
                case 9: // Spawn Point
                    spawner.addTile(j*TILESIZE, i*TILESIZE);
                    spawnPoint.x = (j*TILESIZE) + ((TILESIZE/2)-(PLAYER_WIDTH/2));
                    spawnPoint.y = (i*TILESIZE);
                    if (spawnPointSet) std::cout << "Spawn point set twice.\n";
                    spawnPointSet = true;
                    break;
                default:
                    std::cout << "The tile number " << map1[i][j] << " is not valid\n";
                    break;
            }
        }

        if (!spawnPointSet)
            std::cout << "Spawn point not set.\n";


    this->tiles.push_back(rock.tiles); // 1
    this->tiles.push_back(lava.tiles); // 2
    this->tiles.push_back(breakable.tiles); // 3
    this->tiles.push_back(spawner.tiles); // 9

    checkTiles();
}


void TileManager::checkTiles() {

    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++)
            for (int k=0; k<tiles.size(); k++)
                for (int l=0; l<tiles[k].size(); l++) {

                    // Below
                    if (tiles[i][j].y + TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[i][j].solid || tiles[i][j].y+TILESIZE == SCREEN_HEIGHT) {
                        tiles[i][j].tileBelow = true;
                    }
                    // Above
                    if (tiles[i][j].y - TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[k][l].solid || tiles[i][j].y == 0) {
                        tiles[i][j].tileAbove = true;
                    }
                    // Right
                    if (tiles[i][j].x + TILESIZE == tiles[k][l].x && tiles[i][j].y == tiles[k][l].y && tiles[k][l].solid || tiles[i][j].x+TILESIZE == SCREEN_WIDTH) {
                        tiles[i][j].tileRight = true;
                    }
                    // Left
                    if (tiles[i][j].x - TILESIZE == tiles[k][l].x && tiles[i][j].y == tiles[k][l].y && tiles[k][l].solid || tiles[i][j].x == 0) {
                        tiles[i][j].tileLeft = true;
                    }

                    // Setting textures

                    // Rock
                    if (tiles[i][j].type == 1) {
                        if (tiles[i][j].tileAbove && tiles[i][j].tileLeft && tiles[i][j].tileRight && !tiles[i][j].tileBelow) // Bottom
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_T);
                        else if (tiles[i][j].tileBelow && tiles[i][j].tileLeft && tiles[i][j].tileRight && !tiles[i][j].tileAbove) // Top
                            tiles[i][j].sprite.setTexture(ROCK_TOP_T);
                        else if (tiles[i][j].tileAbove && tiles[i][j].tileBelow && tiles[i][j].tileRight && !tiles[i][j].tileLeft) // Left
                            tiles[i][j].sprite.setTexture(ROCK_LEFT_T);
                        else if (tiles[i][j].tileAbove && tiles[i][j].tileLeft && tiles[i][j].tileBelow && !tiles[i][j].tileRight) // Right
                            tiles[i][j].sprite.setTexture(ROCK_RIGHT_T);

                        else if (tiles[i][j].tileAbove && tiles[i][j].tileLeft && !tiles[i][j].tileBelow && !tiles[i][j].tileRight) // Bottom - Right
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_RIGHT_T);
                        else if (tiles[i][j].tileRight && tiles[i][j].tileAbove && !tiles[i][j].tileLeft && !tiles[i][j].tileBelow) // Bottom - Left
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_LEFT_T);
                        else if (tiles[i][j].tileRight && tiles[i][j].tileLeft && !tiles[i][j].tileAbove && !tiles[i][j].tileBelow) // Bottom - Top
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_TOP_T);
                        else if (tiles[i][j].tileBelow && tiles[i][j].tileLeft && !tiles[i][j].tileAbove && !tiles[i][j].tileRight) // Top - Right
                                tiles[i][j].sprite.setTexture(ROCK_TOP_RIGHT_T);
                        else if (tiles[i][j].tileBelow && tiles[i][j].tileRight && !tiles[i][j].tileLeft && !tiles[i][j].tileAbove) // Top - Right
                                tiles[i][j].sprite.setTexture(ROCK_TOP_LEFT_T);

                        else if (tiles[i][j].tileLeft && !tiles[i][j].tileRight && !tiles[i][j].tileBelow && !tiles[i][j].tileAbove) // Bottom - Right - Top
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_RIGHT_TOP_T);
                        else if (tiles[i][j].tileRight && !tiles[i][j].tileLeft && !tiles[i][j].tileBelow && !tiles[i][j].tileAbove) // Bottom - Left - Top
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_TOP_LEFT_T);
                        else if (tiles[i][j].tileAbove && !tiles[i][j].tileBelow && !tiles[i][j].tileRight && !tiles[i][j].tileLeft) // Bottom - Left - Right
                            tiles[i][j].sprite.setTexture(ROCK_BOTTOM_RIGHT_LEFT_T);
                        else if (tiles[i][j].tileBelow && !tiles[i][j].tileRight && !tiles[i][j].tileLeft && !tiles[i][j].tileAbove) // Top - Right - Left
                            tiles[i][j].sprite.setTexture(ROCK_RIGHT_TOP_LEFT_T);



                        else if (tiles[i][j].tileAbove && tiles[i][j].tileBelow && tiles[i][j].tileRight) // None
                            tiles[i][j].sprite.setTexture(ROCK_T);
                        else if (!tiles[i][j].tileAbove && !tiles[i][j].tileBelow && !tiles[i][j].tileRight && !tiles[i][j].tileLeft) // All
                            tiles[i][j].sprite.setTexture(ROCK_ALL_T);

                    }
                }
}


