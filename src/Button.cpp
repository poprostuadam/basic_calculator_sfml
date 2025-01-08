//
// Created by adam on 1/8/25.
//

#include "../include/Button.h"

Button::Button(const std::string &label, const sf::Vector2f &position, const sf::Vector2f &size, const sf::Font &font,
    int fontSize) :
    bShape(size),
    bNormalColor(Config::NormalColor),
    bHoverColor(Config::HoverColor),
    bActiveColor(Config::ActiveColor),
    isActive(false)
{
    // Set button properties
    bShape.setPosition(position);
    bShape.setFillColor(bNormalColor);

    // Set text properties
    bText.setFont(font);
    bText.setString(label);
    bText.setCharacterSize(fontSize);
    bText.setFillColor(Config::TextColor);

    sf::FloatRect textRect = bText.getLocalBounds();
    bText.setOrigin(
        textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f
    );
    bText.setPosition(
        position.x + bShape.getSize().x / 2.0f,
        position.y + bShape.getSize().y / 2.0f
    );

}

void Button::setColors(const sf::Color &normal, const sf::Color &hover, const sf::Color &active) {
    bNormalColor = normal;
    bHoverColor = hover;
    bActiveColor = active;
}

void Button::processEvents(const sf::Event &event, const sf::RenderWindow& window) {
    if (isHovered(window)) {
        if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
            bShape.setFillColor(bActiveColor);
            isActive = true;
        }
        else if (event.type == sf::Event::MouseButtonReleased and event.mouseButton.button == sf::Mouse::Left) {
            if (isActive) {
                bShape.setFillColor(bHoverColor);
                isActive = false;
            }
        } else if (!isActive) {
            bShape.setFillColor(bHoverColor);
        }
    } else {
        bShape.setFillColor(bNormalColor);
        isActive = false;
    }
}


void Button::render(sf::RenderWindow &window) {
    window.draw(bShape);
    window.draw(bText);
}

bool Button::isHovered(const sf::RenderWindow &window) const {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return bShape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition));
}
