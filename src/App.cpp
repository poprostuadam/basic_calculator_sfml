//
// Created by adam on 1/8/25.
//

#include "../include/App.h"
#include <iostream>

App::App(): mWindow(sf::VideoMode(config::windowWidth, config::windowHeight),
        config::windowTitle, sf::Style::Close | sf::Style::Titlebar),
        mDisplay(nullptr)
{
        // Set frame rate limit
        mWindow.setFramerateLimit(config::frameLimit);

        // Load font
        if (!mFont.loadFromFile(config::fontPath)) {
                throw std::runtime_error("Error loading font");
        }

        initButtons();

        mDisplay = std::make_unique<Display>(sf::Vector2f(24,24),
                sf::Vector2f(472, 152),
                mFont,
                config::DisplayFontSize,
                config::DisplayMaxChars);
}

void App::run() {
        while (mWindow.isOpen()) {
                processEvents();
                update();
                render();
        }
}

void App::processEvents() {
        // Process window close and escape key events
        while (mWindow.pollEvent(mEvent)) {
                if (mEvent.type == sf::Event::Closed) {
                        mWindow.close();
                }

                for (auto& button: mButtons) {
                        button->processEvents(mEvent, mWindow);
                }

                processMouseInput(mEvent);
                processKeyboardInput(mEvent);

        }
}

void App::update() {
}

void App::render() {
        // Clear window and set background color
        mWindow.clear(config::BackgroundColor);

        // Render display
        mDisplay->render(mWindow);

        // Render buttons
        for (const auto& button: mButtons) {
                button->render(mWindow);
        }

        // Display window
        mWindow.display();
}

void App::initButtons() {

        const sf::Vector2f buttonSize{100,100};
        const float padding = 24.0f;
        const sf::Vector2f startingPosition{24.0f, 200.0f};

        // Button labels
        std::vector<std::string> labels = {
                "7", "8", "9", "/",
                "4", "5", "6", "*",
                "1", "2", "3", "-",
                "AC", "0", ".", "+",
                "=", "<-"
        };

        for (size_t i = 0; i < labels.size(); i++) {
                size_t row = i / 4;
                size_t col = i % 4;

                if (labels[i] == "=") {
                        float x = startingPosition.x;
                        float y = startingPosition.y + (row * (buttonSize.y + padding));

                        sf::Vector2f size{buttonSize.x * 3 + padding * 2, buttonSize.y};

                        auto button = std::make_unique<Button>(labels[i], sf::Vector2f(x,y), size, mFont, config::ButtonFontSize);
                        button->setColors(config::GreenNormalColor, config::GreenHoverColor, config::GreenActiveColor);
                        mButtons.push_back(std::move(button));
                } else if (labels[i] == "<-") {
                        float x = startingPosition.x + (buttonSize.x * 3 + padding * 3);
                        float y = startingPosition.y + (row * (buttonSize.y + padding));

                        auto button = std::make_unique<Button>(labels[i], sf::Vector2f(x,y), buttonSize, mFont, config::ButtonFontSize);
                        button->setColors(config::GreenNormalColor, config::GreenHoverColor, config::GreenActiveColor);
                        mButtons.push_back(std::move(button));

                } else {
                        float x = startingPosition.x + (col * (buttonSize.x + padding));
                        float y = startingPosition.y + (row * (buttonSize.y + padding));

                        auto button = std::make_unique<Button>(labels[i], sf::Vector2f(x,y), buttonSize, mFont, config::ButtonFontSize);

                        if (labels[i] == "/" || labels[i] == "*"  || labels[i] == "-" ||
                            labels[i] == "AC" || labels[i] == "." || labels[i] == "+" || labels[i] == "AC") {
                                button->setColors(config::GreenNormalColor, config::GreenHoverColor, config::GreenActiveColor);
                        }

                        mButtons.push_back(std::move(button));
                }


        }
}

void App::processMouseInput(const sf::Event &event) const {
        if (event.type == sf::Event::MouseButtonPressed and event.mouseButton.button == sf::Mouse::Left) {
                for (auto& button: mButtons) {
                        if (button->isHovered(mWindow)) {
                                const std::string& label = button->getLabel();

                                if (label == "AC") {
                                        mDisplay->clear();
                                } else if (label == "<-") {
                                        mDisplay->deleteLastChar();
                                } else if (label == ".") {
                                        mDisplay->addChar('.');
                                } else if (label == "=") {

                                } else if (label == "/" || label == "*" || label == "-" || label == "+") {
                                        mDisplay->addChar(label[0]);
                                } else {
                                        mDisplay->addChar(label[0]);
                                }
                        }
                }
        }
}

void App::processKeyboardInput(const sf::Event &event) {
        if (event.type == sf::Event::KeyPressed) {
                std::string buttonLabel;
                // Numbers
                if (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9 && !event.key.shift) {
                        buttonLabel = std::to_string(event.key.code - sf::Keyboard::Num0);
                        mDisplay->addChar(buttonLabel[0]);
                }

                // Operators with Shift
                if (event.key.shift) { // Jeśli Shift jest wciśnięty
                        switch (event.key.code) {
                                case sf::Keyboard::Num8: // Shift + 8 -> '*'
                                        buttonLabel = "*";
                                        mDisplay->addChar(buttonLabel[0]);
                                        break;
                                case sf::Keyboard::Equal:
                                        buttonLabel = "+";
                                        mDisplay->addChar(buttonLabel[0]);
                                        break;
                                default:
                                        break;
                        }
                }

                // Operators
                if (event.key.code == sf::Keyboard::Divide) {
                        buttonLabel = "/";
                        mDisplay->addChar(buttonLabel[0]);
                } else if (event.key.code == sf::Keyboard::Multiply) {
                        buttonLabel = "*";
                        mDisplay->addChar(buttonLabel[0]);
                } else if (event.key.code == sf::Keyboard::Add) {
                        buttonLabel = "+";
                        mDisplay->addChar(buttonLabel[0]);
                } else if (event.key.code == sf::Keyboard::Hyphen) {
                        buttonLabel = "-";
                        mDisplay->addChar(buttonLabel[0]);
                } else if (event.key.code == sf::Keyboard::Period) {
                        buttonLabel = ".";
                        mDisplay->addChar(buttonLabel[0]);
                }

                // Backspace
                if (event.key.code == sf::Keyboard::Backspace) {
                        buttonLabel = "<-";
                        mDisplay->deleteLastChar();
                }

                // Clear
                if (event.key.code == sf::Keyboard::Escape) {
                        buttonLabel = "AC";
                        mDisplay->clear();
                }

                // Enter
                if (event.key.code == sf::Keyboard::Enter || event.key.code == sf::Keyboard::Equal) {
                        buttonLabel = "=";

                        // std::string text = mDisplay->getText();
                        // std::cout << "text: " << text << std::endl;
                }


        }
}



