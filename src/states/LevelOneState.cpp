#include "LevelOneState.h"

LevelOneState::LevelOneState(std::stack<GameState*>* states)
        : GameState(states), map("mapa.json") {
    initValues();
    initHitboxes();
    initDmgBoxes();
    initEndTrigger();
    initEnemies();
    initDeadButtons();
    initPauseButtons();
    initVirtualCursor();
    initTextGame();
    initTextPlay();
    initTextPause();
    musicGame.play();
    if(GameState::getLoadMenu()){
        loadGame();
        unpause();
        GameState::setLoadMenu(false);
        if(checkLevel==1){
            musicGame.stop();
        }else
            musicGame.play();
    }
}

void LevelOneState::initValues() {
    player = new Player(10*3, 250*3);
    hud = new PlayerHUD();
}

void LevelOneState::update(float dt) {
    if (!bPaused && !bEndGame) {
        updateInput();
        if (!player->getTimeStopped())
            updateEntities(dt);

        player->update(dt, hitboxes);

        // triggers
        updateEndTrigger();
        updateDmgTriggers();
        updateDeadTrigger();
        killPlayerTriggers();

        // hud
        hud->setPosition(player->getPosition().x,player->getPosition().y);
        hud->update(player,player->bTimeStopReady);
    } else{
        if(bPaused)
            updatePaused();
        else
            updateDeadTrigger();
    }
}

void LevelOneState::render(sf::RenderTarget &window) {

    initViewPlayer(window);
    map.draw(window);
    window.draw(nameTextPlay);
    renderEntities(window);
    hud->render(window);

    if (renderHitboxes) {
        for (auto & h : hitboxes)
            window.draw(h);
        for (auto & h : dmgboxes)
            window.draw(h);
        window.draw(endLevelTrigger);
    }

    if(bPaused)
        renderPaused(window);

    if(bEndGame){
        renderDead(window);
    }
}

void LevelOneState::initHitboxes() {

    Layer solidLayer = map.getSolidLayer();
    std::vector<LayerObject> objects = solidLayer.getObjects();

    sf::RectangleShape hb;
    hb.setOutlineColor(sf::Color::Blue);
    hb.setFillColor(sf::Color::Transparent);
    hb.setOutlineThickness(1);

    for (auto & obj : objects)
    {
        hb.setPosition(obj.x*3, obj.y*3);
        hb.setSize({obj.width*3, obj.height*3});
        hitboxes.push_back(hb);
    }

    // Left wall
    hb.setPosition(-10, -300);
    hb.setSize({10, 600*3});
    hitboxes.push_back(hb);

    // Right wall
    hb.setPosition(2400*3, -300);
    hitboxes.push_back(hb);
}

void LevelOneState::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        musicGame.pause();
        pause();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
        renderHitboxes = true;

        // Get player location
        std::cout << "L1: " << player->getPosition().x << ", " << player->getPosition().y << "\n";
        // Cheat go to level 2
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            cheatGame.play();
            bnextLevel = true;
            if(bnextLevel){
                checkLevel = 1;
            }
            else {
                checkLevel = 0;
            }
            std::cout << "Next Level!\n";
            musicGame.stop();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            player->takeDamage(1);
            deathGame.play();
        }
    }
    else
        renderHitboxes = false;
}

void LevelOneState::updatePaused() {
    updateMousePosition();
    updateVirtualCursor();

    if (pauseResumeBtn->intersects(virtualCursor))
    {
        // START
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pauseResumeBtn->getState() == Button::ACTIVE) {
            clickMenu.play();
            unpause();
            musicGame.play();
        }
    }
    else if (saveBtn->intersects(virtualCursor))
    {
        // SAVE
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && saveBtn->getState() == Button::ACTIVE){
            clickMenu.play();
            saveGame();
            unpause();
            musicGame.play();
        }
    }
    else if (loadBtn->intersects(virtualCursor))
    {
        // LOAD
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && loadBtn->getState() == Button::ACTIVE){
            clickMenu.play();
            loadGame();
            unpause();
            if(checkLevel==1){
                musicGame.stop();
            }else
                musicGame.play();
        }
    }
    else if (pauseExitBtn->intersects(virtualCursor))
    {
        // EXIT
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pauseExitBtn->getState() == Button::ACTIVE) {
            clickMenu.play();
            musicGame.stop();
            //saveGame(); //zapis po wyjsciu
            endState();
        }
    }

    pauseResumeBtn->update(virtualCursor);
    saveBtn->update(virtualCursor);
    loadBtn->update(virtualCursor);
    pauseExitBtn->update(virtualCursor);
}

