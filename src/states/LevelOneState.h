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
    ///
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
    ///
    void initView(sf::RenderTarget& window);
    /// inicjalizacja kamery gracza
    void initViewPlayer(sf::RenderTarget &window);
    /// Rozmieszczenie wrogów na mapie
    void initEnemies();

    /// Czytanie klawiatury i wykonywanie odpowiednich operacji
    void updateInput();
    /// Aktualizacja logiki gry podczas, gdy jest zapauzowana
    void updatePaused();
    /// Aktualizacja logiki gry podczas, gdy postać straci wszystkie punkty życia
    void updateDead();
    /// Aktualizacja logiki przeciwników
    void updateEntities(float deltaTime);
    /// Wyświetlanie na ekranie elementów, gdy rozgrywka jest spauzowana
    void renderPaused(sf::RenderTarget& window);
    /// Wyświetlanie elementów gdy gracz nie żyje
    void renderDead(sf::RenderTarget& window);
    /// Wyświetlanie przeciwników i gracza na ekranie
    void renderEntities(sf::RenderTarget& window);

    /// Sprawdza czy gracz nie wszedł na teren obszaru kończącego poziom
    void updateEndTrigger();
    ///
    void updateDeadTrigger();
    /// Sprawdza czy gracz nie wszedł na teren obszaru zadającego obrażenia
    void updateDmgTriggers();
    ///
    void killPlayerTriggers();

    /// Zapisuje stan gry
    void saveGame();
    /// Wczytuje stan gry
    void loadGame();

public:
    /// Konstruktor przyjmujący odniesienie do stosu stanów aplikacji
    explicit LevelOneState(std::stack<GameState*>* states);

    /// Odświeża logikę stanu
    void update(float deltaTime) override;
    /// Wyświetla elementy stanu na ekranie
    void render(sf::RenderTarget& window) override;
};

#endif //TREES_JSON_LEVELONESTATE_H
