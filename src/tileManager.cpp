#include "tileManager.h"

TileManager::TileManager() {


}

void TileManager::draw(sf::RenderWindow* window) {

    //std::cout << tiles[3].size() << "\n";
    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++) {
            window->draw(tiles[i][j].sprite);
        }
            
}


void TileManager::loadMap(int type, Player* p/*, bool alreadyLoaded*/) {

    bool spawnPointSet = false;
    p->hasKey = false;
    
    int tempMap[11][20];

    // Clears previous map
    for (int i=0; i<tiles.size(); i++) {
            tiles[i].clear();
    }

    
            

    rock.tiles.clear();
    lava.tiles.clear();
    breakable.tiles.clear();
    lockedDoor.tiles.clear();
    spawner.tiles.clear();
    oManager.key.list.clear();
    

    for (int i=0; i<TILESCOLUMN; i++)
        for (int j=0; j<TILESROW; j++)
            switch (type) { // Which Map?
                    case 0:
                        tempMap[i][j] = map1[i][j];
                        break;
                    case 1:
                        tempMap[i][j] = map2[i][j];
                        break;
                    default:
                        std::cout << "Map type chosen not valid.\n";
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
                case 4: // Locked Door
                        lockedDoor.addTile(j*TILESIZE, i*TILESIZE);
                    break;
                case 8: // Key
                    oManager.key.addO((j*TILESIZE)+((TILESIZE/2)-(oManager.key.width/4)), (i*TILESIZE)+((TILESIZE/2)-oManager.key.height/2));
                    break;
                case 9: // Spawn Point
                    spawner.addTile(j*TILESIZE, i*TILESIZE);
                    p->spawnPoint.x = (j*TILESIZE) + ((TILESIZE/2)-(PLAYER_WIDTH/2));
                    p->spawnPoint.y = (i*TILESIZE);
                    p->x = p->spawnPoint.x;
                    p->y = p->spawnPoint.y;
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
    this->tiles.push_back(lockedDoor.tiles); // 4
    this->tiles.push_back(spawner.tiles); // 9
    
    //if (alreadyLoaded) { // This is what I had to do to fix the stupid locked door issue where the door would't open if you reset because it wan't in the array for the lockedDoor. Even though it was drawing to the screen perfectly fine. I tried many many things to try and fix it and none of them worked. So I had to do this.
        //for (int i=0; i<tiles[3].size(); i++)
        //    tiles[3][i].sprite.setScale(TILESIZE/tiles[3][i].width, TILESIZE/tiles[3][i].width);
   // }

    checkTiles();
}


void TileManager::checkTiles() {

    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++)
            for (int k=0; k<tiles.size(); k++)
                for (int l=0; l<tiles[k].size(); l++) {

                    // Below
                    if (tiles[i][j].y + TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[i][j].solid && !tiles[k][l].breakable || tiles[i][j].y+TILESIZE == SCREEN_HEIGHT) {
                        tiles[i][j].tileBelow = true;
                    }
                    // Above
                    if (tiles[i][j].y - TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[k][l].solid && !tiles[k][l].breakable || tiles[i][j].y == 0) {
                        tiles[i][j].tileAbove = true;
                    }
                    // Right
                    if (tiles[i][j].x + TILESIZE == tiles[k][l].x && tiles[i][j].y == tiles[k][l].y && tiles[k][l].solid && !tiles[k][l].breakable || tiles[i][j].x+TILESIZE == SCREEN_WIDTH) {
                        tiles[i][j].tileRight = true;
                    }
                    // Left
                    if (tiles[i][j].x - TILESIZE == tiles[k][l].x && tiles[i][j].y == tiles[k][l].y && tiles[k][l].solid && !tiles[k][l].breakable || tiles[i][j].x == 0) {
                        tiles[i][j].tileLeft = true;
                    }

                    // Setting textures

                    // Rock
                    #pragma region 
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
                        else if (tiles[i][j].tileBelow && tiles[i][j].tileAbove && !tiles[i][j].tileLeft && !tiles[i][j].tileRight) // Left - Right
                                tiles[i][j].sprite.setTexture(ROCK_LEFT_RIGHT_T);

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
                        
                        #pragma endregion

                    }
                }
}


