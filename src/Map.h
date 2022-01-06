//
// Created by ToQly on 27.11.2021.
//

#ifndef PLATFORMER2D_MAP_H
#define PLATFORMER2D_MAP_H

#include <SFML/Graphics.hpp>
#include "Layer.h"
#include "TileSetMap.h"
#include <string>
#include <fstream>
#include "rapidjson/include/rapidjson/ostreamwrapper.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/istreamwrapper.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/ostreamwrapper.h"
class Map {
public:
    Map(std::string mapa);
    ~Map();

    int getHeight() { return height; }
    bool isInfinite() { return infinite; }
    std::vector<Layer> getLayers(){ return layers; }
    int getNextLayerId() { return nextlayerid; }
    int getNextObjectId() { return nextobjectid; }
    std::string getOrientation() { return orientation; }
    std::string getRenderOrder() { return renderorder; }
    std::string getTiledVersion(){ return tiledversion; }
    int getTileHeight() { return tileheight; }
    std::vector<TileSetMap> getTileSetMap() { return tilesets; }
    int getTileWidth() { return tilewidth; }
    std::string getType() { return type; }
    float getVersion() { return version; }
    int getWidth() { return width; }

private:
    int height;
    bool infinite;
    std::vector<Layer> layers;
    int nextlayerid;
    int nextobjectid;
    std::string orientation;
    std::string renderorder;
    std::string tiledversion;
    int tileheight;
    std::vector<TileSetMap> tilesets;
    int tilewidth;
    std::string type;
    float version;
    int width;
};


#endif //PLATFORMER2D_MAP_H
