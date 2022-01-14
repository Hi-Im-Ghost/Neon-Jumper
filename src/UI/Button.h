#ifndef TREES_JSON_BUTTON_H
#define TREES_JSON_BUTTON_H


#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
/***
 * @class Klasa dla przycisków, przechowuje informacje o ich pozycji, stanie, wysokości, szerokości oraz tekście
 */
class Button {
public:
    ///Typ wyliczeniowy dla stanów przycisków
    enum ButtonState {
        IDLE,
        HOVER,
        ACTIVE
    };
private:
    ///Zmienna reprezentujaca kształt prostokąta dla przycisków
    sf::RectangleShape buttonShape;
    ///Zmienna przechowujaca tekst
    sf::Text text;
    ///Zmienna przechowująca informację o rodzaju czcionki
    sf::Font font;
    ///Zmienna przechowująca szerokość przycisku
    float width;
    ///Zmienna przechowujaca wysokość przycisku
    float height;
    ///Obiekt dla typu wyliczeniowego reprezentujacy stan przycisku
    ButtonState state;

    ///Metoda służąca do inicjalizacji tekstu przekazanego przez parametr
    void initText(const std::string& text);

public:
    ///Konstruktor który tworzy przycisk na wskazanej w parametrach pozycji x i y oraz wysokości i szerokości z tekstem.
    Button(const std::string& text, float posX, float posY, float width, float height);

    ///Przechowuje kolor podstawowy
    sf::Color colorIdle;
    ///Przechowuje kolor interakcji
    sf::Color colorHover;
    ///Przechowuje kolor aktywacji
    sf::Color colorActive;

    ///
    bool intersects(const sf::Shape& shape);
    ///Ustawia stan przycisku
    void setState(ButtonState newState);
    ///Zwraca stan przycisku
    ButtonState getState() {return state;}
    ///Przenosi na ekran przycisk
    void render(sf::RenderTarget& window);
    ///Służy do aktualizacji stanu przycisku kursorem myszy
    void update(const sf::RectangleShape& cursor);
};


#endif //TREES_JSON_BUTTON_H
