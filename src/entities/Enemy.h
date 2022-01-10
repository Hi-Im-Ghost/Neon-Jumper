#ifndef TREES_JSON_ENEMY_H
#define TREES_JSON_ENEMY_H

#include "../modules/Damageable.h"
#include "../modules/Animated.h"

class Enemy : public Damageable, public Animated {
protected:
    sf::Texture _texture;
    sf::Sprite _sprite;
    sf::RectangleShape _hitbox;
    sf::RectangleShape _path;
    bool movingRight = false;
    int spriteOffset;

    void initSprite(const std::string& filePath, sf::IntRect frame);
    void initHitbox(sf::Vector2f size);
    virtual void initPath(float pointA, float pointB) = 0;

    void setPosition(float x, float y);
public:
    explicit Enemy(float x = 0, float y = 0);

    void moveHorizontal(float x);
    sf::Vector2f getPosition();
    sf::RectangleShape& getHitbox() {return _hitbox;}

    virtual void update(float deltaSeconds) = 0;
    virtual void render(sf::RenderTarget& window) = 0;
};


#endif //TREES_JSON_ENEMY_H
