#include "PlayerHUD.h"


PlayerHUD::PlayerHUD() {
    initHeartTexture();
    initHearts();
    takedDmg=false;
}

void PlayerHUD::initHearts() {
    for (int i=0; i<3; i++)
    {
        hearths[i].setSize({50, 50});
        //hearths[i].setFillColor(sf::Color::Red);
        //hearths[i].setOutlineThickness(3);
        //hearths[i].setOutlineColor(sf::Color::Red);
        hearths[i].setTexture(&htfull);
        float newX = 20 + (150 * i);
        hearths[i].setPosition({newX, 20});
    }
}

void PlayerHUD::render(sf::RenderTarget &window) {
    for (int i=0; i<3; i++) {
        window.draw(hearths[i]);
    }
}

void PlayerHUD::update(Damageable *damageableModule) {
    int hp = damageableModule->getHP();
    for (int i=0; i<3; ++i)
    {
        if(takedDmg) {
            if (i < hp)
                hearths[i].setTexture(&htfull);
            else
                hearths[i].setFillColor(sf::Color::Transparent);
        }else{
            hearths[i].setFillColor(sf::Color::Transparent);
        }
    }

}

void PlayerHUD::initHeartTexture() {
    htfull.loadFromFile("../resources/hfull.png");
}

void PlayerHUD::setPosition(float x,float y) {
        hearths[0].setPosition({x-50, y-75});
        hearths[1].setPosition({x, y-75});
        hearths[2].setPosition({x+50, y-75});
}
