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
    ///Konstruktor, który przyjmuje nazwę pliku json w którym to znajdują się elementy mapy
    LoadMap(std::string mapFileName);
    ///Metoda która słuzy do wczytywania danych z pliku
    std::ifstream readFile(std::string);
    ///Metoda która służy do znalezienia przekazanej w parametrze warstwy
    TileSet findTileSet(Layer&, std::vector<TileSet>&);

    ///Metoda klasy Layer która zwraca warstwe hitboxow dla terenu
    Layer getSolidLayer();
    ///Metoda klasy Layer która zwraca warstwe hitboxow dla obiektow ktore zadaja obrazenia
    Layer getDamageLayer();

    ///Służy do wyświetlania na ekranie warstw
    void draw(sf::RenderTarget& window);

};


#endif //TREES_JSON_LOADMAP_H
