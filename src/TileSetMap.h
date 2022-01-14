#ifndef PLATFORMER2D_TILESETMAP_H
#define PLATFORMER2D_TILESETMAP_H

#include <SFML/Graphics.hpp>
#include "rapidjson/include/rapidjson/document.h"

class TileSetMap {
public:
    TileSetMap(rapidjson::Value& value) {
        firstgid = value["firstgid"].GetInt();
        source = value["source"].GetString();
    }

    ~TileSetMap() {}

    int getFirstGId() { return firstgid; }
    std::string getSource() { return source; }
private:
    int firstgid;
    std::string source;
};


#endif //PLATFORMER2D_TILESETMAP_H
