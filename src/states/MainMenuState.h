#ifndef TREES_JSON_MAINMENUSTATE_H
#define TREES_JSON_MAINMENUSTATE_H

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include "GameState.h"
#include "LevelOneState.h"
#include "../UI/Button.h"

/**
 * @class Stan aplikacji obsługujący menu główne
 */
class MainMenuState : public GameState {
private:
    /// Tekstura tła menu
    sf::Texture bgTexture;
    /// Sprite tła menu
    sf::Sprite bgSprite;
    /// Tekst przechowujący nazwę gry
    sf::Text gamenameText;
    /// Czciona używana do tekstu nazwy gry
    sf::Font gamenameFont;

    /// Lista przycisków menu z nazwami
    std::map<std::string, Button*> buttons;

    /// Odświeżanie logiki przycisków menu
    void updateButtons();

    /// Inicjacja tła menu
    void initBackground();
    /// Inicjacja przycisków menu
    void initButtons();
    /// Inicjacja tekstu nazwy gry
    void initText();

public:
    /** Konstruktor przyjmujący stos stanów programu
     * @param states odniesienie do stosu wszystkich stanów aplikacji
     */
    explicit MainMenuState(std::stack<GameState *> *states);
    /** Definicja funkcji render klasy GameState
     * @param window okno na którym renderowane są elementy
     */
    void render(sf::RenderTarget &window) override;
    /** Definicja funkcji update klasy GameState
     * @param deltaTime czas pomiędzy klatkami aplikacji
     */
    void update(float deltaTime) override;
};


#endif //TREES_JSON_MAINMENUSTATE_H
