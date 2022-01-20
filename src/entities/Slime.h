#ifndef TREES_JSON_SLIME_H
#define TREES_JSON_SLIME_H

#include "Enemy.h"
/**
 * @class Slime to rodzaj przeciwnika, który porusza się poziomo od punktu A do B
 */
class Slime : public Enemy {
private:
    /** Nadaje odpowiednie parametry granicy ruchu
     * @param pointA wartość x lewego punktu patrolowego
     * @param pointB wartość x prawego punktu patrolowego
     */
    void initPath(float pointA, float pointB) override;
public:
    /** Konstruktor przeciwnika slime.
     * @param x pozycja x na mapie
     * @param y pozycja y na mapie
     * @param pathPointA wartość x lewego punktu patrolowego
     * @param pathPointB wartość x prawego punktu patrolowego
     * @param moveRight określa czy początkowo przeciwnik porusza się w lewo czy w prawo
     */
    explicit Slime(float x, float y, float pathPointA, float pathPointB, bool moveRight);

    /** Odpowiada za odświeżanie logiki przeciwnika
     * @param deltaSeconds czas pomiędzy klatkami aplikacji
     */
    void update(float deltaSeconds) override;
    /** Wyświetla przeciwnika na ekranie
     * @param window okno na którym wyświetlony zostanie przeciwnik
     */
    void render(sf::RenderTarget &window) override;
};


#endif //TREES_JSON_SLIME_H
