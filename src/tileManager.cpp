#include "tileManager.h"

TileManager::TileManager() {

    for (int i=0; i<5; i++)
        rock.addTile(TILESIZE*5, SCREEN_HEIGHT-TILESIZE*i);

    rock.addTile(SCREEN_WIDTH/2, SCREEN_HEIGHT-TILESIZE*4);

    rock.addTile(TILESIZE*2, SCREEN_HEIGHT-(TILESIZE*3));

    rock.addTile(TILESIZE*4, SCREEN_HEIGHT-TILESIZE*2);

    rock.addTile(TILESIZE*12, SCREEN_HEIGHT-(TILESCOLUMN-6)*TILESIZE);

/////////////////////////////////////////////////////////////////////////////////////

    this->tiles.push_back(rock.tiles); // 0
    this->tiles.push_back(lava.tiles); // 1


    // See which tiles are next to which
    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++)
            for (int k=0; k<tiles.size(); k++)
                for (int l=0; l<tiles[k].size(); l++) {

                    // Below
                    if (tiles[i][j].y + TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x) {
                        tiles[i][j].tileBelow = true;
                    }
                    // Above
                    if (tiles[i][j].y - TILESIZE == tiles[k][l].y && tiles[i][j].x == tiles[k][l].x) {
                        tiles[i][j].tileAbove = true;
                    }
                }
}

void TileManager::draw(sf::RenderWindow* window) {

    for (int i=0; i<tiles.size(); i++)
        for (int j=0; j<tiles[i].size(); j++)
            window->draw(tiles[i][j].sprite);
}

void TileManager::update() {

}
