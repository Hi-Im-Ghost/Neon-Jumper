//
// Created by ToQly on 27.11.2021.
//

#ifndef PLATFORMER2D_TILESET_H
#define PLATFORMER2D_TILESET_H

#include <string>
#include "rapidjson/include/rapidjson/document.h"

class TileSet {
public:
    TileSet() {}
    TileSet(int firstgid, std::ifstream  tileset);
    ~TileSet();

    int getFirstGid() { return firstgid; }
    int getColumns() { return columns; }
    std::string getImage() { return image; }
    int getImageHeight() { return imageHeight; }
    int getImageWidth() { return imageWidth; }
    int getMargin() { return margin; }
    std::string getName() { return name; }
    int getSpacing() { return spacing; }
    int getTileCount(){ return tilecount; }
    std::string getTiledVersion() { return tiledversion; }
    int getTileHeight() { return tileheight; }
    int getTileWidth() { return tilewidth; }
    std::string getType() { return type; }
    float getVersion() { return version; }

private:
    int firstgid;
    int columns;
    std::string image;
    int imageHeight;
    int imageWidth;
    int margin;
    std::string name;
    int spacing;
    int tilecount;
    std::string tiledversion;
    int tileheight;
    int tilewidth;
    std::string type;
    float version;
};


#endif //PLATFORMER2D_TILESET_H
