//
// Created by ToQly on 30.12.2021.
//

#include "Button.h"

Button::Button(const std::string& text, float posX, float posY, float width, float height) {
    colorIdle = sf::Color::White;
    colorHover = sf::Color::Cyan;
    colorActive = sf::Color::Green;

    // Buton Width and Height for text alligment
    this->width = width;
    this->height = height;

    float px = posX - width/2;
    float py = posY - height/2;

    buttonShape.setPosition(px, py);
    buttonShape.setSize({width,height});

    initText(text);
    //setColors(105,105,105);
    setState(IDLE);
}

void Button::render(sf::RenderTarget &window) {
    window.draw(buttonShape);
    window.draw(text);
}

void Button::initText(const std::string& text) {
    if (!font.loadFromFile("../resources/Robot_Crush.ttf"))
        std::printf("Could not load the button font\n");
    this->text.setFont(font);
    this->text.setFillColor(sf::Color::Black);
    this->text.setString(text);

    this->text.setPosition(
            buttonShape.getPosition().x + width/2 - this->text.getGlobalBounds().width/2,
            buttonShape.getPosition().y + height/2 - this->text.getGlobalBounds().height
    );
}

bool Button::intersects(const sf::Shape& shape) {
    return buttonShape.getGlobalBounds().intersects(shape.getGlobalBounds());
}

void Button::setState(ButtonState newState) {
    state = newState;
    switch (state) {
        case IDLE:
            buttonShape.setFillColor(colorIdle);
            break;
        case HOVER:
            buttonShape.setFillColor(colorHover);
            break;
        case ACTIVE:
            buttonShape.setFillColor(colorActive);
            break;
    }
}

void Button::update(const sf::RectangleShape& cursor) {
    if (intersects(cursor))
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            setState(ACTIVE);
        else
            setState(HOVER);
    else
        setState(IDLE);
}
