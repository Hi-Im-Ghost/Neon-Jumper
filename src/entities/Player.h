#ifndef TREES_JSON_PLAYER_H
#define TREES_JSON_PLAYER_H

#include <SFML/Window/Keyboard.hpp>
#include <list>
#include <SFML/Audio.hpp>
#include "projectiles/Bullet.h"

#include "../modules/Damageable.h"
#include "../modules/Animated.h"
#include "../modules/Shooter.h"

/**
 * @class Reprezentuje postać gracza
 */
class Player : public Damageable, public Animated, public Shooter {
private:
    /// Bufor dla dźwięku skoku
    sf::SoundBuffer bufGame;
    /// Dźwięk skoku
    sf::Sound jumpGame;
    /// Tekstura gracza
    sf::Texture _texture;
    /// Sprite gracza wczytywany z tekstury
    sf::Sprite _sprite;
    /// Kształt odpowiadający za kolizje i poruszanie się
    sf::RectangleShape _hitbox;
    /// Prędkość gracza. Dodaje się ją do poprzedniej prędkości symulując ruch
    sf::Vector2f _velocity;

    /// Przyspieszenie gracza podczas poruszania się
    float _acceleration;
    /// Maksymalna prędkość pozioma gracza
    float _maxSpeedX;
    /// Maksymalna prędkość pionowa gracza
    float _maxSpeedY;
    /// Siła skoku
    float _jumpForce;
    /// Siła grawitacji działająca na gracza
    float _gravity;
    /// Różnica siły grawitacji używana do lepszego symulowania skoku
    float _gravityDelta;
    /// Pokazuje czy gracz stoi na jakimś podłożu
    bool _bIsGrounded;

    // Time stop values
    /// Pozwala określić, czy czas jest w tej chwili zatrzymany
    bool _bTimeStopped;
    /// Jeżeli wartość ta równa jest 1, to można zatrzymać czas, po czym wartość zeruje się
    float tsValue;
    /// Określa z jaką prędkością napełnia się wartość tsValue
    float tsFillRate;
    /// Liczy czas po którym czas zostanie wznowiony
    sf::Clock tsClock;

    /// Nadanie początkowych wartości parametrom gracza takim jak przyspieszenie.
    void initValues();
    /// Wczytanie tekstury z pliku i zaaplikowanie jej do sprite
    void initSprite();
    /// Nadaje początkowe parametry hitboxowi
    void initHitbox();
    /// Wczytuje z pliku i zapisuje dźwięki dla gracza
    void initSoundGame();

    /** Sprawdza, czy użytkownik nacisnął odpowiedni przycisk oraz wykonuje odpowiednią akcję
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    void handleInput(float deltaTime);
    /** Sprawdza kolizję gracza ze wszystkimi obiektami terenu i w przypadku kolizji zeruje prędkość gracza
     * @param allHitboxes lista wszystkich hitboksów otoczenia na mapie
     */
    void handleCollision(const std::list<sf::RectangleShape>& allHitboxes);
    /// Aplikuje prędkość do pozycji gracza.
    void moveFinal();
    /** Dodaje do prędkości wartość grawitacji
     * @param deltaSeconds czas pomiędzy klatkami aplikacji
     */
    void applyGravity(float deltaSeconds);
    /// Wykonuje skok
    void jump();
    /// Przypisuje obiektowi sprite skrawek tekstury odpowiadający animacji odpowiedniej do sytuacji gracza
    void animateMovement();

    // Shooting
    void shoot() override;

    // Time stop functions
    /// Służy do zatrzymywania czasu
    void timeStop();
    /// Służy do wznawiania czasu
    void timeStart();

public:
    /** Konstruktor gracza z opcją podania lokalizacji początkowej na mapie
     * @param x początkowa pozycja x gracza na mapie
     * @param y początkowa pozycja y gracza na mapie
     */
    explicit Player(float x = 0, float y = 0);

    // Position and logic
    /** Służy do poruszania graczem. Podanie wartości 1 jako argument porusza graczem w domyślny sposób.
     * Podanie do parametrów wartości 1, lub -1 jest domyślnym sposobem korzystania z metody.
     * Podanie większej, lub mniejszej wartości skutkować będzie zmianą prędkości poruszania się.
     * Podane wartości nie zmieniają prędkości bezpośrednio, a tylko dodają wartość do wektora prędkości.
     * @param x wartość o którą gracz zostanie poruszony poziomo
     * @param y wartość o którą gracz zostanie poruszony pionowo
     */
    void move(float x, float y);
    /** Zwraca pozycję gracza
     * @return Pozycja gracza
     */
    sf::Vector2f getPosition();
    /** Zerowanie wektora prędkości na osi
     * @param x zerowanie zmiennej x wektora
     * @param y zerowanie zmiennej y wektora
     */
    void zeroVelocity(bool x, bool y);
    /** Sprawdza, czy hitbox gracza nachodzi na hitbox podany w parametrze
     * @param shape hitbox, który ma być sprawdzany pod kątem nachodzenia na hitbox gracza
     * @return true - jeżeli hitboxy na siebie nachodzą, false - jeżeli hitboxy na siebie nie nachodzą
     */
    bool checkForIntersection(sf::RectangleShape& shape);

    // Time stop
    /** Pozwala sprawdzić czy czas jest zatrzymany
     * @return true - jeżeli czas jest zatrzymany, false - jeżeli czas płynie
     */
    bool getTimeStopped() const {return _bTimeStopped;}
    /** Pobiera stopień naładowania umiejętności zatrzymania czasu
     * @return wartość od 0 do 1 reprezentująca stopień naładowania umiejętności
     */
    float getTimeStopValue() const {return tsValue;}

    /** Odświeża logikę gracza odpowiedzialną za ruch, czytanie klawiatury itd.
     * @param deltaTime czas pomiędzy klatkami aplikacji
     * @param allHitboxes lista wszystkich hitboksów otoczenia na mapie
     */
    void update(float deltaTime, const std::list<sf::RectangleShape>& allHitboxes);
    /** Wyświetla postać gracza na ekranie
     * @param window okno na którym renderowany jest gracz
     */
    void render(sf::RenderTarget& window);
    /** Ustawia pozycję postaci gracza a mapie
     * @param position nowa pozycja gracza
     */
    void setPosition(sf::Vector2f position);
    /** Zmienia stan animacji gracza na podany
     * @param newAnimation nowa animacja typu enum Animation zdefiniowanego w Animated.h
     */
    void switchAnimation(Animation newAnimation) override;

    /// Określa, czy umiejętność zatrzymania czasu jest gotowa do użycia
    bool bTimeStopReady;
};


#endif //TREES_JSON_PLAYER_H
