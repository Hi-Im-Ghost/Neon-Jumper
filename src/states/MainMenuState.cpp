//
// Created by ToQly on 30.12.2021.
//

#include "MainMenuState.h"

MainMenuState::MainMenuState(std::stack<GameState *> *states) : GameState(states) {
    initBackground();
    initButtons();
    initVirtualCursor();
    initText();

    musicMenu.play();
}

void MainMenuState::initBackground() {
    bgTexture.loadFromFile("../resources/menubg.png");
    bgSprite.setTexture(bgTexture);
}

void MainMenuState::initButtons() {
    buttons["START"] = new Button("Graj", 960, 480, 200, 100);
    buttons["EXIT"] = new Button("Wyjdz", 960, 600, 200, 100);
}

void MainMenuState::updateButtons() {
    if (buttons["START"]->intersects(virtualCursor))
    {
        // START
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttons["START"]->getState() == Button::ACTIVE) {
            clickMenu.play();
            musicMenu.stop();
            states->push(new LevelOneState(states));
        }
    }
    else if (buttons["EXIT"]->intersects(virtualCursor))
    {
        // EXIT
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && buttons["EXIT"]->getState() == Button::ACTIVE){
            clickMenu.play();
            endState();
        }
    }

    for (auto & b : buttons)
        b.second->update(virtualCursor);
}

void MainMenuState::render(sf::RenderTarget &window) {

    sf::View view (sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    view.setCenter(960,540);
    window.setView(view);

    window.draw(bgSprite);
    for (auto & b : buttons)
    {
        b.second->render(window);
    }
    window.draw(gamenameText);
}

void MainMenuState::update(float deltaTime) {
    updateMousePosition();
    updateVirtualCursor();
    updateButtons();
}

void MainMenuState::initText() {
    if (!gamenameFont.loadFromFile("../resources/Platinum_Sign.ttf"))
        std::printf("Could not load the menu font\n");
    this->gamenameText.setFont(gamenameFont);
    sf::Color color(255, 77, 255);
    this->gamenameText.setFillColor(color);
    gamenameText.setCharacterSize(47);
    this->gamenameText.setString("NEON JUMPER");

    this->gamenameText.setPosition(960 - gamenameText.getGlobalBounds().width/2, 300);
}

