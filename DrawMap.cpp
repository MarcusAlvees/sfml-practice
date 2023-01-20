#include "Headers/DrawMap.hpp"
#include "Headers/Global.hpp"

DrawMap::DrawMap() {
    gridLength = 16;
    setUpTiles();
}

void DrawMap::initialState() {
}

void DrawMap::setUpTiles() {
    for(int x = 0; x < gridLength - 1; x++)
    {
        for (int y = 0; y < gridLength - 1; y++)
        {
            if(map[x][y] == 1){
                row.push_back(new GameTile("Resources/brick.png", CELL_SIZE * y, CELL_SIZE * x, true));
            }
        }  
    }   
}

void DrawMap::drawTiles(sf::RenderWindow& window) {
    for (int i = 0; i < row.size(); i++)
    {
        window.draw(row[i]->spr);
    }
}