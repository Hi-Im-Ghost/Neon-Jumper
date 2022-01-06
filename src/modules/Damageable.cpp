#include "Damageable.h"

void Damageable::takeDamage(int damage) {
    if (!_bIsInvincible) {
        _bIsInvincible = true;
        hp -= damage;
        if (hp < 0)
            hp = 0;
    }
}

void Damageable::setMaxHP(unsigned int newMax) {
    maxHP = newMax;
}

void Damageable::setHP(unsigned int newHP) {
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
            invTime = 1.0f;
            _bIsInvincible = false;
        }
    }
    else
    {
        invTime = 1.0f;
    }
}

bool Damageable::isDead() {
    if(hp < 1)
        return true;
    else
        return false;
}

