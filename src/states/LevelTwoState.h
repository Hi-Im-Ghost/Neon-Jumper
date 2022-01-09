#ifndef TREES_JSON_LEVELTWOSTATE_H
#define TREES_JSON_LEVELTWOSTATE_H

#include "GameState.h"
#include "../entities/Player.h"
#include "../LoadMap.h"
#include "../modules/PlayerHUD.h"

class LevelTwoState : public GameState {
private:
    // Duplicates
    Player* player;
    std::list<sf::RectangleShape> hitboxes;
    std::list<sf::RectangleShape> dmgboxes;
    LoadMap map;
    PlayerHUD* hud;

    Button* endMenuBtn;
    Button* pauseResumeBtn;
    Button* pauseExitBtn;
    Button* saveBtn;
    Button* loadBtn;
    bool renderHitboxes = false;

    bool level2;

    sf::RectangleShape endLevelTrigger;

    void initValues();
    void initHitboxes();
    void initDmgBoxes();
    void initPauseButtons();
    void initEndButtons();
    void initEndTrigger();
    void initView(sf::RenderTarget& window);
    void initViewPlayer(sf::RenderTarget &window);

    void updateInput();
    void updatePaused();
    void updateEnd();
    void renderPaused(sf::RenderTarget& window);
    void renderEnd(sf::RenderTarget& window);

    void updateEndTrigger();
    void updateDmgTriggers();
    void killPlayerTriggers();

    void saveGame();

public:
    explicit LevelTwoState(std::stack<GameState*>* states);

    void update(float deltaTime) override;
    void render(sf::RenderTarget &window) override;

    void loadGame();
};


#endif //TREES_JSON_LEVELTWOSTATE_H