//
// Created by ToQly on 04.01.2022.
//

#ifndef TREES_JSON_ANIMATED_H
#define TREES_JSON_ANIMATED_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class Animated {
public:
    enum Animation {
        IDLE,
        WALK,
        JUMP,
        FALL
    };

private:
    sf::Vector2i _frameSize;
    sf::Vector2i _frameOrigin;
    bool _bLooping;
    int _maxFrameNumber;

    int _startingX;
    int _frameY;

    Animation _currAnim;

    void setFrame(sf::Sprite& sprite);


    /// Przechowuje obecną klatkę animacji
    // sf::IntRect currFrame;
    /// Przechowuje indeks obecnej klatki animacji
    int currFrameNumber = 1;
    /// Mierzy czas jaki upłynął od ostatniej klatki animacji
    sf::Clock _animClock;
    /// Określa czas jaki musi upłynąć, by zmienić klatkę animacji
    float frameIntervalTime = 0.7f;
protected:
    void setAnimValues(sf::Vector2i frameOrigin, sf::Vector2i frameSize, int frameCount, float intervalTime, bool isLooping);

public:
    /// Służy do animacji przekazanego sprite-a
    void animate(sf::Sprite& sprite, bool noWait = false);
    void switchAnimation(Animation newAnimation);
    Animation getCurrentAinmation() {return _currAnim;}
};


#endif //TREES_JSON_ANIMATED_H
