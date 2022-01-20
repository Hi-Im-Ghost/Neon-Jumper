#include "Bullet.h"

Bullet::Bullet(sf::Vector2f pos, bool movingRight) : Projectile(pos, movingRight) {
    initTexture("../resources/shot.png", {0,0,8,8});

    speed = 1.0f;
    speedRate = 1.0f;
    speedFallRate = 0.0f;
}

void Bullet::move(float x, float y) {
    setPosition(
            getPosition().x + (speed * speedRate * ((getIsMovingRight()) ? 1.0f : -1.0f) ),
            getPosition().y
            );
}

void Bullet::update(float deltaTime) {
    Projectile::update(deltaTime);

    speedRate -= deltaTime;

    if (speed * speedRate < 0.001f) {
        markForDestruction();
    }
}
