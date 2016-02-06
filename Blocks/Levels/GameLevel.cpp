#include "GameLevel.hpp"

void GameLevel::init() {
    // Obtain the game's resources for this level
    Font font = resMan->getFont("FN_COPPER");
    SoundBuffer bgMusic = resMan->getSound("MS_BACKGROUND");
    SoundBuffer winMusic = resMan->getSound("SN_VICTORY");
    SoundBuffer hoverSound = resMan->getSound("SN_BUTTON_HOVER");
    SoundBuffer clickSound = resMan->getSound("SN_BUTTON_CLICK");
    Texture background = resMan->getTexture("TX_BACKGROUND_GAME");
    Texture buttonHover = resMan->getTexture("TX_BUTTON_HOVER");
    Texture buttonNormal = resMan->getTexture("TX_BUTTON_NORMAL");
    // Create and configure new Button objects
    resetButton = new Button("Reset", 30, font, buttonNormal, buttonHover);
    quitButton = new Button("Quit", 30, font, buttonNormal, buttonHover);
    resetButton->setPosition(111, 107);
    quitButton->setPosition(321, 107);
    resetButton->setSounds(hoverSound, clickSound);
    quitButton->setSounds(hoverSound, clickSound);
    resetButton->setColours(white, red);
    quitButton->setColours(white, red);
    // Set the background texture and music
    setBackgroundAndFont(background, font);
    setBackgroundMusic(bgMusic, 19.5, true);
    // Add the GameObject pointers to the object's container
    objects.push_back(resetButton);
    objects.push_back(quitButton);
    objects.push_back(gameGrid);
}

void GameLevel::update() {
    // Call parent update function
    CoreLevel::update();
    // Set fade out transition if any button was clicked
    if (resetButton->getIsClicked() && !isTransition) {
        setTransition();
		buttonEventName = "BUTTON_EVT_RESTART";
    }
    if (quitButton->getIsClicked() && !isTransition) {
        setTransition();
        buttonEventName = "BUTTON_EVT_QUIT";
    }
    // Process button events
    processButtonEvents();
}

void GameLevel::restart() {
    // Restart the GameGrid and start the bgMusic
    gameGrid->reset();
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

void GameLevel::setGameGrid(GameGrid *_gameGrid) {
    // Set the GameGrid
    gameGrid = _gameGrid;
}
