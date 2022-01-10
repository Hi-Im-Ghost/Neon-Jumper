#ifndef TREES_JSON_PLAYER_H
#define TREES_JSON_PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <list>
#include <SFML/Audio.hpp>

#include "../modules/Damageable.h"
#include "../modules/Animated.h"

class Player : public Damageable, public Animated {
private:
    sf::SoundBuffer bufGame;
    sf::Sound jumpGame;
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::RectangleShape _hitbox;
    sf::Vector2f _velocity;
    sf::Vector2f _spriteOffset;

    float _acceleration;
    float _maxSpeedX;
    float _maxSpeedY;
    float _jumpForce;
    float _gravity;
    float _gravityDelta;
    bool _bIsGrounded;

    /// Pozwala określić, czy czas jest w tej chwili zatrzymany
    bool _bTimeStopped;
    /// Jeżeli wartość ta równa jest 1, to można zatrzymać czas, po czym wartość zeruje się
    float tsValue;
    /// Określa z jaką prędkością napełnia się wartość tsValue
    float tsFillRate;
    /// Liczy czas po którym czas zostanie wznowiony
    sf::Clock tsClock;

    void initValues();
    void initSprite();
    void initHitbox();
    void initSoundGame();

    void handleInput(float deltaTime);
    void handleCollision(const std::list<sf::RectangleShape>& allHitboxes);
    void moveFinal();
    void applyGravity(float deltaSeconds);
    void jump();
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
    sf::Vector2f getPosition();
    void zeroVelocity(bool x, bool y);
    bool checkForIntersection(sf::RectangleShape& shape);
    bool getTimeStopped() const {return _bTimeStopped;}
    float getTimeStopValue() const {return tsValue;}

    void update(float deltaTime, const std::list<sf::RectangleShape>& allHitboxes);
    void render(sf::RenderTarget& window);
    void setPosition(sf::Vector2f);
    void switchAnimation(Animation newAnimation);
};


#endif //TREES_JSON_PLAYER_H
