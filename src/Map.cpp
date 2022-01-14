#include <iostream>
#include "Map.h"

Map::Map(std::string mapa) {
    rapidjson::Document mapDoc;

    std::ifstream ifs;
    ifs.open("../map/"+mapa,std::ios::binary);
    if ( !ifs.is_open() )
    {
        std::cerr << "Could not open file for reading!\n";
        return;
    }
    rapidjson::IStreamWrapper isw { ifs };
    mapDoc.ParseStream(isw);

    if ( mapDoc.HasParseError() )
    {
        std::cout << "Error  : " << mapDoc.GetParseError()  << '\n'
                  << "Offset : " << mapDoc.GetErrorOffset() << '\n';
    }

    height = mapDoc["height"].GetInt();
    infinite = mapDoc["infinite"].GetBool();

    rapidjson::Value::Array layersA = mapDoc["layers"].GetArray();
    for (size_t i = 0; i < layersA.Capacity(); i++) {
        Layer layer(layersA[i]);
        layers.push_back(layer);
    }

    std::reverse(layers.begin(), layers.end());

    nextlayerid = mapDoc["nextlayerid"].GetInt();
    nextobjectid = mapDoc["nextobjectid"].GetInt();
    orientation = mapDoc["orientation"].GetString();
    renderorder = mapDoc["renderorder"].GetString();
    tiledversion = mapDoc["tiledversion"].GetString();
    tileheight = mapDoc["tileheight"].GetInt();

    rapidjson::Value::Array tileSetArray = mapDoc["tilesets"].GetArray();
    for (size_t i = 0; i < tileSetArray.Capacity(); i++) {
        TileSetMap tileset(tileSetArray[i]);
        tilesets.push_back(tileset);
    }

    std::reverse(tilesets.begin(), tilesets.end());

    tilewidth = mapDoc["tilewidth"].GetInt();
    type = mapDoc["type"].GetString();
    version = mapDoc["version"].GetFloat();
    width = mapDoc["width"].GetInt();
    ifs.close();
    //delete[](map);
}

Map::~Map() = default;
