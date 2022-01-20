#ifndef TREES_JSON_ANIMATED_H
#define TREES_JSON_ANIMATED_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

/**
 * @class Przedstawia obiekt, którego sprite może być animowany
 */
class Animated {
public:
    /// Enumerator reprezentujący dostępne animacje
    enum Animation {
        IDLE,     ///< Animacja stania w miejscu
        WALK,     ///< Animacja chodzenia
        JUMP,     ///< Animacja skakania
        FALL      ///< Animacja spadania
    };

private:
    /// Rozmiar pojedynczej klatki animacji
    sf::Vector2i _frameSize;
    /// Lewy-górny punkt obecnej klatki animacji
    sf::Vector2i _frameOrigin;
    /// Określa czy animacja powinna się zapętlać
    bool _bLooping;
    /// Określa ile klatek powinna mieć obecna animacja
    int _maxFrameNumber;
    /// Pozycja x klatki animacji od której powinna się zacząć animacji
    int _startingX;

    /// Obecnie używana animacja
    Animation _currAnim;

    /** Wczytuje następną klatkę i aktualizuje podany sprite
     * @param sprite sprite do animacji
     */
    void setFrame(sf::Sprite& sprite);

    /// Mierzy czas jaki upłynął od ostatniej klatki animacji
    sf::Clock _animClock;
    /// Określa czas jaki musi upłynąć, by zmienić klatkę animacji
    float frameIntervalTime = 0.7f;
protected:
    /** Ustawia wartości animacji, które używane będą przy animowaniu. Używane przy zmianie animacji
     * @param frameOrigin pozycja lewego-górnego punktu klatki na teksturze
     * @param frameSize rozmiar klatki animacji
     * @param frameCount ilość klatek do animacji
     * @param intervalTime czas pomiędzy klatkami animacji
     * @param isLooping czy animacja powinna się zapętlać
     */
    void setAnimValues(sf::Vector2i frameOrigin, sf::Vector2i frameSize, int frameCount, float intervalTime, bool isLooping);

    /// Określa czy sprite jest obrócony w drugą stronę
    bool _bIsFlipped;
public:
    /** Animuje przekazanego sprite-a z odpowiednią częstotliwością
     * @param sprite sprite do animacji
     * @param noWait ignoruj intervalTime i animuj klatkę od razu
     */
    void animate(sf::Sprite& sprite, bool noWait = false);

    /** Zmienia obecną animację na podaną w argumencie
     * @param newAnimation nowa animacja
     */
    virtual void switchAnimation(Animation newAnimation);
    /** Pobiera obecnie używaną animację
     * @return obecnie używana animacja
     */
    Animation getCurrentAinmation() {return _currAnim;}
};


#endif //TREES_JSON_ANIMATED_H
