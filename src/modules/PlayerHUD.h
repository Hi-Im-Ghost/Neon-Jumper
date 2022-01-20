#ifndef TREES_JSON_PLAYERHUD_H
#define TREES_JSON_PLAYERHUD_H


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Damageable.h"

/**
 * @class Klasa służąca do tworzenia HUD dla gracza
 */
class PlayerHUD {
private:
    ///Tablica przechowująca ilość naszych tekstur życia
    sf::RectangleShape hearths[3];
    sf::RectangleShape stopwatch;
    ///Tekstura dla ilości żyć gracza
    sf::Texture htfull;
    ///Tekstura dla umiejetności gracza
    sf::Texture stopTime;

    ///Metoda służąca do inicjalizacji tekstur dla hud gracza
    void initTexture();
    ///Metoda służąca do inicjalizacji właściwości tekstury życia
    void initHearts();
    ///Metoda służąca do inicjalizacji właściwości tekstury umiejętności zatrzymania czasu
    void initStopTime();
protected:

public:
    /// Konstruktor dla HUD
    PlayerHUD();

    /** Wyświetla tekstury HUD na ekranie
     * @param window okno na którym ma być rysowany HUD
     */
    void render(sf::RenderTarget& window);
    /** Odświeża stan naszych tekstur HUD
     * @param damageableModule moduł Damageable, który przechowuje dane o ilości życia obiektu
     * @param playerReady Wartość pokazująca, czy umiejętność zatrzymania czasu jest gotowa do użycia
     */
    void update(Damageable* damageableModule, bool playerReady);
    /** Pozwala ustawić pozycje dla tekstur HUD
     * @param x pozycja x HUD na ekranie
     * @param y pozycja y HUD na ekranie
     */
    void setPosition(float x, float y);
    /// Zmienna pozwalająca sprawdzić czy otrzymaliśmy jakieś obrażenia
    bool takedDmg;


};


#endif //TREES_JSON_PLAYERHUD_H
