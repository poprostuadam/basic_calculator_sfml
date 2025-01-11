//
// Created by adam on 1/8/25.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <config.h>

constexpr const char* error_message = "ERROR";

class Display {
public:
    Display(
        const sf::Vector2f& position,
        const sf::Vector2f& size,
        const sf::Font& font,
        int fontSize,
        int char_limit);

    void addChar(char c);
    void deleteLastChar();
    void setText(const std::string& text);
    void render(sf::RenderWindow& window);
    void clear();
    void showError();

private:
    sf::RectangleShape dShape;
    sf::Text dText;

    sf::Color DisplayColor;
    sf::Color DisplayTextColor;

    int maxFontSize;
    int charLimit;

    void adjustFontSize();
};



#endif //DISPLAY_H
