#include "MenuLevel.hpp"

MenuLevel::MenuLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer, SoundBuffer bgMusic, RenderWindow *window) : CoreLevel(title, font, bg, bgMusic, 19.5, window) {
    // Create new Button object pointers
    startButton = new Button("Start", 30, 220, 250, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 220, 330, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Create a new FadeTrans object pointer
    Vector2u dims = bg.getSize();
    fadeEffect = new FadeTrans(5, dims.x, dims.y, black);
    // Add the GameObject pointers to the object's container
    objects.push_back(startButton);
    objects.push_back(quitButton);
    objects.push_back(fadeEffect);
}

void MenuLevel::processGameStartEvent() {
    if (fadeEffect->isDone() && isTransition) {
        isTransition = false;
        isComplete = true;  // Set the level completed to true
    }
}

void MenuLevel::update() {
    // Call parent update method
    LevelObject::update();
    // Fade out and set isTransition to true if start Button was clicked
    if (startButton->getClicked()) {
        fadeEffect->setFadeOut();
        isTransition = true;
    }
    // Close window if quit Button was clicked
    if (quitButton->getClicked()) {
        window->close();
    }
    // Process events for starting the game
    processGameStartEvent();
}
