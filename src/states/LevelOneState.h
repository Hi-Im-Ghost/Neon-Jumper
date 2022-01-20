#ifndef TREES_JSON_LEVELONESTATE_H
#define TREES_JSON_LEVELONESTATE_H


#include "GameState.h"
#include "../LoadMap.h"
#include "../entities/Player.h"
#include "LevelTwoState.h"
#include "../modules/PlayerHUD.h"
#include "../entities/Slime.h"

/**
 * @class Stan aplikacji obsługujący pierwszy poziom gry
 */
class LevelOneState : public GameState {
private:
    /// Odniesienie do obiektu gracza
    Player* player;
    /// Lista hitboxów otoczenia
    std::list<sf::RectangleShape> hitboxes;
    /// Lista obszarów zadających obrażenia
    std::list<sf::RectangleShape> dmgboxes;
    /// Odniesienie do wybranej przez nas mapy
    LoadMap map;

    /// Lista odniesień do wszystkich wrogów
    std::list<Enemy*> enemies;

    /// Odniesienie do przycisku wyjścia do menu
    Button* endMenuBtn;
    /// Odniesienie do przycisku powrotu do rozgrywki
    Button* pauseResumeBtn;
    /// Odniesienie do przycisku wyjścia do menu
    Button* pauseExitBtn;
    /// Odniesienie do przycisku wczytania zapisu gry
    Button* loadBtn;
    /// Odniesienie do przycisku zapisu gry
    Button* saveBtn;
    /// Zmienna debug służąca do renderowania hitbox-ów
    bool renderHitboxes = false;
    ///zmienna okreslajaca czas widocznosci hud
    int i = 1;
    ///zmienna okreslajaca czas widocznosci hud
    int x = 1;


    /// Obszar wykrywający czy gracz powinien przejść do następnego poziomu
    sf::RectangleShape endLevelTrigger;
    /// Odniesienie do interfejsu użytkownika
    PlayerHUD* hud;

    /// Inicjalizacja podstawowych wartości klasy
    void initValues();
    /// Rozmieszczenie hitboxów na mapie
    void initHitboxes();
    /// Rozmieszczenie obszarów zadających obrażenia na mapie
    void initDmgBoxes();
    /// Inicjalizacja przycisków menu pauzy
    void initPauseButtons();
    /// Inicjalizacja przycisków na ekranie śmierci
    void initDeadButtons();
    /// Inicjalizacja obszaru przejścia do następnego poziomu
    void initEndTrigger();
    /** Inicjalizacja kamery dla menu pauzy
     * @param window
     */
    void initView(sf::RenderTarget& window);
    /** inicjalizacja kamery gracza
     * @param window
     */
    void initViewPlayer(sf::RenderTarget &window);
    /// Rozmieszczenie wrogów na mapie
    void initEnemies();

    /// Czytanie klawiatury i wykonywanie odpowiednich operacji
    void updateInput();
    /// Aktualizacja logiki gry podczas, gdy jest zapauzowana
    void updatePaused();
    /// Aktualizacja logiki gry podczas, gdy postać straci wszystkie punkty życia
    void updateDead();
    /** Aktualizacja logiki przeciwników
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    void updateEntities(float deltaTime);
    /** Wyświetlanie na ekranie elementów, gdy rozgrywka jest spauzowana
     * @param window okno na którym elementy mają być wyświetlane
     */
    void renderPaused(sf::RenderTarget& window);
    /** Wyświetlanie elementów gdy gracz nie żyje
     * @param window okno na którym elementy mają być wyświetlane
     */
    void renderDead(sf::RenderTarget& window);
    /** Wyświetlanie przeciwników i gracza na ekranie
     * @param window okno na którym elementy mają być wyświetlane
     */
    void renderEntities(sf::RenderTarget& window);

    /// Sprawdza czy gracz nie wszedł na teren obszaru kończącego poziom
    void updateEndTrigger();
    /// Sprawdza czy gracz zginął, jeśli tak to zostanie wyrenderowany ekran śmierci
    void updateDeadTrigger();
    /// Sprawdza czy gracz nie wszedł na teren obszaru zadającego obrażenia
    void updateDmgTriggers();
    /// Sprawdza czy gracz nie utonął, jeśli tak to zabija go
    void killPlayerTriggers();

    /// Zapisuje stan gry
    void saveGame();
    /// Wczytuje stan gry
    void loadGame();

public:
    /** Konstruktor przyjmujący odniesienie do stosu stanów aplikacji
     * @param states odniesienie do stosu wszystkich stanów aplikacji
     */
    explicit LevelOneState(std::stack<GameState*>* states);

    /** Odświeża logikę stanu
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    void update(float deltaTime) override;
    /** Wyświetla elementy stanu na ekranie
     * @param window okno na którym elementy mają być wyświetlane
     */
    void render(sf::RenderTarget& window) override;
};

#endif //TREES_JSON_LEVELONESTATE_H
