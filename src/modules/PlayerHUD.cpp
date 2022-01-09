#include "PlayerHUD.h"


PlayerHUD::PlayerHUD() {
    initHeartTexture();
    initHearts();
}

void PlayerHUD::initHearts() {
    for (int i=0; i<3; i++)
    {
        hearths[i].setSize({100, 100});
        //hearths[i].setFillColor(sf::Color::Red);
        //hearths[i].setOutlineThickness(3);
        //hearths[i].setOutlineColor(sf::Color::Red);
        hearths[i].setTexture(&htfull);
        float newX = 20 + (150 * i);
        hearths[i].setPosition({newX, 20});
    }
}

void PlayerHUD::render(sf::RenderTarget &window) {
    for (int i=0; i<3; i++)
        window.draw(hearths[i]);
}

void PlayerHUD::update(Damageable *damageableModule) {
    int hp = damageableModule->getHP();
    for (int i=0; i<3; ++i)
    {
        if (i < hp)
            hearths[i].setTexture(&htfull);
        else
            hearths[i].setTexture(&htempty);
    }

}

void PlayerHUD::initHeartTexture() {
    htfull.loadFromFile("../resources/hfull.png");
    htempty.loadFromFile("../resources/hempty.png");
}

void PlayerHUD::setPosition(float x) {
        hearths[0].setPosition({x, 20});
        hearths[1].setPosition({x+100, 20});
        hearths[2].setPosition({x+200, 20});
}
