#include "Projectile.h"

Projectile::Projectile(sf::Vector2f pos, bool movingRight) {
    setPosition(pos.x, pos.y);
    _bMovingRight = movingRight;

    _hitbox.setSize({16,16});
}

void Projectile::initTexture(const std::string& path, sf::IntRect textureRect) {
    _texture.loadFromFile(path);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(textureRect);

    _sprite.setScale(3.0f, 3.0f);
}

void Projectile::render(sf::RenderTarget &window) {
    window.draw(_sprite);
}

void Projectile::update(float deltaTime) {
    _sprite.setPosition(getPosition());
}

sf::Vector2f Projectile::getPosition() {
    return _hitbox.getPosition();
}

void Projectile::setPosition(float x, float y) {
    _hitbox.setPosition(x,y);
}

bool Projectile::isColliding(const sf::RectangleShape &recShape) {
    return _hitbox.getGlobalBounds().intersects(recShape.getGlobalBounds());
}
