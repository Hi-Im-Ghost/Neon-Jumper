#ifndef TREES_JSON_PLAYER_H
#define TREES_JSON_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <list>
#include <SFML/Audio.hpp>

#include "../modules/Damageable.h"
#include "../modules/Animated.h"

/**
 * @class Reprezentuje postać gracza
 */
class Player : public Damageable, public Animated {
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
    /// Przesunięcie sprite względem pozycji gracza
    sf::Vector2f _spriteOffset;

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

    /// Sprawdza, czy użytkownik nacisnął odpowiedni przycisk oraz wykonuje odpowiednią akcję
    void handleInput(float deltaTime);
    /// Sprawdza kolizję gracza ze wszystkimi obiektami terenu i w przypadku kolizji zeruje prędkość gracza
    void handleCollision(const std::list<sf::RectangleShape>& allHitboxes);
    /// Aplikuje prędkość do pozycji gracza.
    void moveFinal();
    /// Dodaje do prędkości wartość grawitacji
    void applyGravity(float deltaSeconds);
    /// Wykonuje skok
    void jump();
    /// Przypisuje obiektowi sprite skrawek tekstury odpowiadający animacji odpowiedniej do sytuacji gracza
    void animateMovement();

    /// Służy do zatrzymywania czasu
    void timeStop();
    /// Służy do wznawiania czasu
    void timeStart();

public:
    /// Konstruktor gracza z opcją podania lokalizacji początkowej na mapie
    explicit Player(float x = 0, float y = 0);

    /// Służy do poruszania graczem. Podanie wartości 1 jako argument porusza graczem w domyślny sposób.
    void move(float x, float y);
    /// Zwraca pozycję gracza
    sf::Vector2f getPosition();
    /// Zeruje x - poziomą, y - pionową prędkość gracza
    void zeroVelocity(bool x, bool y);
    /// Sprawdza, czy hitbox gracza nachodzi na hitbox podany w parametrze
    bool checkForIntersection(sf::RectangleShape& shape);
    /// Pozwala sprawdzić czy czas jest zatrzymany
    bool getTimeStopped() const {return _bTimeStopped;}
    /// Zwraca wartość 0-1 reprezentującą stopień naładowania umiejętności zatrzymania czasu
    float getTimeStopValue() const {return tsValue;}

    /// Odświeża logikę gracza odpowiedzialną za ruch, czytanie klawiatury itd.
    void update(float deltaTime, const std::list<sf::RectangleShape>& allHitboxes);
    /// Wyświetla postać gracza na ekranie
    void render(sf::RenderTarget& window);
    /// Ustawia pozycję postaci gracza a mapie
    void setPosition(sf::Vector2f);
    /// Zmienia stan animacji gracza na podany
    void switchAnimation(Animation newAnimation);

    bool isReady;
};


#endif //TREES_JSON_PLAYER_H
