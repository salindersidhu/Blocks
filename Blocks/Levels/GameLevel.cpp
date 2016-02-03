#include "GameLevel.hpp"

GameLevel::GameLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer, SoundBuffer bgMusic, RenderWindow *window) : CoreLevel(title, font, bg, bgMusic, 19.5, window) {
    // Create new Button object pointers
    resetButton = new Button("Reset", 30, 111, 107, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 321, 107, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Create a new GameClock pointer
    gameInfo = new GameInfo(600, 640, 30, white, font);
    // Add the GameObject pointers to the object's container
    objects.push_back(resetButton);
    objects.push_back(quitButton);
    objects.push_back(gameInfo);
    // Set remaining instance variables
    numMoves = 0;
}

void GameLevel::update() {
    // Call parent update function
    CoreLevel::update();
    // Set fade out transition if any button was clicked
    if (resetButton->getClicked() && !isTransition) {
        setTransition();
		buttonEventName = "BUTTON_EVT_RESTART";
    }
    if (quitButton->getClicked() && !isTransition) {
        setTransition();
        buttonEventName = "BUTTON_EVT_QUIT";
    }
    // Process button events
    processButtonEvents();
}

void GameLevel::restart() {
    // Restart the GameLevel
    gameInfo->getClock()->reset();
    numMoves = 0;
    bgMusic->start();
}

void GameLevel::processButtonEvents() {
    if (fadeEffect->isDone() && isTransition) {
        isTransition = false;   // No longer transitioning
        // Process button events after transition effect
        if (buttonEventName == "BUTTON_EVT_RESTART") {
            restart();
        } else {
            // Quit button clicked, terminate the game
            window->close();
        }
    }
}
