#include "PlayerHUD.h"


PlayerHUD::PlayerHUD() {
    initTexture();
    initHearts();
    initStopTime();
    takedDmg = false;
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

void PlayerHUD::initStopTime() {
    stopwatch.setSize({50, 50});
    stopwatch.setTexture(&stopTime);
    stopwatch.setPosition({50, 20});
}

void PlayerHUD::render(sf::RenderTarget &window) {
    for (int i=0; i<3; i++) {
        window.draw(hearths[i]);
    }
    window.draw(stopwatch);
}

void PlayerHUD::update(Damageable *damageableModule,bool playerReady) {
    int hp = damageableModule->getHP();
    for (int i=0; i<3; ++i)
    {
        if(takedDmg) {
            if (i < hp) {
                hearths[i].setFillColor(sf::Color::White);
                hearths[i].setTexture(&htfull);
            }
            else
                hearths[i].setFillColor(sf::Color::Transparent);
        }else
            hearths[i].setFillColor(sf::Color::Transparent);
    }
    if(playerReady){
        stopwatch.setFillColor(sf::Color::White);
        stopwatch.setTexture(&stopTime);
    }else{
        stopwatch.setFillColor(sf::Color::Transparent);
    }

}

void PlayerHUD::initTexture() {
    htfull.loadFromFile("../resources/hfull.png");
    stopTime.loadFromFile("../resources/stopTime.png");
}

void PlayerHUD::setPosition(float x,float y) {
        hearths[0].setPosition({x-50, y-75});
        hearths[1].setPosition({x, y-75});
        hearths[2].setPosition({x+50, y-75});
        stopwatch.setPosition(x-75,y);
}
