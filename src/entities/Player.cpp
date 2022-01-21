#include <iostream>
#include "Player.h"

Player::Player(float x, float y) {
    initValues();
    initSprite();
    initHitbox();
    initSoundGame();
    setMaxHP(3);
    setHP(3);
    setPosition({x,y});
    switchAnimation(Animated::IDLE);
}

void Player::update(float dt, const std::list<sf::RectangleShape>& allHitboxes) {
    _sprite.setPosition(_hitbox.getPosition());

    updateInvincibilityTimer(dt);
    handleInput(dt);
    applyGravity(dt);
    handleCollision(allHitboxes);
    moveFinal();

    if (_bTimeStopped && tsClock.getElapsedTime().asSeconds() > 5)
        timeStart();
    if (tsValue < 1.0f && !_bTimeStopped) {
        tsValue += dt * tsFillRate;
    }
    if(getTimeStopValue()>=1.0f){
        bTimeStopReady= true;
    }else{
        bTimeStopReady= false;
    }

    if (shootingCooldown > 0.0f)
        shootingCooldown -= dt;

    updateProjectiles(dt);
    for (auto& h : allHitboxes)
        if (checkIsProjectileColliding(h))
            std::cout << "col";
}

void Player::render(sf::RenderTarget &window) {
    animateMovement();
    animate(_sprite);
    window.draw(_sprite);
    //window.draw(_hitbox);
    renderProjectiles(window);
}

void Player::initValues() {
    _acceleration = 8.0f;
    _maxSpeedX = 5.0f;
    _maxSpeedY = 20.0f;
    _jumpForce = 2.3f;
    _gravity = 7.0f;
    _gravityDelta = 5.0f;
    _bIsGrounded = false;
    _bTimeStopped = false;
    tsValue = 0;
    tsFillRate = 0.1;

    shootingPoint = {10, 30};
    shootingCooldown = 0.7f;
}

void Player::initSprite() {
    _texture.loadFromFile("../resources/player.png");
    _sprite.setTexture(_texture);
    _sprite.setScale({4,4});
    _sprite.setTextureRect(sf::IntRect(0, 0, 12, 15));
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (_bIsGrounded)
            jump();
        _gravityDelta = -2.5f;
    } else
        _gravityDelta = 0.0f;

    if (!bMoving)
        zeroVelocity(true, false);
    _bIsGrounded = false;

    // Time Stop
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)
    && !_bTimeStopped
    && tsValue >= 1.0f)
    {
        timeStop();
    }

    // Shooting
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootingCooldown <= 0.0f) {
        shoot();
        shootingCooldown = 0.7f;
        std::cout << "Shot!" << "\n";
    }
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

    bufShoot.loadFromFile("../resources/music/shoot.wav");
    shootGame.setBuffer(bufShoot);
    shootGame.setVolume(30);
}

bool Player::checkForIntersection(sf::RectangleShape& shape) {
    return _hitbox.getGlobalBounds().intersects(shape.getGlobalBounds());
}

void Player::animateMovement() {
    if (_velocity.x > 0) {
        // FACING RIGHT
        _bIsFlipped = false;
    }
    else if (_velocity.x < 0) {
        // FACING LEFT
        _bIsFlipped = true;
    }

    if (_bIsGrounded) {
        // IDLE
        if (_velocity.x == 0) {
            if (getCurrentAinmation() != Animated::IDLE)
                switchAnimation(Animated::IDLE);
        }
        // GOING RIGHT / LEFT
        else {
            if (getCurrentAinmation() != Animated::WALK)
                switchAnimation(Animated::WALK);
        }
    }
    else {
        if (std::abs(_velocity.y) > 0) {
            // IN AIR
            //sf::IntRect upf = sf::IntRect(0,20*3,15,20);
            if (getCurrentAinmation() != JUMP)
                switchAnimation(JUMP);
            //_sprite.setTextureRect(upf);
        }
    }
}

void Player::switchAnimation(Animation newAnimation)  {
    Animated::switchAnimation(newAnimation);
    switch (newAnimation) {

        case IDLE:
            setAnimValues({0,16}, {12,15},2, 0.7, true);
            break;
        case WALK:
            setAnimValues({0,0}, {12,15},4, 0.1, true);
            break;
        case JUMP:
            setAnimValues({0, 31}, {12,15},1,10.0, false);
            break;
        case FALL:
            break;
    }
    animate(_sprite, true);
}

void Player::timeStop() {
    _bTimeStopped = true;
    tsValue = 0;
    tsClock.restart();
}

void Player::timeStart() {
    _bTimeStopped = false;
}

void Player::shoot() {
    shootGame.play();
    sf::Vector2f sp = shootingPoint;
    sp.x *= (_bIsFlipped) ? -1 : 1;
    Bullet* b = new Bullet(getPosition() + sp, !_bIsFlipped);
    addToList(b);
}
