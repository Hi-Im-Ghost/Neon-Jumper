//
// Created by ToQly on 30.12.2021.
//

#ifndef TREES_JSON_BUTTON_H
#define TREES_JSON_BUTTON_H


#include <string>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>

enum ButtonState {
    IDLE,
    HOVER,
    ACTIVE
};

class Button {
private:
    sf::RectangleShape buttonShape;
    sf::Text text;
    sf::Font font;
    float width;
    float height;
    ButtonState state;

    void initText(const std::string& text);

public:
    Button(const std::string& text, float posX, float posY, float width, float height);

    sf::Color colorIdle;
    sf::Color colorHover;
    sf::Color colorActive;

    bool intersects(const sf::Shape& shape);
    void setState(ButtonState newState);
    ButtonState getState() {return state;}
    void render(sf::RenderTarget& window);
    void update(const sf::RectangleShape& cursor);
};


#endif //TREES_JSON_BUTTON_H
