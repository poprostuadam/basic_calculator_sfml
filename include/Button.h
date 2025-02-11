//
// Created by adam on 1/8/25.
//

#ifndef BUTTON_H
#define BUTTON_H

#include <config.h>

class Button {
public:
    Button(
        const std::string& label,
        const sf::Vector2f& position,
        const sf::Vector2f& size,
        const sf::Font& font,
        int fontSize);

    void setColors(const sf::Color& normal, const sf::Color& hover, const sf::Color& active);
    void processEvents(const sf::Event& event, const sf::RenderWindow& window);
    void render(sf::RenderWindow& window) const;
    void setActive(bool isActive);

    bool isHovered(const sf::RenderWindow& window) const;

    const std::string& getLabel() const;
private:
    sf::RectangleShape bShape;
    sf::Text bText;

    sf::Color bNormalColor;
    sf::Color bHoverColor;
    sf::Color bActiveColor;


    bool isActive;
};


#endif //BUTTON_H
