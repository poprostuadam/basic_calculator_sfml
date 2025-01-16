//
// Created by adam on 1/8/25.
//

#ifndef APP_H
#define APP_H

#include <vector>
#include <memory>

#include <config.h>
#include <Button.h>
#include <Display.h>
#include <Calculator.h>

class App {
public:
    App();

    // main loop
    void run();

private:
    void processEvents();
    void update();
    void render();
    void initButtons();

    sf::RenderWindow mWindow;
    sf::Event mEvent;
    sf::Font mFont;

    std::vector<std::unique_ptr<Button>> mButtons;

    std::unique_ptr<Display> mDisplay;

    Calculator mCalculator;

    void processMouseInput(const sf::Event& event);
    void processKeyboardInput(const sf::Event& event);

};



#endif //APP_H