void LevelOneState::initPauseButtons() {
    pauseResumeBtn = new Button("Powrot do gry", 960, 480, 300, 100);
    saveBtn =  new Button("Zapisz gre", 960, 600, 200, 100);
    loadBtn =  new Button("Wczytaj gre", 960, 720, 200, 100);
    pauseExitBtn = new Button("Wyjscie", 960, 840, 300, 100);
}

void LevelOneState::renderPaused(sf::RenderTarget& window) {
    initView(window);
    window.draw(nameTextPause);
    pauseResumeBtn->render(window);
    saveBtn->render(window);
    loadBtn->render(window);
    pauseExitBtn->render(window);
}

void LevelOneState::initViewPlayer(sf::RenderTarget &window) {
    sf::View view (sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));


    sf::Vector2<unsigned int> windowSize = window.getSize();
    sf::Vector2<float> newViewPos = player->getPosition();
    if (player->getPosition().x < 960.0f)
        newViewPos.x = 960.0f;
    if (player->getPosition().x > 6250.0f)
        newViewPos.x = 6250.0f;

    newViewPos.y = windowSize.y/2;
    view.setCenter(newViewPos);
    window.setView(view);
}

void LevelOneState::initView(sf::RenderTarget &window) {
    sf::View view (sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    view.setCenter(960,540);
    window.setView(view);
}

void LevelOneState::initDmgBoxes() {
    Layer dmgLayer = map.getDamageLayer();
    std::vector<LayerObject> objects = dmgLayer.getObjects();

    sf::RectangleShape hb;
    hb.setOutlineColor(sf::Color::Red);
    hb.setFillColor(sf::Color::Transparent);
    hb.setOutlineThickness(1);

    for (auto & obj : objects)
    {
        hb.setPosition(obj.x*3, obj.y*3);
        hb.setSize({obj.width*3, obj.height*3});
        dmgboxes.push_back(hb);
    }
}

void LevelOneState::initEndTrigger() {
    endLevelTrigger.setSize({93, 48});
    endLevelTrigger.setOutlineColor(sf::Color::Yellow);
    endLevelTrigger.setOutlineThickness(1);
    endLevelTrigger.setFillColor(sf::Color::Transparent);

    endLevelTrigger.setPosition(7104, 769.5);
}

void LevelOneState::updateEndTrigger() {
    if (player->checkForIntersection(endLevelTrigger))
    {
        // next level
        //states->push(new LevelTwoState(states));
        bnextLevel = true;
        if(bnextLevel){
            checkLevel = 1;
        }
        else {
            checkLevel = 0;
        }
        std::cout << "Next Level!\n";
        musicGame.stop();
    }
}

void LevelOneState::updateDead() {
    updateMousePosition();
    updateVirtualCursor();

    if (endMenuBtn->intersects(virtualCursor)) {
        // EXIT
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && endMenuBtn->getState() == Button::ACTIVE) {
            clickMenu.play();
            unEndGame();
            musicGame.stop();
            endState();
        }
    }

    endMenuBtn->update(virtualCursor);
}

void LevelOneState::initDeadButtons() {
    endMenuBtn = new Button("Przejdz do menu", 960, 600, 300, 100);
}

void LevelOneState::renderDead(sf::RenderTarget& window) {
    initView(window);
    window.draw(nameTextGame);
    endMenuBtn->render(window);
}

void LevelOneState::updateDeadTrigger() {
    if (player->isDead())
    {
        // end game
        // states->push(new LevelTwoState(states));
        std::cout << "End Game!\n";
        endGame();
        updateDead();
        musicGame.stop();
    }
}

void LevelOneState::updateDmgTriggers() {
    for (auto & h : dmgboxes)
    {
        if (player->checkForIntersection(h) && !player->getIsInvincible())
        {
            deathGame.play();
            // Do damage
            hud->takedDmg = true;
            player->takeDamage(1);
            i=0;
            x=0;
            std::cout << "Player damage detected!\n";
        }else if(i==1000){
            hud->takedDmg = false;
        }else{
            i++;
        }
    }
}

