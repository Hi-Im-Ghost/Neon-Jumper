#include "LevelTwoState.h"

LevelTwoState::LevelTwoState(std::stack<GameState*>* states)
        : GameState(states), map("mapa1.json") {
    initValues();
    initHitboxes();
    initDmgBoxes();
    initEndTrigger();
    initPauseButtons();
    initEndButtons();
    initVirtualCursor();
    initTextGame();
    initTextPause();
    musicGame.play();
    if(loadSave) {
        player->setPosition({playerPositionX, playerPositionY});
        player->setHP(playerHP);
    }
}

void LevelTwoState::initValues() {
    player = new Player(10*3, 230*3);
    hud = new PlayerHUD();
    checkLevel = 1;
    level2 = true;
}

void LevelTwoState::update(float dt) {
    if (!bPaused && !bEndGame) {
        updateInput();
        player->update(dt, hitboxes);
        updateEndTrigger();
        updateDmgTriggers();
        killPlayerTriggers();
        hud->setPosition(player->getPosition().x);
        hud->update(player);
        checkLevel = 1;
    } else{
        if(bPaused)
            updatePaused();
        else
            updateEndTrigger();
    }


}

void LevelTwoState::render(sf::RenderTarget &window) {

    initViewPlayer(window);
    map.draw(window);
    player->render(window);
    hud->render(window);
    if (renderHitboxes) {
        for (auto & h : hitboxes)
            window.draw(h);
        for (auto & h : dmgboxes)
            window.draw(h);
        window.draw(endLevelTrigger);
    }

    if (bPaused)
        renderPaused(window);

    if(bEndGame){
        renderEnd(window);
    }
}

void LevelTwoState::initHitboxes() {

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

void LevelTwoState::updateInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        musicGame.pause();
        pause();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
        renderHitboxes = true;
    else
        renderHitboxes = false;
}

void LevelTwoState::updateEnd() {
    updateMousePosition();
    updateVirtualCursor();

 if (endMenuBtn->intersects(virtualCursor)) {
        // EXIT
        if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && endMenuBtn->getState() == ACTIVE) {
            clickMenu.play();
            unEndGame();
            musicGame.stop();
            endState();
        }
    }

    endMenuBtn->update(virtualCursor);
}

    void LevelTwoState::updatePaused() {
        updateMousePosition();
        updateVirtualCursor();

        if (pauseResumeBtn->intersects(virtualCursor))
        {
            // START
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pauseResumeBtn->getState() == ACTIVE) {
                clickMenu.play();
                unpause();
                musicGame.play();
            }
        }
        else if (saveBtn->intersects(virtualCursor))
        {
            // SAVE
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && saveBtn->getState() == ACTIVE){
                clickMenu.play();
                saveGame();
                unpause();
                musicGame.play();
            }
        }
        else if (loadBtn->intersects(virtualCursor))
        {
            // LOAD
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && loadBtn->getState() == ACTIVE){
                clickMenu.play();
                loadGame();
                unpause();
                if(checkLevel==1){
                    if(level2)
                    {
                        musicGame.play();
                    }else
                        musicGame.stop();
                }else
                    musicGame.play();
            }
        }
        else if (pauseExitBtn->intersects(virtualCursor))
        {
            // EXIT
            if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && pauseExitBtn->getState() == ACTIVE) {
                clickMenu.play();
                musicGame.stop();
                //saveGame();
                endState();
            }
        }

        pauseResumeBtn->update(virtualCursor);
        saveBtn->update(virtualCursor);
        loadBtn->update(virtualCursor);
        pauseExitBtn->update(virtualCursor);
    }

void LevelTwoState::initPauseButtons() {
    pauseResumeBtn = new Button("Powrot do gry", 960, 480, 300, 100);
    saveBtn =  new Button("Zapisz gre", 960, 600, 200, 100);
    loadBtn =  new Button("Wczytaj gre", 960, 720, 200, 100);
    pauseExitBtn = new Button("Wyjscie", 960, 840, 300, 100);
}

void LevelTwoState::initEndButtons() {
    endMenuBtn = new Button("Przejdz do menu", 960, 480, 300, 100);
}


void LevelTwoState::renderPaused(sf::RenderTarget& window) {
    initView(window);
    window.draw(nameTextPause);
    pauseResumeBtn->render(window);
    saveBtn->render(window);
    loadBtn->render(window);
    pauseExitBtn->render(window);
}

void LevelTwoState::renderEnd(sf::RenderTarget& window) {
    initView(window);
    window.draw(nameTextGame);
    endMenuBtn->render(window);
}

void LevelTwoState::initViewPlayer(sf::RenderTarget &window) {
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

void LevelTwoState::initView(sf::RenderTarget &window) {
    sf::View view (sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    view.setCenter(960,540);
    window.setView(view);
}

void LevelTwoState::initDmgBoxes() {
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

void LevelTwoState::initEndTrigger() {
    endLevelTrigger.setSize({32*3, 32*3});
    endLevelTrigger.setOutlineColor(sf::Color::Yellow);
    endLevelTrigger.setOutlineThickness(1);
    endLevelTrigger.setFillColor(sf::Color::Transparent);

    endLevelTrigger.setPosition(2366.66666666667*3, 160*3);

}

void LevelTwoState::updateEndTrigger() {
    if (player->checkForIntersection(endLevelTrigger) || player->isDead())
    {
        // end game
        // states->push(new LevelTwoState(states));
        std::cout << "End Game!\n";
        endGame();
        updateEnd();
        musicGame.stop();
    }
}

void LevelTwoState::updateDmgTriggers() {
    for (auto & h : dmgboxes)
    {
        if (player->checkForIntersection(h)) {
            // Do damage
            deathGame.play();
            std::cout << "Player damage detected!\n";
            player->takeDamage(1);
        }
    }
}

void LevelTwoState::killPlayerTriggers(){
    if(player->getPosition().y>1080){
        deathGame.play();
        if (deathGame.getStatus() == sf::SoundSource::Status::Playing) {
            sf::sleep(sf::seconds(0.1f));
            deathGame.stop();
        }
        player->takeDamage(player->getHP());
        std::cout << "Player killed!\n";
    }
}

void LevelTwoState::saveGame() {
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


void LevelTwoState::loadGame() {

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
        if(level2){
            loadSave=false;
        }else {
            loadSave = true;
            bnextLevel = true;
            musicGame.stop();
        }
    }
    else{
        player->setPosition({0,247});
        player->setHP(player->getMaxHP());
        loadSave=false;
        bnextLevel=false;
    }
    load.close();
}