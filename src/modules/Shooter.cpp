#include "Shooter.h"

void Shooter::renderProjectiles(sf::RenderTarget& window) {
    for (auto& p : projectileList) {
        p->render(window);
    }
}

void Shooter::updateProjectiles(float deltaTime) {
    for (auto& p : projectileList) {
        p->update(deltaTime);
        if (p->getShouldBeDestroyed())
            removeFromList(p);
    }
}

void Shooter::addToList(Projectile *projectile) {
    projectileList.push_back(projectile);
}

void Shooter::removeFromList(Projectile *projectile) {
    projectileList.remove(projectile);
}

bool Shooter::checkIsProjectileColliding(const sf::RectangleShape& recShape) {
    for (auto& p : projectileList) {
        if ( p->isColliding(recShape) ) {
            p->markForDestruction();
            return true;
        }
    }
    return false;
}
