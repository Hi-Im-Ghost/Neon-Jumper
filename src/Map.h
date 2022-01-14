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
/**
 * @class Klasa służy do pobrania informacji o mapie z pliku json
 */
class Map {
public:
    ///Konstruktor który parsuje przekazana w parametrze mape
    Map(std::string mapa);
    ///Destruktor
    ~Map();

    ///Zwraca wysokość
    int getHeight() { return height; }
    ///Sprawdza czy wystepuje niesokonczoność
    bool isInfinite() { return infinite; }
    ///Zwraca poszczególne warstwy
    std::vector<Layer> getLayers(){ return layers; }
    ///Zwaraca nastepne id warstwy
    int getNextLayerId() { return nextlayerid; }
    ///Zwraca nastepny id obiektu
    int getNextObjectId() { return nextobjectid; }
    ///Zwraca informacje o orientacji
    std::string getOrientation() { return orientation; }
    ///Zwraca informacje o renderowaniu
    std::string getRenderOrder() { return renderorder; }
    ///Zwraca informacje o wersji
    std::string getTiledVersion(){ return tiledversion; }
    ///Zwraca informacje o wysokosci kafelka
    int getTileHeight() { return tileheight; }
    ///Zwraca kafelki mapy
    std::vector<TileSetMap> getTileSetMap() { return tilesets; }
    ///Zwraca szerokosc kafelka
    int getTileWidth() { return tilewidth; }
    ///Zwraca informacje o typie
    std::string getType() { return type; }
    ///Zwraca informacje o uzytej wersji zapisu
    float getVersion() { return version; }
    ///Zwraca szerokość
    int getWidth() { return width; }

private:
    ///Zmienna do wysokości
    int height;
    ///Zmienna określjąca czy jest nieskończoność
    bool infinite;
    ///Zmienna przechowująca warstwy
    std::vector<Layer> layers;
    ///Zmienna przechowująca id następnej warstwy
    int nextlayerid;
    ///Zmienna przechowująca id nastepnego obiektu
    int nextobjectid;
    ///Zmienna przechowująca informacje o orientacji na mapie
    std::string orientation;
    ///Zmienna przechowująca informacje o renderowaniu
    std::string renderorder;
    ///Zmienna przechowująca informacje o wersji
    std::string tiledversion;
    ///Zmienna przechowująca informacje o wysokości kafelka
    int tileheight;
    ///Zmienna przechowują kafleki
    std::vector<TileSetMap> tilesets;
    ///Zmienna przechowujaca informacje o szerokości kafelka
    int tilewidth;
    ///Zmienna przechowująca informacje o typie
    std::string type;
    ///Zmienna przechowujaca informacje o wersji zapisu
    float version;
    ///Zmienna przechowujaca informacje o szerokosci
    int width;
};


#endif //PLATFORMER2D_MAP_H
