#include "Enemy.h"

Enemy::Enemy(float x, float y) {
    setPosition(x,y);
}

void Enemy::initSprite(const std::string& filePath, sf::IntRect frame) {
    _texture.loadFromFile(filePath);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(frame);
    _sprite.setScale(3,3);
}

void Enemy::initHitbox(sf::Vector2f size) {
    _hitbox.setSize(size);
    _hitbox.setOutlineColor(sf::Color::Red);
    _hitbox.setFillColor(sf::Color::Transparent);
    _hitbox.setOutlineThickness(1);
}

void Enemy::setPosition(float x, float y) {
    _hitbox.setPosition(x,y);
}

sf::Vector2f Enemy::getPosition() {
    return _hitbox.getPosition();
}

void Enemy::moveHorizontal(float x) {
    if (movingRight) {
        _sprite.setScale(-3, 3);
        spriteOffset = _sprite.getTextureRect().width * 3;
        setPosition(getPosition().x + x, getPosition().y);
    } else {
        _sprite.setScale(3, 3);
        spriteOffset = 0;
        setPosition(getPosition().x - x, getPosition().y);
    }

    if (getPosition().x < _path.getGlobalBounds().left)
        movingRight = true;
    else if (getPosition().x > _path.getGlobalBounds().left + _path.getGlobalBounds().width)
        movingRight = false;
}
