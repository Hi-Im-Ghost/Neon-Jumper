//
// Created by ToQly on 09.01.2022.
//

#ifndef TREES_JSON_SLIME_H
#define TREES_JSON_SLIME_H

#include "Enemy.h"
/**
 * @class Slime to rodzaj przeciwnika, który porusza się poziomo od punktu A do B
 */
class Slime : public Enemy {
private:
    /// Implementacja funkcji initPath z Enemy.h
    void initPath(float pointA, float pointB) override;
public:
    /// Konstruktor przeciwnika slime.
    /// x i y to pozycja na mapie,
    /// pathPointA i pathPointB określają zakres patrolu dla przeciwnika
    /// moveRight określa czy początkowo przeciwnik porusza się w lewo czy w prawo
    explicit Slime(float x, float y, float pathPointA, float pathPointB, bool moveRight);

    /// Implementacja wirtualnej metody update z Enemy.h
    void update(float deltaSeconds) override;
    /// Implementacja wirtualnej metody render z Enemy.h
    void render(sf::RenderTarget &window) override;
};


#endif //TREES_JSON_SLIME_H
