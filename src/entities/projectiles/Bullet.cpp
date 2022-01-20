#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, bool movingRight) : Projectile(pos, movingRight) {
    initTexture("../resources/shot.png", {0,0,4,4});

    speed = 10.0f;
    speedRate = 3.0f;
    speedFallRate = 10.0f;
}

void Bullet::move() {
    setPosition(
            getPosition().x + (speed * speedRate * ((getIsMovingRight()) ? 1.0f : -1.0f) ),
            getPosition().y
            );
}

void Bullet::update(float deltaTime) {
    Projectile::update(deltaTime);

    if (speedRate < 0.001f) {
        markForDestruction();
    } else {
        speedRate -= speedFallRate * deltaTime;
    }
    move();
}
