//
// Created by adam on 1/8/25.
//

#include "../include/Display.h"

Display::Display(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Font &font, int fontSize, int char_limit)
: dShape(size), DisplayColor(Config::TextColor), DisplayTextColor(Config::DisplayTextColor), maxFontSize(fontSize), charLimit(char_limit)
{
    // Display position and color
    dShape.setPosition(position);
    dShape.setFillColor(DisplayColor);

    // Display text settings
    dText.setFont(font);
    dText.setCharacterSize(fontSize);
    dText.setFillColor(DisplayTextColor);
    dText.setPosition(position.x + 14, position.y + 14);

}

void Display::addChar(char c) {
    if (dText.getString().getSize() < static_cast<size_t>(charLimit)) {
        dText.setString(dText.getString() + c);
        adjustFontSize();
    }
}

void Display::deleteLastChar() {
    sf::String currentString = dText.getString();
    if (!currentString.isEmpty()) {
        currentString.erase(currentString.getSize() - 1);
        dText.setString(currentString);
        adjustFontSize();
    }
}

void Display::setText(const std::string &text) {
    dText.setString(text);
    adjustFontSize();
}

void Display::render(sf::RenderWindow &window) {
    window.draw(dShape);
    window.draw(dText);
}

void Display::clear() {
    dText.setString("0");
    dText.setCharacterSize(maxFontSize);
}

void Display::showError() {
    dText.setString(error_message);
    dText.setCharacterSize(maxFontSize);
}

void Display::adjustFontSize() {
    dText.setCharacterSize(maxFontSize);

    while ((dText.getLocalBounds().width +
            dText.getFont()->getGlyph(' ', dText.getCharacterSize(), false).advance) > dShape.getSize().x
            && dText.getCharacterSize() > 10) {
        dText.setCharacterSize(dText.getCharacterSize() - 1);
    }
}
