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

public:
    Player();
    Player(float x, float y);

    void move(float x, float y);
    sf::Vector2f getPosition();
    void zeroVelocity(bool x, bool y);
    bool checkForIntersection(sf::RectangleShape& shape);

    void update(float deltaTime, const std::list<sf::RectangleShape>& allHitboxes);
    void render(sf::RenderTarget& window);
    void setPosition(sf::Vector2f);
};


#endif //TREES_JSON_PLAYER_H
