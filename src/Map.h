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
 * @class Map - Klasa służy do pobrania informacji o mapie z pliku json
 */
class Map {
public:
    /***
     * Konstruktor który parsuje przekazana w parametrze mape
     * @param mapa - tekst, który reprezentuje nazwe pliku w którym przechowywana jest mapa
     */
    Map(std::string mapa);
    ///Destruktor
    ~Map();

    /***
     * Zwraca wysokość
     * @return zwraca liczbę, która reprezentuje wysokość mapy
     */
    int getHeight() { return height; }
    /***
     * Sprawdza czy wystepuje niesokonczoność
     * @return zwraca true jeśli mapa jest nieskończona lub false jeśli nie jest
     */
    bool isInfinite() { return infinite; }
    /***
     * Zwraca poszczególne warstwy
     * @return zwraca kolekcje vector, która przechowuje warstwy mapy
     */
    std::vector<Layer> getLayers(){ return layers; }
    /***
     * Zwaraca nastepne id warstwy
     * @return zwraca liczbe reprezentujacą id kolejnej warstwy mapy
     */
    int getNextLayerId() { return nextlayerid; }
    /***
     * Zwraca nastepny id obiektu
     * @return zwraca liczbę, która reprezentuje id kolejnego obiektu mapy
     */
    int getNextObjectId() { return nextobjectid; }
    /***
     * Zwraca informacje o orientacji mapy
     * @return zwraca tekst, który reprezentuje orientacje
     */
    std::string getOrientation() { return orientation; }
    /***
     * Zwraca informacje o renderowaniu
     * @return zwraca tekst, który informuje o kolejności renderowania obiektów na mapie
     */
    std::string getRenderOrder() { return renderorder; }
    /***
     * Zwraca informacje o wersji programu użytego do tworzenia mapy
     * @return zwraca tekst, który reprezentuje wersje programu
     */
    std::string getTiledVersion(){ return tiledversion; }
    /***
     * Zwraca informacje o wysokosci kafelka
     * @return zwraca liczbę, która reprezentuje wysokość kafelka
     */
    int getTileHeight() { return tileheight; }
    /***
     * Zwraca kafelki mapy
     * @return zwraca kolekcje vector, która przechowuje kafelki użyte na mapie
     */
    std::vector<TileSetMap> getTileSetMap() { return tilesets; }
    /***
     * Zwraca szerokosc kafelka
     * @return zwraca liczbę, która reprezentuje szerokość kafelka
     */
    int getTileWidth() { return tilewidth; }
    /***
     * Zwraca informacje o typie
     * @return zwraca tekst, który reprezentuje informacje o typie
     */
    std::string getType() { return type; }
    /***
     * Zwraca informacje o uzytej wersji zapisu
     * @return zwraca liczbę zmiennoprzecinkową, która reprezentuje wersję użytą do zapisu do pliku json
     */
    float getVersion() { return version; }
    /***
     * Zwraca szerokość
     * @return zwraca liczbę, która reprezentuje szerokość mapy
     */
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
