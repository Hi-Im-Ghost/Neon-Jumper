//
// Created by ToQly on 09.01.2022.
//

#ifndef TREES_JSON_SLIME_H
#define TREES_JSON_SLIME_H

#include "Enemy.h"

class Slime : public Enemy {
private:
    void initPath(float pointA, float pointB) override;
public:
    explicit Slime(float x, float y, float pathPointA, float pathPointB, bool moveRight);

    void update(float deltaSeconds) override;
    void render(sf::RenderTarget &window) override;
};


#endif //TREES_JSON_SLIME_H
