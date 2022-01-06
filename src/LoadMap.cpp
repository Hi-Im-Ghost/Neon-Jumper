//
// Created by R2-D2 on 29.12.2021.
//

#include "LoadMap.h"
#include "Entities/Player.h"
#include <iostream>


std::ifstream LoadMap::readFile(std::string path) {
    std::ifstream ifs;
    ifs.open(path,std::ios::binary);
    if ( !ifs.is_open() )
    {
        std::cerr << "Could not open file for reading!\n";
    }
    return ifs;
}

TileSet LoadMap::findTileSet(Layer& layer, std::vector<TileSet>& tilesets) {
    for (auto d : layer.getData()) {
        if (d != 0) {
            for (auto& t : tilesets) {
                if (d >= t.getFirstGid()) {
                    return t;
                }
            }
        }
    }
}

LoadMap::LoadMap(std::string mapFileName){

    Map map(mapFileName);
    std::vector<TileSet> tilesets;
    std::vector<TileSetMap> tilesetMaps = map.getTileSetMap();

    for (size_t i = 0; i < tilesetMaps.size(); i++) {
        std::string file = tilesetMaps[i].getSource();
        file = file.substr(0, file.size());
        TileSet tileset(tilesetMaps[i].getFirstGId(), readFile(file));
        tilesets.push_back(tileset);
    }

    std::vector<Layer> layers = map.getLayers();

    for (auto & l : layers)
    {
        if (l.getName() == "solid") {
            solidLayer = l;
        }
    }

    for (auto & l : layers)
    {
        if (l.getName() == "weater") {
            solidLayer = l;
        }
    }

    for (auto & l : layers)
    {
        if (l.getName() == "dmg") {
            damageLayer = l;
        }
    }

    std::vector<sf::Texture> textures;

    for (size_t i = 0; i < layers.size(); i++) {
        if (layers[i].getType() == "tilelayer") {
            tilemap_render.push_back(TileMap());
            tilemap_render.back().load(findTileSet(layers[i], tilesets), layers[i]);
        } else if (layers[i].getType() == "imagelayer") {
            bg.loadFromFile(layers[i].getImage());
        }
    }
    bgSpr.setTexture(bg);

    for (auto & t : tilemap_render) {
        t.setScale({3.0f, 3.0f});
    }
}

void LoadMap::draw(sf::RenderTarget &window) {
    window.draw(bgSpr);
    for (auto & t : tilemap_render)
        window.draw(t);
}

Layer LoadMap::getSolidLayer() {
    return solidLayer;
}
Layer LoadMap::getDamageLayer() {
    return damageLayer;
}
