#ifndef PLATFORMER2D_LAYER_H
#define PLATFORMER2D_LAYER_H

#include <SFML/Graphics.hpp>
#include "rapidjson/include/rapidjson/document.h"
/***
 * @class Klasa służąca do pobierania informacji o warstwach obiektów na mapie
 */
class LayerObject {
public:
    /** Konstruktor który przyjmuje współrzędne x,y oraz szerokość i wysokość dla obiektu warstwy
     * @param x - współrzędna x
     * @param y - współrzędna y
     * @param width - szerokość obiektu
     * @param height - wysokość obiektu
     */
    LayerObject(float x, float y, float width, float height);

    ///Zmienna przechowująca współrzędna x
    float x;
    ///Zmienna przechowująca współrzędna y
    float y;
    ///Zmienna przechowująca szerokość
    float width;
    ///Zmienna przechowująca wysokość
    float height;
};
/***
 * @class Klasa służąca do pobierania informacji o warstwach na mapie
 */
class Layer {
public:
    ///Konstruktor pusty
    Layer(){};
    /** Konstruktor który przyjmuje sparsowane wartości z json'a
     * @param value - sparsowane wartości json
     */
    Layer(rapidjson::Value& value);
    ///Destruktor
    ~Layer();

    /** Służy do zwracania informacji o miejscach wystąpienia na mapie danej warstwy
     * @return zwraca date, ktora zawiera informacje o wystapieniach na mapie danej warstwy
     */
    std::vector<int> getData() { return data; }
    /** Zwraca wysokość warstwy
     * @return zwraca liczbę oznaczająca wysokość
     */
    int getHeight() { return height; }
    /** Zwraca id warstwy
     * @return zwraca liczbę która reprezentuje id dla warstwy
     */
    int getId() { return id; }
    /** Zwraca sciezke do obrazka
     * @return zwraca tekst, który reprezentuje ścieżke do obrazka
     */
    std::string getImage() { return image; }
    /** Zwraca nazwe
     * @return zwraca tekst, który reprezentuje nazwe warstwy
     */
    std::string getName() { return name; }
    /** Zwraca informacje o przezroczystości
     * @return zwraca liczbe, która reprezentuje przezroczystość dla warstwy
     */
    int getOpacity() { return opacity; }
    /** Zwraca informacje o typie
     * @return zwraca tekst, który reprezentuje typ dla warstwy
     */
    std::string getType() { return type; }
    /** Zwraca informacje o widoczności
     * @return zwraca true jeśli warstwa jest widoczna lub false jeśli nie widoczna
     */
    bool isVisible() { return visible; }
    /** Zwraca szerokość warstwy
     * @return zwraca liczbę która reprezentuje szerokość warstwy
     */
    int getWidth() { return width; }
    /** Zwraca współrzędną x
     * @return zwraca liczbę, która reprezentuje współrzedną x dla warstwy
     */
    int getX() { return x; }
    /** Zwraca współrzędną y
     * @return zwraca liczbę, która reprezentuje współrzedną y dla warstwy
     */
    int getY() { return y; }
    /** Zwraca obiekty występujące w warstwie
     * @return zwraca obiekty, które występują w warstwie
     */
    std::vector<LayerObject> getObjects() {return objects;}

private:
    ///Wektor który przechowuje informacje o występieniach na mapie danej warstwy
    std::vector<int> data;
    ///Zmienna przechowująca wysokość
    int height;
    ///Zmienna przechowująca id
    int id;
    ///Zmienna przechowująca ściezke do obrazka
    std::string image;
    ///Zmienna przechowująca nazwe
    std::string name;
    ///Zmienna przechowująca przezroczystość
    int opacity;
    ///Zmienna przechowująca informacje o typie
    std::string type;
    ///Zmienna przechowująca informacje o widoczności
    bool visible;
    ///Zmienna przechowująca szerokość
    int width;
    ///Zmienna przechowujaca współrzędną x
    int x;
    ///Zmienna przechowująca współrzędną y
    int y;
    ///Wektor który przechowuje obiekty warstwy
    std::vector<LayerObject> objects;
};


#endif //PLATFORMER2D_LAYER_H
