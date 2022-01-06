#include <iostream>
#include "Player.h"

Player::Player() {
    initValues();
    initSprite();
    initHitbox();
    initSoundGame();

    setMaxHP(3);
    setHP(3);

}

Player::Player(float x, float y) {
    initValues();
    initSprite();
    initHitbox();
    initSoundGame();
    setMaxHP(3);
    setHP(3);
    setPosition({x,y});
}

void Player::update(float dt, const std::list<sf::RectangleShape>& allHitboxes) {
    _sprite.setPosition(_hitbox.getPosition() + _spriteOffset);

    updateInvincibilityTimer(dt);
    handleInput(dt);
    applyGravity(dt);
    handleCollision(allHitboxes);
    moveFinal();
}

void Player::render(sf::RenderTarget &window) {
    animateMovement();
    window.draw(_sprite);
    window.draw(_hitbox);
}

void Player::initValues() {
    _acceleration = 3.0f;
    _maxSpeedX = 1.0f;
    _maxSpeedY = 3.0f;
    _jumpForce = 900.0f;
    _gravity = 3.0f;
    _gravityDelta = 0.0f;
    _bIsGrounded = false;
    _spriteOffset = {0,0};
}

void Player::initSprite() {
    _texture.loadFromFile("../resources/player.png");
    _sprite.setTexture(_texture);
    _sprite.setScale({4,4});
    _sprite.setTextureRect(sf::IntRect(0, 0, 12, 16));
}

void Player::initHitbox() {
    _hitbox.setSize({30, 60});
    _hitbox.setOutlineColor(sf::Color::Red);
    _hitbox.setFillColor(sf::Color::Transparent);
    _hitbox.setOutlineThickness(1);
}

void Player::move(float x, float y) {
    _velocity.x += x * _acceleration;
    _velocity.y += y * _acceleration;
}

sf::Vector2f Player::getPosition() {
    return _hitbox.getPosition();
}

void Player::moveFinal() {
    // Restrict horizontal movement speed
    if (std::abs(_velocity.x) >= _maxSpeedX)
        _velocity.x = _maxSpeedX * ((_velocity.x < 0) ? -1.0f : 1.0f );

    // Restrict vertical movement speed
    if (std::abs(_velocity.y) >= _maxSpeedY)
        _velocity.y = _maxSpeedY * ((_velocity.y < 0) ? -1.0f : 1.0f );

    setPosition(getPosition() + _velocity);
}

void Player::setPosition(sf::Vector2f newPos) {
    _hitbox.setPosition(newPos);
}

void Player::handleInput(float dt) {
    bool bMoving = false;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        move(-1.0f * dt, 0.0f);
        bMoving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        move(1.0f * dt, 0.0f);
        bMoving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (_bIsGrounded)
            jump();
        _gravityDelta = -0.5f;
    } else
        _gravityDelta = 0.0f;

    if (!bMoving)
        zeroVelocity(true, false);
    _bIsGrounded = false;
}

void Player::zeroVelocity(bool x, bool y) {
    if (x)
        _velocity.x = 0.0;
    if (y)
        _velocity.y = 0.0;
}

void Player::handleCollision(const std::list<sf::RectangleShape>& allHitboxes) {
    sf::FloatRect prevPlayerHb = _hitbox.getGlobalBounds();

    sf::Vector2f velDelta = _velocity;
    setPosition(getPosition() + velDelta);

    sf::FloatRect playerHb = _hitbox.getGlobalBounds();

    for (auto & h : allHitboxes)
    {
        sf::FloatRect hb = h.getGlobalBounds();
        if (playerHb.intersects(hb))
        {
            // Top collision
            if (playerHb.top <= hb.top
                     && prevPlayerHb.top + playerHb.height <= hb.top)
            {
                // Zero out vertical velocity
                zeroVelocity(false, true);
                _bIsGrounded = true;
            }

                // Bottom collision
            else if (playerHb.top + playerHb.height >= hb.top + hb.height
            && prevPlayerHb.top >= hb.top + hb.height)
            {
                // Zero out vertical velocity
                zeroVelocity(false, true);
            }

            // Right collision
            else if (playerHb.left + playerHb.width >= hb.left + hb.width
            && prevPlayerHb.left >= hb.left + hb.width)
            {
                // Zero out horizontal velocity
                zeroVelocity(true, false);
            }

            // Left collision
            else if (playerHb.left <= hb.left
            && prevPlayerHb.left + prevPlayerHb.width <= hb.left)
            {
                // Zero out horizontal velocity
                zeroVelocity(true, false);
            }
        }
    }

    setPosition(getPosition() - velDelta);
}

void Player::applyGravity(float dt) {
    move(0.0f, (_gravity + _gravityDelta) * dt);

    if(!_bIsGrounded && _velocity.y > 0.0f)
        _gravityDelta = 0.0f;
}

void Player::jump() {
    jumpGame.play();
    _gravityDelta = 0.0f;
    move(0.0f, -_jumpForce);
}

void Player::initSoundGame() {
    bufGame.loadFromFile("../resources/music/jump.wav");
    jumpGame.setBuffer(bufGame);
    jumpGame.setVolume(30);
}

bool Player::checkForIntersection(sf::RectangleShape& shape) {
    return _hitbox.getGlobalBounds().intersects(shape.getGlobalBounds());
}

void Player::animateMovement() {
    if (_velocity.x > 0) {
        // FACING RIGHT
        _sprite.setScale(4, 4);
        _spriteOffset = {0,0};
    }
    else if (_velocity.x < 0) {
        // FACING LEFT
        _sprite.setScale(-4,4);
        _spriteOffset = {static_cast<float>(_sprite.getTextureRect().width), 0};
    }

    if (_bIsGrounded) {
        // IDLE
        if (_velocity.x == 0) {
            animate(_sprite, 2, 2);
        }
        // GOING RIGHT / LEFT
        else {
            animate(_sprite, 1, 4);
        }
    }
    else {
        if (_velocity.y > 0) {
            // GOING UP / JUMPING
            sf::IntRect upf = sf::IntRect(0,16*3,12,16);
            _sprite.setTextureRect(upf);
        }
        else {
            // FALLING
            sf::IntRect upf = sf::IntRect(0,16*3,12*1,16);
            _sprite.setTextureRect(upf);
        }
    }
}
