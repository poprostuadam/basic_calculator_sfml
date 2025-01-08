//
// Created by adam on 1/8/25.
//

#include "../include/Display.h"

Display::Display(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Font &font, int fontSize):
dShape(size)
{
    // Display position and color
    dShape.setPosition(position);
    dShape.setFillColor(Config::GreenNormalColor);

    // Display text settings
    dText.setFont(font);
    dText.setCharacterSize(fontSize);
    dText.setFillColor(Config::TextColor);
    dText.setPosition(position.x + 14, position.y + 14);
}

void Display::setText(const std::string &text) {
    dText.setString(text);
}

void Display::render(sf::RenderWindow &window) {
    window.draw(dShape);
    window.draw(dText);
}
