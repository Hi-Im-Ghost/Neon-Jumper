#ifndef PLATFORMER2D_TILESET_H
#define PLATFORMER2D_TILESET_H

#include <string>
#include "rapidjson/include/rapidjson/document.h"
/**
 * @class Klasa służaca do pobrania informacji dotyczacych kafeków
 */
class TileSet {
public:
    ///Konstruktor pusty
    TileSet() {}
    ///Konstruktor który przyjmuje numer kafelka i jego tileset a nastepnie go parsuje
    TileSet(int firstgid, std::ifstream  tileset);
    ///Destruktor
    ~TileSet();

    ///Zwraca numer kafelka
    int getFirstGid() { return firstgid; }
    ///Zwraca numer kolumny
    int getColumns() { return columns; }
    ///Zwraca informacje o obrazku kafelka
    std::string getImage() { return image; }
    ///Zwraca wysokosc obrazka kafelka
    int getImageHeight() { return imageHeight; }
    ///Zwraca szerokosc obrazka kafelka
    int getImageWidth() { return imageWidth; }
    ///Zwraca margines
    int getMargin() { return margin; }
    ///Zwraca nazwe
    std::string getName() { return name; }
    ///Zwraca odstep
    int getSpacing() { return spacing; }
    ///Zwraca ilosc kafelkow
    int getTileCount(){ return tilecount; }
    ///Zwraca informacje o wersji kafelka
    std::string getTiledVersion() { return tiledversion; }
    ///Zwraca wysokosc kafelka
    int getTileHeight() { return tileheight; }
    ///Zwraca szerokosc kafelka
    int getTileWidth() { return tilewidth; }
    ///Zwraca typ
    std::string getType() { return type; }
    ///Zwraca numer wersji na której został stworzony kafelek
    float getVersion() { return version; }

private:
    ///Zmienna przechowująca numer kafelka
    int firstgid;
    ///Zmienna przechowujaca numer kolumny
    int columns;
    ///Zmienna przechowujaca sciezke do obrazka dla kafelka
    std::string image;
    ///Zmienna przechowujaca wysokosc obrazka kafelka
    int imageHeight;
    ///Zmienna przechowujaca szerokosc obrazka kafelka
    int imageWidth;
    ///Zmienna przechowujaca margines
    int margin;
    ///Zmienna przechowujaca nazwe
    std::string name;
    ///Zmienna przechowujaca odstep
    int spacing;
    ///Zmienna przechowuajca ilosc kafelkow
    int tilecount;
    ///Zmienna przechowujaca informacje o wersji kafelka
    std::string tiledversion;
    ///Zmienna przechowujaca wysokosc kafelka
    int tileheight;
    ///Zmienna przechowujaca szerokosc kafelka
    int tilewidth;
    ///Zmienna przechowujaca inofrmacje o typie
    std::string type;
    ///Zmienna przechowujca inforamcje o wersji na ktorej zostal stworzony kafelek
    float version;
};


#endif //PLATFORMER2D_TILESET_H
