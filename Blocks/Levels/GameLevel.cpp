#include "GameLevel.hpp"

void GameLevel::init() {
    // Obtain the game's resources for this level
    Font font = resMan->getFont("FN_COPPER");
    SoundBuffer bgMusic = resMan->getSound("MS_BACKGROUND");
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
    // If not transitioning
    if (!isTransition) {
        // Set fade out transition if Grid is complete
        if (gameGrid->getIsGridComplete()) {
            setTransition();
            transitionEventName = "GRID_COMPLETE";
        }
        // Set fade out transition if any button was clicked
        if (resetButton->getIsClicked()) {
            setTransition();
    		transitionEventName = "BUTTON_RESTART";
        }
        if (quitButton->getIsClicked()) {
            setTransition();
            transitionEventName = "BUTTON_QUIT";
        }
    }
    // Process transition events
    processTransition();
}

void GameLevel::restart() {
    // Restart the GameGrid and start the bgMusic
    gameGrid->reset();
    bgMusic->start();
}

void GameLevel::processTransition() {
    if (fadeEffect->isDone() && isTransition) {
        isTransition = false;   // No longer transitioning
        // Process transition events
        if (transitionEventName == "BUTTON_RESTART") {
            // Restart button clicked, restart the level
            restart();
        } else if (transitionEventName == "BUTTON_QUIT") {
            // Quit button clicked, terminate the game
            window->close();
        } else {
            // Grid is complete, go to next level to display win results
            isFinished = true;
        }
    }
}

void GameLevel::setGameGrid(GameGrid *_gameGrid) {
    // Set the GameGrid
    gameGrid = _gameGrid;
}
