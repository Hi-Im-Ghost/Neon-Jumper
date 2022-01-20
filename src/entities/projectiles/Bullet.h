#ifndef TREES_JSON_BULLET_H
#define TREES_JSON_BULLET_H

#include "Projectile.h"

class Bullet : public Projectile {
private:
    float speed;
    float speedRate;
    float speedFallRate;

    void move(float x, float y) override;

public:
    Bullet(sf::Vector2f pos, bool movingRight);

    void update(float deltaTime) override;
};


#endif //TREES_JSON_BULLET_H
