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
                    if (tiles[i][j].y + TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[i][j].solid) {
                        tiles[i][j].tileBelow = true;
                    }
                    // Above
                    if (tiles[i][j].y - TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x && tiles[k][l].solid) {
                        tiles[i][j].tileAbove = true;
                    }
                }
}


