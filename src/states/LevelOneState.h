//
// Created by ToQly on 30.12.2021.
//

#ifndef TREES_JSON_LEVELONESTATE_H
#define TREES_JSON_LEVELONESTATE_H


#include "GameState.h"
#include "../LoadMap.h"
#include "../entities/Player.h"
#include "LevelTwoState.h"
#include "../modules/PlayerHUD.h"

class LevelOneState : public GameState {
private:
    Player* player;
    std::list<sf::RectangleShape> hitboxes;
    std::list<sf::RectangleShape> dmgboxes;
    LoadMap map;

    Button* endMenuBtn;
    Button* pauseResumeBtn;
    Button* pauseExitBtn;
    Button* loadBtn;
    Button* saveBtn;
    bool renderHitboxes = false;
    PlayerHUD* hud;

    sf::RectangleShape endLevelTrigger;

    void initValues();
    void initHitboxes();
    void initDmgBoxes();
    void initPauseButtons();
    void initDeadButtons();
    void initEndTrigger();
    void initView(sf::RenderTarget& window);
    void initViewPlayer(sf::RenderTarget &window);

    void updateInput();
    void updatePaused();
    void updateDead();
    void renderPaused(sf::RenderTarget& window);
    void renderDead(sf::RenderTarget& window);

    void updateEndTrigger();
    void updateDeadTrigger();
    void updateDmgTriggers();
    void killPlayerTriggers();

    void saveGame();
    void loadGame();

public:
    explicit LevelOneState(std::stack<GameState*>* states);

    void update(float deltatime) override;
    void render(sf::RenderTarget& window) override;
};

#endif //TREES_JSON_LEVELONESTATE_H
