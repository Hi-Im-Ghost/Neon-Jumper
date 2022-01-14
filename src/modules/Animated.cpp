#include <iostream>
#include "Animated.h"

void Animated::animate(sf::Sprite &sprite, bool noWait) {
/*
    sf::IntRect currFrame = sprite.getTextureRect();
    int x = currFrame.width * (currFrameNumber - 1);
    int y = currFrame.height * (animRow - 1);

    if (animClock.getElapsedTime().asSeconds() >= frameIntervalTime) {
        //Next frame
        currFrameNumber++;
        if (currFrameNumber <= maxFrameNumber) {
            x += currFrame.width;
        } else if (loop) {
            x = 0;
            currFrameNumber = 1;
        } else {
            currFrameNumber = maxFrameNumber;
            return;
        }

        currFrame = sf::IntRect(x, y, currFrame.width, currFrame.height);
        sprite.setTextureRect(currFrame);

        //Restart clock
        animClock.restart();
    }
*/
    /// Sprawdza, czy czas, który upłynął od ostatniej klatki animacji jest większy niż czas pomiędzy klatkami
    if (_animClock.getElapsedTime().asSeconds() > frameIntervalTime || noWait) {
        setFrame(sprite);
        ///resetuje zegar animacji
        _animClock.restart();
    }
}

void Animated::setFrame(sf::Sprite& sprite) {
    /// Zmienia teksturę źródłową sprite na taką o zadanych współrzędnych
    sprite.setTextureRect(sf::IntRect(
            _frameOrigin.x + ( (_bIsFlipped) ? _frameSize.x : 0 ),
            _frameOrigin.y,
            _frameSize.x * ( (_bIsFlipped) ? -1 : 1 ),
            _frameSize.y)
    );
    ///przesuwa ramkę o jedną klatkę do przodu
    _frameOrigin.x += _frameSize.x;
    /// Jeżeli współrzędne następnej klatki wychodzą poza rozmiar tekstury, przejdź do początkowej klatki
    if (_frameOrigin.x >= _frameSize.x * _maxFrameNumber)
        _frameOrigin.x = _startingX;
}

void Animated::setAnimValues(sf::Vector2i frameOrigin, sf::Vector2i frameSize, int frameCount, float intervalTime, bool isLooping) {
    _frameOrigin = frameOrigin;
    _frameSize = frameSize;

    _maxFrameNumber = frameCount;
    _startingX = frameOrigin.x;
    frameIntervalTime = intervalTime;
    _bLooping = isLooping;
}

void Animated::switchAnimation(Animation newAnimation) {
    switch (newAnimation) {

        case IDLE:
            _currAnim = IDLE;
            break;
        case WALK:
            _currAnim = WALK;
            break;
        case JUMP:
            _currAnim = JUMP;
            break;
        case FALL:
            _currAnim = FALL;
            break;
    }
}
