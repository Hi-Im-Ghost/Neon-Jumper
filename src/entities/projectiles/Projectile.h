#ifndef TREES_JSON_PROJECTILE_H
#define TREES_JSON_PROJECTILE_H

#include <SFML/Graphics.hpp>

class Projectile {
private:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::RectangleShape _hitbox;

    bool _bMovingRight;
    bool _bShouldBeDestroyed = false;

protected:
    virtual void move(float x, float y) = 0;
    void setPosition(float x, float y);
    void markForDestruction() {_bShouldBeDestroyed = true;}

    void initTexture(const std::string& path, sf::IntRect textureRect);
public:
    Projectile(sf::Vector2f pos, bool movingRight);

    sf::Vector2f getPosition();
    bool getIsMovingRight() const {return _bMovingRight;}
    bool getShouldBeDestroyed() const {return _bShouldBeDestroyed;}

    virtual void update(float deltaTime);
    void render(sf::RenderTarget& window);
};


#endif //TREES_JSON_PROJECTILE_H
