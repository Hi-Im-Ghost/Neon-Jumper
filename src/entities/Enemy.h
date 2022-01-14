#ifndef TREES_JSON_ENEMY_H
#define TREES_JSON_ENEMY_H

#include "../modules/Damageable.h"
#include "../modules/Animated.h"
/**
 * @class Opisuje postać przeciwnika, którą można spotkać w grze
 */
class Enemy : public Damageable, public Animated {
protected:
    /// Przechowuje teksturę przeciwnika
    sf::Texture _texture;
    /// Przechowuje sprite-a gracza
    sf::Sprite _sprite;
    /// Reprezentuje kształt odpowiedzialny za kolizje i ruch przeciwnika
    sf::RectangleShape _hitbox;
    /// Reprezentuje kształt określający granice ruchu przeciwnika
    sf::RectangleShape _path;
    /// Określa kierunek ruchu przeciwnika
    bool movingRight = false;

    /// Wczytuje teksturę z pliku, oraz tworzy sprite ze wczytanej tekstury
    void initSprite(const std::string& filePath, sf::IntRect frame);
    /// Nadaje odpowiednie parametry hitboxowi
    void initHitbox(sf::Vector2f size);
    /// Nadaje odpowiednie parametry granicy ruchu
    virtual void initPath(float pointA, float pointB) = 0;

    /// Ustawia pozycję przeciwnika na mapie
    void setPosition(float x, float y);
public:
    /// Konstruktor przyjmuje początkową pozycję przeciwnika na mapie
    explicit Enemy(float x = 0, float y = 0);

    /// Porusza przeciwnikiem w poziomej linii o podaną wartość
    void moveHorizontal(float x);
    /// Zwraca pozycję przeciwnika na mapie
    sf::Vector2f getPosition();
    /// Zwraca hitbox przeciwnika. Używane do sprawdzania kolizji
    sf::RectangleShape& getHitbox() {return _hitbox;}

    /// Odpowiada za odświeżanie logiki przeciwnika
    virtual void update(float deltaSeconds) = 0;
    /// Wyświetla przeciwnika na ekranie
    virtual void render(sf::RenderTarget& window) = 0;
};


#endif //TREES_JSON_ENEMY_H
