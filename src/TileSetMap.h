#ifndef PLATFORMER2D_TILESETMAP_H
#define PLATFORMER2D_TILESETMAP_H

#include <SFML/Graphics.hpp>
#include "rapidjson/include/rapidjson/document.h"
/**
 * @class TileSetMap - klasa która ustawia kafelki na mape
 */
class TileSetMap {
public:
    /***
     * Metoda która ustawia zmienne kafelków z pobranych wartości json
     * @param value - wartości pobrane z json
     */
    TileSetMap(rapidjson::Value& value) {
        firstgid = value["firstgid"].GetInt();
        source = value["source"].GetString();
    }
    ///Destruktor kafelków mapy
    ~TileSetMap() {}
    /***
     * Metoda która zwraca informacje o pierwszy globalny identyfikator kafelka wybranego zestawu
     * @return zwraca liczbe która reprezentuje id pierwszego kafelka w danym zestawie
     */
    int getFirstGId() { return firstgid; }
    /***
     * Metoda która zwraca informacje ścieżke do pliku w którym przechowywanym jest zestaw kafelków
     * @return zwraca ścieżke do zestawu kafelków
     */
    std::string getSource() { return source; }
private:
    ///Zmienna reprezentująca pierwszy globalny identyfikator kafelka tego zestawu kafelków
    int firstgid;
    ///Zmienna przechowująca ścieżke do zestawu kafelków
    std::string source;
};


#endif //PLATFORMER2D_TILESETMAP_H