void LevelOneState::killPlayerTriggers(){
    if(player->getPosition().y>1080){
        deathGame.play();
        if (deathGame.getStatus() == sf::SoundSource::Status::Playing) {
            sf::sleep(sf::seconds(0.1f));
            deathGame.stop();
        }
        player->takeDamage(player->getMaxHP());

        std::cout << "Player killed!\n";

    }
}

void LevelOneState::saveGame() {
    std::ofstream save("../resources/Save/save.dat", std::ios_base::out);
    if(!save)
    {
        std::cout<<"There is an error ! Save Failed !"<<std::endl;
    }
    std::cout<<"Save game success! Value: "<<std::endl;
    save << player->getPosition().x << std::endl;
    save << player->getPosition().y << std::endl;
    save << player->getHP() << std::endl;
    save<<checkLevel<<std::endl;


    std::cout<<player->getPosition().x<< std::endl;
    std::cout<<player->getPosition().y<< std::endl;
    std::cout<<player->getHP()<< std::endl;
    std::cout<<checkLevel<< std::endl;
    save.close();
}


void LevelOneState::loadGame() {

    std::ifstream load("../resources/Save/save.dat", std::ios_base::out);
    if(!load)
    {
        std::cout<<"There is an error ! Load Failed !"<<std::endl;
    }
    load >> playerPositionX;
    load >> playerPositionY;
    load >> playerHP;
    load >> checkLevel;

    std::cout<< std::endl<<"Load game success! Value: " << std::endl;
    std::cout<<playerPositionX<<std::endl;
    std::cout<<playerPositionY<<std::endl;
    std::cout<<playerHP<<std::endl;
    std::cout<<checkLevel<<std::endl;

    player->setPosition({playerPositionX,playerPositionY});
    player->setHP(playerHP);
    if(checkLevel>0){
        loadSave=true;
        bnextLevel=true;
        musicGame.stop();
    }
    else{
        loadSave=false;
        bnextLevel=false;
    }
    load.close();
}

void LevelOneState::initEnemies() {
    // #1 location
    enemies.push_back(new Slime(863.25*3, 262*3, 2160, 3050, false));
    enemies.push_back(new Slime(820.25*3, 262*3, 2160, 3050, true));
    enemies.push_back(new Slime(900.25*3, 262*3, 2160, 3050, false));
    enemies.push_back(new Slime(750.25*3, 262*3, 2160, 3050, true));
    // #2 location
    enemies.push_back(new Slime(1071*3, 310*3, 3220, 3410, false));
    // #3 location
    enemies.push_back(new Slime(511*3, 166*3, 1400, 1725, false));
    enemies.push_back(new Slime(467*3, 166*3, 1400, 1725, true));
    // #4 location
    enemies.push_back(new Slime(1567*3, 182*3, 4450, 4825, true));
    enemies.push_back(new Slime(1510*3, 182*3, 4500, 4850, true));
    // #5 location
    enemies.push_back(new Slime(1407*3, 214*3, 4225, 4260, true));
    // #6 location
    enemies.push_back(new Slime(1935*3, 230*3, 5626, 6040, true));
    enemies.push_back(new Slime(2000*3, 230*3, 5626, 6040, false));
    // #7 location
    enemies.push_back(new Slime(2064*3, 327*3, 6100, 6500, true));
}

void LevelOneState::renderEntities(sf::RenderTarget &window) {
    // Render every enemy
    for (auto& e : enemies) {
        e->render(window);
    }
    // Render player
    player->render(window);
}

void LevelOneState::updateEntities(float dt) {
    // Update every enemy
    for (auto& e : enemies) {
        e->update(dt);
        // check collision with projectiles
        if (player->checkIsProjectileColliding(e->getHitbox())) {
            hitGame.play();
            e->takeDamage(1);
            break;
        }

        // check collision with player
        if (player->checkForIntersection(e->getHitbox())) {
            deathGame.play();
            hud->takedDmg = true;
            i=0;
            x=0;
            player->takeDamage(1);
        }else if(x==1000){
           hud->takedDmg = false;
        }else{
            x++;
        }
    }
}
