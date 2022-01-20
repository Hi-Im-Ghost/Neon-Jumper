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

    /**
     *  Wczytuje teksturę z pliku, oraz tworzy sprite ze wczytanej tekstury
     * @param filePath ścieżka do pliku tekstury
     * @param frame określa jakim fragmentem tekstury zostanie zainicjowany sprite
     */
    void initSprite(const std::string& filePath, sf::IntRect frame);
    /** Nadaje odpowiednie parametry hitboxowi
     * @param size wymiary hitboxa
     */
    void initHitbox(sf::Vector2f size);
    /** Nadaje odpowiednie parametry granicy ruchu
     * @param pointA wartość x lewego punktu patrolowego
     * @param pointB wartość x prawego punktu patrolowego
     */
    virtual void initPath(float pointA, float pointB) = 0;

    /** Ustawia pozycję przeciwnika na mapie
     * @param x pozycja na osi x
     * @param y pozycja na osi y
     */
    void setPosition(float x, float y);
public:
    /** Konstruktor przyjmuje początkową pozycję przeciwnika na mapie
     * @param x początkowa pozycja x
     * @param y początkowa pozycja y
     */
    explicit Enemy(float x = 0, float y = 0);

    /** Porusza przeciwnikiem w poziomej linii o podaną wartość
     * @param x wartość na osi x o jaką zostanie poruszony przeciwnik
     */
    void moveHorizontal(float x);
    /** Zwraca pozycję przeciwnika na mapie
     * @return Pozycja gracza na mapie
     */
    sf::Vector2f getPosition();
    /** Zwraca hitbox przeciwnika. Używane do sprawdzania kolizji
     * @return obiekt reprezentujący hitbox
     */
    sf::RectangleShape& getHitbox() {return _hitbox;}

    /** Odpowiada za odświeżanie logiki przeciwnika
     * @param deltaSeconds czas pomiędzy klatkami aplikacji
     */
    virtual void update(float deltaSeconds) = 0;
    /** Wyświetla przeciwnika na ekranie
     * @param window okno na którym wyświetlony zostanie przeciwnik
     */
    virtual void render(sf::RenderTarget& window) = 0;
};


#endif //TREES_JSON_ENEMY_H
