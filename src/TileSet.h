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
    /***
     * Konstruktor który przyjmuje numer kafelka i jego tileset a nastepnie go parsuje
     * @param firstgid - pierwszy globalny identyfikator kafelka tego zestawu kafelków
     * @param tileset - zestaw kafelków
     */
    TileSet(int firstgid, std::ifstream  tileset);
    ///Destruktor
    ~TileSet();

    /***
     * Metoda która zwraca informacje o pierwszy globalny identyfikator kafelka wybranego zestawu
     * @return zwraca liczbe która reprezentuje id pierwszego kafelka w danym zestawie
     */
    int getFirstGid() { return firstgid; }
    /***
     * Zwraca numer kolumny
     * @return zwraca liczbe, która reprezentuje liczbe kolumn kafelków w danym zestawie
     */
    int getColumns() { return columns; }
    /***
     * Zwraca informacje o obrazku kafelka
     * @return zwraca tekst, który reprezentuje ścieżke do obrazka dla kafelka
     */
    std::string getImage() { return image; }
    /***
     * Zwraca wysokosc obrazka kafelka
     * @return zwraca liczbe, która reprezentuje wysokość w pikselach dla obrazka kafelka
     */
    int getImageHeight() { return imageHeight; }
    /***
     * Zwraca szerokosc obrazka kafelka
     * @return zwraca liczbe, która reprezentuje szerokosc w pikselach dla obrazka kafelka
     */
    int getImageWidth() { return imageWidth; }
    /***
     * Zwraca margines
     * @return zwraca liczbe, która reprezentuje margines w tym zestawie kafelków
     */
    int getMargin() { return margin; }
    /***
     * Zwraca nazwe
     * @return zwraca tekst, który reprezentuje nazwe tego zestawu kafelka
     */
    std::string getName() { return name; }
    /***
     * Zwraca odstep
     * @return zwraca liczbę, która reprezentuje odstęp w pikselach między kafelkami w tym zestawie
     */
    int getSpacing() { return spacing; }
    /***
     * Zwraca ilosc kafelkow
     * @return zwraca liczbe, która reprezentuje ilość kafelków w tym zestawie
     */
    int getTileCount(){ return tilecount; }
    /***
     * Zwraca informacje o wersji kafelka
     * @return zwraca tekst, który reprezentuje wersję w której został zapisany kafelek
     */
    std::string getTiledVersion() { return tiledversion; }
    /***
     * Zwraca wysokosc kafelka
     * @return zwraca liczba która reprezentuje wysokość kafelka
     */
    int getTileHeight() { return tileheight; }
    /***
     * Zwraca szerokosc kafelka
     * @return zwraca liczbę która reprezentuje szerokość kafelka
     */
    int getTileWidth() { return tilewidth; }
    /***
     * Zwraca typ
     * @return zwraca tekst, który reprezentuje typ
     */
    std::string getType() { return type; }
    /***
     * Zwraca numer wersji na której został stworzony kafelek
     * @return zwraca liczbę float, która reprezentuje wersję w której został stworzony kafelek
     */
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
