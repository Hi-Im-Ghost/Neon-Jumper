#ifndef TREES_JSON_LEVELTWOSTATE_H
#define TREES_JSON_LEVELTWOSTATE_H

#include "GameState.h"
#include "../entities/Player.h"
#include "../LoadMap.h"
#include "../entities/Slime.h"

/**
 * @class Stan aplikacji obsługujący drugi poziom gry
 */

class LevelTwoState : public GameState {
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

    ///zmienna okreslajaca czy jestesmy na lvl2
    bool level2;
    ///zmienna okreslajaca czas widocznosci hud
    int i = 1;
    ///zmienna okreslajaca czas widocznosci hud
    int x = 1;

    /// Obszar wykrywający czy gracz przeszedł poziom
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
    /// Inicjalizacja przycisków ekranu końcowego gry
    void initEndButtons();
    /// Inicjalizacja obszaru zakończenia gry
    void initEndTrigger();
    ///
    void initView(sf::RenderTarget& window);
    /// Inicjalizacja kamery gracza
    void initViewPlayer(sf::RenderTarget &window);
    /// Rozmieszczenie wrogów na mapie
    void initEnemies();

    /// Czytanie klawiatury i wykonywanie odpowiednich operacji
    void updateInput();
    /// Aktualizacja logiki gry podczas, gdy jest zapauzowana
    void updatePaused();
    /// Aktualizacja logiki po zakończeniu gry
    void updateEnd();
    /// Aktualizacja logiki wrogów na mapie
    void updateEntities(float deltaTime);
    /// Wyświetlanie na ekranie elementów, gdy rozgrywka jest spauzowana
    void renderPaused(sf::RenderTarget& window);
    /// Wyświetlanie elementów gdy gracz zakończy grę
    void renderEnd(sf::RenderTarget& window);
    /// Wyświetlanie przeciwników i gracza na ekranie
    void renderEntities(sf::RenderTarget& window);

    /// Sprawdza, czy gracz nie wszedł na teren obszaru kończącego poziom
    void updateEndTrigger();
    /// Sprawdza czy gracz nie wszedł na teren obszaru zadającego obrażenia
    void updateDmgTriggers();
    ///
    void killPlayerTriggers();

    /// Zapisuje grę
    void saveGame();

protected:
// Duplicates

public:
    /// Konstruktor przyjmujący odniesienie do stosu stanów aplikacji
    explicit LevelTwoState(std::stack<GameState*>* states);

    /// Odświeża logikę stanu
    void update(float deltaTime) override;
    /// Wyświetla elementy stanu na ekranie
    void render(sf::RenderTarget& window) override;

    /// Wczytuje grę
    void loadGame();
};


#endif //TREES_JSON_LEVELTWOSTATE_H
