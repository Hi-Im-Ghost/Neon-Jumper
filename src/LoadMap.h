//
// Created by R2-D2 on 29.12.2021.
//

#ifndef TREES_JSON_LOADMAP_H
#define TREES_JSON_LOADMAP_H

#include "Map.h"
#include "TileSet.h"
#include "TileMap.h"
#include <iostream>
#include <string>

class LoadMap {
private:
    sf::Texture bg;
    sf::Sprite bgSpr;
    std::vector<TileMap> tilemap_render;

    Layer solidLayer;
    Layer damageLayer;

public:
    LoadMap(std::string mapFileName);
    std::ifstream readFile(std::string);
    TileSet findTileSet(Layer&, std::vector<TileSet>&);

    Layer getSolidLayer();
    Layer getDamageLayer();

    void draw(sf::RenderTarget& window);

};


#endif //TREES_JSON_LOADMAP_H
