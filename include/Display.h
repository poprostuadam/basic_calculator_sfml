//
// Created by adam on 1/8/25.
//

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Config.h>

class Display {
public:
    Display(
        const sf::Vector2f& position,
        const sf::Vector2f& size,
        const sf::Font& font,
        int fontSize);

    void setText(const std::string& text);
    void render(sf::RenderWindow& window);

private:
    sf::RectangleShape dShape;
    sf::Text dText;
};



#endif //DISPLAY_H
