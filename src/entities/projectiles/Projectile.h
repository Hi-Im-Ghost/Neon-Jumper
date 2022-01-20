#ifndef TREES_JSON_PROJECTILE_H
#define TREES_JSON_PROJECTILE_H

#include <SFML/Graphics.hpp>
/**
 * @class Opisuje obiekt, który może służyć jako pocisk
 */
class Projectile {
private:
    /// Tekstura pocisku
    sf::Texture _texture;
    /// Sprite pocisku wczytywany z tekstury
    sf::Sprite _sprite;
    /// Kształt odpowiadający za wykrywanie kolizji pocisku
    sf::RectangleShape _hitbox;

    /// Określa czy pocisk porysza się w prawo, czy w lewo
    bool _bMovingRight;
    /// Określa czy pocisk powinien być zniszczony
    bool _bShouldBeDestroyed = false;

protected:
    /// Porusza pociskiem w odpowiedni sposób
    virtual void move() = 0;
    /** Ustawia pozycję pozisku na mapie
     * @param x pozycja x na mapie
     * @param y pozycja y na mapie
     */
    void setPosition(float x, float y);

    /** Inicjalizacja tekstury i sprite pocisku
     * @param path ścieżka do pliku tekstury
     * @param textureRect fragment tekstury, który zostanie wczytany do sprite
     */
    void initTexture(const std::string& path, sf::IntRect textureRect);
public:
    /**
     * Konstruktor pocisku
     * @param pos początkowa pozycja pocisku na mapie
     * @param movingRight określa czy pocisk powinien poruszać się w prawo czy w lewo
     */
    Projectile(sf::Vector2f pos, bool movingRight);

    /**
     * Zwraca pozycję pocisku na mapie
     * @return pozycja pocisku na mapie
     */
    sf::Vector2f getPosition();
    /**
     * Zwraca informację, czy pocisk porusza się w prawo
     * @return informacja, czy pocisk porusza się w prawo
     */
    bool getIsMovingRight() const {return _bMovingRight;}
    /**
     * Zwraca informację, czy pocisk powinien zostać zniszczony
     * @return informacja, czy pocisk powinien zostać zniszcczony
     */
    bool getShouldBeDestroyed() const {return _bShouldBeDestroyed;}
    /**
     * Sprawdza, czy pocisk koliduje z podanym kształtem
     * @param recShape kształt z którym pocisk testuje kolizje
     * @return true - jeżeli nastąpiła kolizja, false - jeżeli nie
     */
    bool isColliding(const sf::RectangleShape& recShape);
    /// Oznacza pocisk jako gotowy do zniszczenia
    void markForDestruction() {_bShouldBeDestroyed = true;}

    /** Odświeżanie logiki pocisku
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    virtual void update(float deltaTime);
    /**
     * Renderowanie pocisku na oknie
     * @param window okno, na którym renderowany jest pocisk
     */
    void render(sf::RenderTarget& window);
};


#endif //TREES_JSON_PROJECTILE_H
