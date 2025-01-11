//
// Created by adam on 1/8/25.
//

#include "../include/App.h"

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

        mDisplay = std::make_unique<Display>(sf::Vector2f(24,24), sf::Vector2f(472, 152), mFont, config::DisplayFontSize, 15);
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
                if (mEvent.type == sf::Event::Closed or (mEvent.type == sf::Event::KeyPressed and mEvent.key.code == sf::Keyboard::Escape)) {
                        mWindow.close();
                }

                for (auto& button: mButtons) {
                        button->processEvents(mEvent, mWindow);
                }

                mDisplay->showError();

        }
}

void App::update() {
}

void App::render() {
        // Clear window and set background color
        mWindow.clear(config::BackgroundColor);

        mDisplay->render(mWindow);

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


