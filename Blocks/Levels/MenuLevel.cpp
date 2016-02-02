#include "MenuLevel.hpp"

MenuLevel::MenuLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer, SoundBuffer bgMusic, RenderWindow *window) : CoreLevel(title, font, bg, bgMusic, 19.5, window) {
    // Create new Button object pointers
    startButton = new Button("Start", 30, 220, 250, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    loadButton = new Button("Load", 30, 220, 330, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    aboutButton = new Button("About", 30, 220, 410, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 220, 490, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Add the GameObject pointers to the object's container
    objects.push_back(startButton);
    objects.push_back(loadButton);
    objects.push_back(aboutButton);
    objects.push_back(quitButton);
}

void MenuLevel::update() {
    // Call parent update function
    CoreLevel::update();
    // Set fade out transition if any button was clicked
    if (startButton->getClicked() && !isTransition) {
        setTransition("BUTTON_EVT_START");
    }
    if (quitButton->getClicked() && !isTransition) {
        setTransition("BUTTON_EVT_QUIT");
    }
    // Process button events
    processButtonEvents();
}

void MenuLevel::setTransition(string _buttonEventName) {
    fadeOutEffect->start();
    isTransition = true;
    buttonEventName = _buttonEventName;
}

void MenuLevel::processButtonEvents() {
    if (fadeOutEffect->isDone() && isTransition) {
        isTransition = false;   // No longer transitioning
        // Process button events after transition effect
        if (buttonEventName == "BUTTON_EVT_START") {
            isComplete = true;
        } else {
            // Quit button clicked, terminate the game
            window->close();
        }
    }
}
