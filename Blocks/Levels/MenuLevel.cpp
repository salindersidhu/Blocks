#include "MenuLevel.hpp"

MenuLevel::MenuLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer, SoundBuffer _bgMusic, RenderWindow *_window) {
    // Call parent constructor
    LevelObject::LevelObject();
    // Create colour objects
    Color white = Color(255, 255, 255);
    Color red = Color(255, 51, 82);
    Color black = Color(0, 0, 0);
    // Create new Button object pointers
    startButton = new Button("Start", 30, 220, 250, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    loadButton = new Button("Load", 30, 220, 330, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    aboutButton = new Button("About", 30, 220, 410, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 220, 490, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Create a new HUD object pointer
    displayHUD = new HUD(title, 600, 15, 60, white, font, bg);
    // Create a new BGMusic object pointer
    bgMusic = new BGMusic(_bgMusic, 19.5);
    // Create a new FadeTrans object pointer
    Vector2u dims = bg.getSize();
    fadeEffect = new FadeTrans(4, dims.x, dims.y, black);
    // Add the Button object ointers to the GameObject pointers container
    objects.push_back(displayHUD);
    objects.push_back(startButton);
    objects.push_back(loadButton);
    objects.push_back(aboutButton);
    objects.push_back(quitButton);
    objects.push_back(fadeEffect);
    objects.push_back(bgMusic);
    // Set the game window
    window = _window;
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
