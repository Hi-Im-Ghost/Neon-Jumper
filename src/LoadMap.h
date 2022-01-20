#ifndef TREES_JSON_LOADMAP_H
#define TREES_JSON_LOADMAP_H

#include "Map.h"
#include "TileSet.h"
#include "TileMap.h"
#include <iostream>
#include <string>
/**
 * @class Klasa ta służy do wczytywania mapy oraz jej elementów
 */
class LoadMap {
private:
    ///Zmienna która przechowuje teksturę dla tła
    sf::Texture bg;
    ///Zmienna która służy do przeniesienia tekstury tła na ekran
    sf::Sprite bgSpr;
    ///Vector który przechowuje wszystkie elementy mapy do wyrenderowania
    std::vector<TileMap> tilemap_render;

    ///Obiekt warstwy gry który przechowuje hitboxy dla terenu
    Layer solidLayer;
    ///Obiekt warstawy gry który przechowuje hitboxy dla obiektów które zadają obrażenia
    Layer damageLayer;

public:
    /***
     * Konstruktor, który przyjmuje nazwę pliku json w którym to znajdują się elementy mapy
     * @param mapFileName - nazwa pliku json w której to znajdują się elementy mapy
     */
    LoadMap(std::string mapFileName);
    /***
     * Metoda która słuzy do wczytywania danych z pliku
     * @return zwraca tekst wczytany z pliku
     */
    std::ifstream readFile(std::string);
    /***
     * Metoda która służy do znalezienia przekazanej w parametrze warstwy
     * @return zwraca warstwie kafelków
     */
    TileSet findTileSet(Layer&, std::vector<TileSet>&);

    /***
     * Metoda klasy Layer która zwraca warstwe hitboxow dla terenu
     * @return zwraca warstwe, która reprezentuje hitboxy terenu
     */
    Layer getSolidLayer();
    /***
     * Metoda klasy Layer która zwraca warstwe hitboxow dla obiektow ktore zadaja obrazenia
     * @return zwraca warstwie, która reprezentuje hitboxy dla obiektów zadających obrażenia
     */
    Layer getDamageLayer();

    /***
     * Służy do wyświetlania na ekranie warstw
     * @param window - okno na którym elementy mają być wyświetlane
     */
    void draw(sf::RenderTarget& window);

};


#endif //TREES_JSON_LOADMAP_H
