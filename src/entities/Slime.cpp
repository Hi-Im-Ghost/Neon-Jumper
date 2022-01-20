#include "Slime.h"

Slime::Slime(float x, float y, float pathPointA, float pathPointB, bool moveRight) : Enemy(x, y) {
    initSprite("../resources/slime.png", {0,0,16,10});
    setAnimValues({0,0}, {16,10}, 4, 0.3, true);
    initHitbox({16*3, 10*3});
    initPath(pathPointA, pathPointB);
    this->movingRight = moveRight;

    setMaxHP(5);
    defaultInvincibilityTime = 0.2f;
}

void Slime::update(float deltaSeconds) {
    _sprite.setPosition(getPosition().x, getPosition().y);
    animate(_sprite);

    if (isDead()) {
        setPosition(0, -100);
    }

    updateInvincibilityTimer(deltaSeconds);
    moveHorizontal(100 * deltaSeconds); //30
}

void Slime::render(sf::RenderTarget &window) {
    window.draw(_sprite);

    //window.draw(_hitbox);
    //window.draw(_path);
}

void Slime::initPath(float pointA, float pointB) {
    _path.setPosition(pointA, 10);
    _path.setSize({pointB-pointA, 1});

    _path.setOutlineColor(sf::Color::Green);
    _path.setOutlineThickness(1);
}
