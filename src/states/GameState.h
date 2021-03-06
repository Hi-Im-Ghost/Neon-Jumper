#ifndef TREES_JSON_GAMESTATE_H
#define TREES_JSON_GAMESTATE_H


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Audio.hpp>
#include <stack>
#include "../UI/Button.h"
#include "../modules/PlayerHUD.h"

/**
 * @class Każdy stan aplikacji dziedziczy po tej klasie
 */
class GameState {
private:
    ///Zmienna która komunikuje o wczytaniu gry z menu
    static bool menuLoad;
    ///Zmienna określająca czy wczytaliśmy grę
    static bool loadSave;
protected:
    /// Tekst przechowujący napis do gry
    sf::Text nameTextGame;
    /// Tekst przechowujący napis do pauzy
    sf::Text nameTextPause;
    /// Tekst przechowujący napis do instrukcji gry
    sf::Text nameTextPlay;
    /// Czciona używana do tekstu gry
    sf::Font nameFontGame;
    /// Przechowuje muzykę graną w menu
    sf::Music musicMenu;
    /// Przechowuje muzykę graną podczas gry
    sf::Music musicGame;
    /// Buffor dla dzwieku klikania
    sf::SoundBuffer buf;
    /// Buffor dla dzwieku zwycienstwa
    sf::SoundBuffer bufOh;
    /// Buffor dla dzwieku cheatowania
    sf::SoundBuffer bufCheat;
    /// Buffor dla dzwieku smierci gracza
    sf::SoundBuffer bufdeath;
    /// Buffor dla dzwieku trafienia
    sf::SoundBuffer bufHit;
    /// Przechowuje dźwięk naciśnięcia przycisku
    sf::Sound clickMenu;
    /// Przechowuje dźwięk smierci gracza
    sf::Sound deathGame;
    /// Przechowuje dźwięk uzycia cheatu
    sf::Sound cheatGame;
    /// Przechowuje dźwięk trafienia
    sf::Sound hitGame;
    /// Przechowuje dźwięk zwycienstwa
    sf::Sound ohGame;
    /// Przechowuje pozycję kursora myszy na ekranie
    sf::Vector2f mousePosition;
    /// Określa, czy należy już wyjść ze stanu
    bool bEndState = false;
    /// Określa, czy zakonczylismy gre
    bool bEndGame = false;
    /// Określa, czy stan jest zatrzymany
    bool bPaused = false;
    /// Określa, czy stan pierwszego poziomu chce przejść do drugiego poziomu
    bool bnextLevel = false;
    /// Stos stanów aplikacji. Zawsze używany jest najwyższy stan na stosie
    std::stack<GameState*>* states;
    /// Kursor wirtualny, czyli hitbox służący do wykrywania obiektów pod kursorem myszy
    sf::RectangleShape virtualCursor;

    ///Zmienna sprawdzająca aktualny lvl
    int checkLevel;
    ///Zmienna do której zapisywana jest pozycja x gracza dla zapisu stanu gry i wczytywania
    float playerPositionX;
    ///Zmienna do której zapisywana jest pozycja y gracza dla zapisu stanu gry i wczytywania
    float playerPositionY;
    ///Zmienna do której zapisywana jest ilość hp gracza dla zapisu stanu gry i wczytywania
    int playerHP;

    /// Pozwala na aktualizowanie pozycji myszy na ekranie
    void updateMousePosition();
    /// Pozwala zakomunikować o potrzebie zatrzymania stanu
    void pause() {bPaused = true;}
    /// Pozwala zakomunikować o potrzebie wznowienia stanu
    void unpause() {bPaused = false;}
    /// Pozwala zakomunikować o koncu gry
    void endGame() {bEndGame = true;}
    /// Pozwala zakomunikować o zmianie stanu konca gry
    void unEndGame() {bEndGame = false;}

    /// Inicjuje wirtualny kursor
    void initVirtualCursor();
    /// Odświeża kursor wirtualny do pozycji kursora myszy
    void updateVirtualCursor();
    /// Inicjuje muzykę menu
    void initMusicMenu();
    /// Inicjuje dźwięki przycisków menu
    void initSoundMenu();
    /// Inicjuje muzykę podczas gry
    void initMusicGame();
    /// Inicjacja tekstu do gry
    void initTextGame();
    /// Inicjacja tekstu do pauzy
    void initTextPause();
    /// Inicjacja tekstu do instrukcji gry
    void initTextPlay();

public:
    /** Konstruktor przyjmuje odniesienie do stosu wszystkich stanów
     * @param states odniesienie do stosu wszystkich stanów aplikacji
     */
    explicit GameState(std::stack<GameState*>* states);

    /// Komunikuje o chęci zakończenia stanu
    void endState();
    /// Pozwala uzyskać informację, czy należy zakończyć stan
    bool getEndState() const {return bEndState;}
    /// Pozwala przejść do drugiego poziomu gry
    bool getGoNextLevel() const {return bnextLevel;}
    //bool isPaused() const {return bPaused;}

    /** Funkcja zarządzająca odświeżaniem logiki stanu
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    virtual void update(float deltaTime) = 0;
    /** Funkcja zarządzająca renderowaniem grafiki stanu
     * @param window okno na którym wyświetlony zostanie przeciwnik
     */
    virtual void render(sf::RenderTarget& window) {};
    /** Funkcja, która pozwala nam na zakomunikowaniu że wczytaliśmy grę z menu
     * @param bool parametr którego ustawiamy na true bądź false
     */
    static void setLoadMenu(bool);
    /*** Funkcja, która zwraca nam wartość zmiennej menuLoad
     * @return zwraca wartość menuLoad, jeśli wynosi true gra zostanie wczytana, jeśli false to nie
     */
    bool getLoadMenu(){return GameState::menuLoad;}
    /** Funkcja, która pozwala nam na zakomunikowaniu że wczytaliśmy grę z menu
 * @param bool parametr którego ustawiamy na true bądź false
 */
    static void setLoadSave(bool);
    /** Funkcja, która zwraca nam wartość zmiennej menuLoad
     * @return zwraca wartość menuLoad, jeśli wynosi true gra zostanie wczytana, jeśli false to nie
     */
    bool getLoadSave(){return GameState::loadSave;}
};


#endif //TREES_JSON_GAMESTATE_H
