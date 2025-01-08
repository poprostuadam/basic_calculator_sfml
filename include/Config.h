//
// Created by adam on 1/6/25.
//

#ifndef CONFIG_H
#define CONFIG_H

#include <SFML/Graphics.hpp>
#include <string>


struct Config {
    // Window settings
    static constexpr int windowWidth = 520;
    static constexpr int windowHeight = 820;
    static constexpr const char* windowTitle = "Calculator";
    static constexpr int frameLimit = 60;

    //Font settings
    static constexpr const char* fontPath = "../assets/fonts/DejaVuSans-Bold.ttf";
    static constexpr int ButtonFontSize = 32;
    static constexpr int DisplayFontSize = 48;

    //Colors
    inline static const sf::Color BackgroundColor{110,110,110};
    inline static const sf::Color NormalColor{215,215,215};
    inline static const sf::Color HoverColor{255,255,255};
    inline static const sf::Color ActiveColor{150,150,150};
    inline static const sf::Color GreenNormalColor{179,242,124};
    inline static const sf::Color GreenHoverColor{222,255,192};
    inline static const sf::Color GreenActiveColor{115, 165, 70};
    inline static const sf::Color TextColor{35,35,35};
};


#endif //CONFIG_H
