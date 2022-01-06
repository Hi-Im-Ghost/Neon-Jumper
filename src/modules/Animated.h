//
// Created by ToQly on 04.01.2022.
//

#ifndef TREES_JSON_ANIMATED_H
#define TREES_JSON_ANIMATED_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class Animated {
private:
    /// Przechowuje obecną klatkę animacji
    sf::IntRect currFrame;
    /// Przechowuje indeks obecnej klatki animacji
    int currFrameNumber = 1;
    /// Mierzy czas jaki upłynął od ostatniej klatki animacji
    sf::Clock animClock;
    /// Określa czas jaki musi upłynąć, by zmienić klatkę animacji
    float frameIntervalTime = 0.7f;

public:
    /// Służy do animacji przekazanego sprite-a
    void animate(sf::Sprite& sprite, int animRow, int maxFrameNumber);
};


#endif //TREES_JSON_ANIMATED_H
