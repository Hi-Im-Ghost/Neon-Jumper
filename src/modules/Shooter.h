#ifndef TREES_JSON_SHOOTER_H
#define TREES_JSON_SHOOTER_H


#include <SFML/Graphics.hpp>
#include <list>
#include "../entities/projectiles/Projectile.h"

class Shooter {
private:
    ///
    std::list<Projectile*> projectileList;

protected:
    /// Pozycja z której obiekt wykonuje strzał
    sf::Vector2f shootingPoint;
    /// Odstęp czasowy pomiędzy strzałami
    float shootingCooldown;

    /// Wykonuje strzał
    virtual void shoot() = 0;
    void addToList(Projectile* projectile);
    void removeFromList(Projectile* projectile);

    void renderProjectiles(sf::RenderTarget& window);
    void updateProjectiles(float deltaTime);

public:
    bool checkIsProjectileColliding(const sf::RectangleShape& recShape);
};


#endif //TREES_JSON_SHOOTER_H
