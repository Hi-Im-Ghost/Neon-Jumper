//
// Created by ToQly on 04.01.2022.
//

#ifndef TREES_JSON_PLAYERHUD_H
#define TREES_JSON_PLAYERHUD_H


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Damageable.h"

class PlayerHUD {
private:
    sf::RectangleShape hearths[3];
    sf::Texture htfull;

    void initHeartTexture();
    void initHearts();

protected:

public:
    PlayerHUD();

    void render(sf::RenderTarget& window);
    void update(Damageable* damageableModule);
    void setPosition(float x, float y);
    bool takedDmg;
};


#endif //TREES_JSON_PLAYERHUD_H
