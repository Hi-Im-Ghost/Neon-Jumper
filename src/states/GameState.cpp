#include <SFML/Window/Mouse.hpp>
#include "GameState.h"

GameState::GameState(std::stack<GameState *> *states) {
    initMusicMenu();
    initMusicGame();
    initSoundMenu();
    this->states = states;
}

void GameState::updateMousePosition() {
    mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition());
}

void GameState::endState() {
    bEndState = true;
}

void GameState::initVirtualCursor() {
    virtualCursor.setSize({1,1});
}

void GameState::updateVirtualCursor() {
    virtualCursor.setPosition(mousePosition);
}

void GameState::initSoundMenu() {
    buf.loadFromFile("../resources/music/click.wav");
    bufdeath.loadFromFile("../resources/music/death.wav");
    clickMenu.setBuffer(buf);
    clickMenu.setVolume(20);
    deathGame.setBuffer(bufdeath);
    deathGame.setVolume(30);
}

void GameState::initMusicMenu() {
    musicMenu.openFromFile("../resources/music/menu.ogg");
    musicMenu.setVolume(60);
    musicMenu.setLoop(true);
}

void GameState::initMusicGame() {
    musicGame.openFromFile("../resources/music/game.ogg");
    musicGame.setVolume(40);
    musicGame.setLoop(true);
}

void GameState::initTextGame() {
    if (!nameFontGame.loadFromFile("../resources/Platinum_Sign.ttf"))
        std::printf("Could not load the menu font\n");
    this->nameTextGame.setFont(nameFontGame);
    this->nameTextGame.setFillColor(sf::Color::White);
    nameTextGame.setCharacterSize(47);
    this->nameTextGame.setString("KONIEC GRY");

    this->nameTextGame.setPosition(960 - nameTextGame.getGlobalBounds().width/2, 300);
}


void GameState::initTextPause() {
    if (!nameFontGame.loadFromFile("../resources/Platinum_Sign.ttf"))
        std::printf("Could not load the menu font\n");
    this->nameTextPause.setFont(nameFontGame);
    this->nameTextPause.setFillColor(sf::Color::White);
    nameTextPause.setCharacterSize(47);
    this->nameTextPause.setString("PAUZA");

    this->nameTextPause.setPosition(960 - nameTextPause.getGlobalBounds().width/2, 300);
}
