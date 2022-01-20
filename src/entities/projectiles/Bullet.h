#ifndef TREES_JSON_BULLET_H
#define TREES_JSON_BULLET_H

#include "Projectile.h"

/**
 * @class Opisuje pocisk z jakiego korzsta gracz
 */
class Bullet : public Projectile {
private:
    /// Prędkość lecącego pocisku
    float speed;
    /// Modyfikator prędkości pocisku
    float speedRate;
    /// Wartość, o którą co klatkę zmniejsza się speedRate
    float speedFallRate;

    /// Porusza pociskiem w odpowiedni sposób
    void move() override;

public:
    /**
     * Konstruktor pocisku gracza
     * @param pos początkowa pozycja pocisku na mapie
     * @param movingRight określa, czy pocisk leci w prawo
     */
    Bullet(sf::Vector2f pos, bool movingRight);

    /// Aktualizacja logiki pocisku
    void update(float deltaTime) override;
};


#endif //TREES_JSON_BULLET_H
