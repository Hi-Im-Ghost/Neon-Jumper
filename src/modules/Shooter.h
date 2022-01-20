#ifndef TREES_JSON_SHOOTER_H
#define TREES_JSON_SHOOTER_H


#include <SFML/Graphics.hpp>
#include <list>
#include "../entities/projectiles/Projectile.h"

class Shooter {
private:
    /// Lista wystrzelonych przez ten obiekt pocisków
    std::list<Projectile*> projectileList;

protected:
    /// Pozycja z której obiekt wykonuje strzał
    sf::Vector2f shootingPoint;
    /// Odstęp czasowy pomiędzy strzałami
    float shootingCooldown;

    /// Wykonuje strzał
    virtual void shoot() = 0;
    /**
     * Dodaje podany pocisk do listy pocisków 'projectileList'
     * @param projectile Odniesienie do pocisku, który należy dodać do listy
     */
    void addToList(Projectile* projectile);
    /**
     * Usuwa podany pocisk z listy 'projectileList'
     * @param projectile Odniesienie do pocisku, który należy usunąć z listy
     */
    void removeFromList(Projectile* projectile);

    /**
     * Renderowanie pocisków na podanym oknie
     * @param window Okno na którym mają być renderowane pociski
     */
    void renderProjectiles(sf::RenderTarget& window);
    /**
     * Odświeżanie logiki pocisków
     * @param deltaTime Czas pomiędzy klatkami aplikacji
     */
    void updateProjectiles(float deltaTime);

public:
    /**
     * Sprawdza, czy jakikolwiek pocisk z listy koliduje z podanym kształtem, a jeżeli tak, to od razu usuwa go z listy
     * @param recShape Kształt na którym testowana jest kolizja z pociskami
     * @return true - jeżeli którykolwiek z pocisków trafił w podany kształt, false - jeżeli kolizja nie zachodzi
     */
    bool checkIsProjectileColliding(const sf::RectangleShape& recShape);
};


#endif //TREES_JSON_SHOOTER_H
