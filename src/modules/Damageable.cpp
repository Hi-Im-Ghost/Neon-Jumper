#include "Damageable.h"

void Damageable::takeDamage(int damage) {
    if (!_bIsInvincible) {
        _bIsInvincible = true;
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }
}

void Damageable::setMaxHP(int newMax) {
    maxHP = newMax;
    setHP(maxHP);
}

void Damageable::setHP(int newHP) {
    hp = newHP;
}

int Damageable::getHP() const {
    return hp;
}

int Damageable::getMaxHP() const {
    return maxHP;
}

void Damageable::updateInvincibilityTimer(float dt) {
    if (_bIsInvincible)
    {
        invTime -= dt;
        if (invTime < 0.0f)
        {
            invTime = defaultInvincibilityTime;
            _bIsInvincible = false;
        }
    }
    else
    {
        invTime = defaultInvincibilityTime;
    }
}

bool Damageable::isDead() const {
    return hp < 1;
}

