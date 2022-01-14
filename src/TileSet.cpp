#include <fstream>
#include <iostream>
#include "TileSet.h"
#include "rapidjson/include/rapidjson/ostreamwrapper.h"
#include "rapidjson/include/rapidjson/document.h"
#include "rapidjson/include/rapidjson/istreamwrapper.h"
#include "rapidjson/include/rapidjson/writer.h"
#include "rapidjson/include/rapidjson/stringbuffer.h"
#include "rapidjson/include/rapidjson/ostreamwrapper.h"

TileSet::TileSet(int firstgid, std::ifstream tileset) {
    this->firstgid = firstgid;
    rapidjson::Document tilesetDoc;
    rapidjson::IStreamWrapper isw {tileset};
    tilesetDoc.ParseStream(isw);

    columns = tilesetDoc["columns"].GetInt();
    image = tilesetDoc["image"].GetString();
    imageHeight = tilesetDoc["imageheight"].GetInt();
    imageWidth = tilesetDoc["imagewidth"].GetInt();
    margin = tilesetDoc["margin"].GetInt();
    name = tilesetDoc["name"].GetString();
    spacing = tilesetDoc["spacing"].GetInt();
    tilecount = tilesetDoc["tilecount"].GetInt();
    tiledversion = tilesetDoc["tiledversion"].GetString();
    tileheight = tilesetDoc["tileheight"].GetInt();
    tilewidth = tilesetDoc["tilewidth"].GetInt();
    type = tilesetDoc["type"].GetString();
    version = tilesetDoc["version"].GetFloat();
    tileset.close();
    //delete[](tileset);
}

TileSet::~TileSet() = default;
