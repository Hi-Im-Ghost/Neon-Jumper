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
    bufOh.loadFromFile("../resources/music/oh.wav");
    bufdeath.loadFromFile("../resources/music/death.wav");
    bufHit.loadFromFile("../resources/music/hit.wav");
    bufCheat.loadFromFile("../resources/music/cheat.wav");
    clickMenu.setBuffer(buf);
    clickMenu.setVolume(20);
    deathGame.setBuffer(bufdeath);
    deathGame.setVolume(30);
    hitGame.setBuffer(bufHit);
    hitGame.setVolume(60);
    ohGame.setBuffer(bufOh);
    ohGame.setVolume(50);
    cheatGame.setBuffer(bufCheat);
    cheatGame.setVolume(50);
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

void GameState::initTextPlay() {
    if (!nameFontGame.loadFromFile("../resources/Platinum_Sign.ttf"))
        std::printf("Could not load the menu font\n");
    this->nameTextPlay.setFont(nameFontGame);
    sf::Color color(21, 235, 53);
    this->nameTextPlay.setFillColor(color);
    nameTextPlay.setCharacterSize(20);
    this->nameTextPlay.setString("A-D - PORUSZANIE \n\n W - SKOK \n\n SPACE - STRZELANIE \n\n ENTER - UMIEJETNOSC \n\n ESC - PAUZA");

    this->nameTextPlay.setPosition(300 - nameTextPlay.getGlobalBounds().width/2, 100);
}
bool GameState::menuLoad = false;

void GameState::setLoadMenu(bool val) {
    GameState::menuLoad=val;
}
