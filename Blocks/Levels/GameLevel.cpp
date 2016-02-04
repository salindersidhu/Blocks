#include "GameLevel.hpp"

GameLevel::GameLevel(string title, ResourceManager *res, RenderWindow *win) :
CoreLevel(title, win) {
    // Obtain the game's resources for this level
    Font font = res->getFont("FN_COPPER");
    SoundBuffer bgMusic = res->getSound("MS_BACKGROUND");
    SoundBuffer hoverSound = res->getSound("SN_BUTTON_HOVER");
	SoundBuffer clickSound = res->getSound("SN_BUTTON_CLICK");
    Texture background = res->getTexture("TX_BACKGROUND_GAME");
    Texture buttonHover = res->getTexture("TX_BUTTON_HOVER");
	Texture buttonNormal = res->getTexture("TX_BUTTON_NORMAL");
    // Create and configure new Button objects
    resetButton = new Button("Reset", 30, font, buttonNormal, buttonHover);
    quitButton = new Button("Quit", 30, font, buttonNormal, buttonHover);
    resetButton->setPosition(111, 107);
    quitButton->setPosition(321, 107);
    resetButton->setSounds(hoverSound, clickSound);
    quitButton->setSounds(hoverSound, clickSound);
    resetButton->setColours(white, red);
    quitButton->setColours(white, red);
    // Create a new GameInfo object
    gameInfo = new GameInfo(600, 640, 30, white, font);
    // Set the background texture and music
    setBackgroundAndFont(background, font);
    setBackgroundMusic(bgMusic, 19.5);
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
    gameGrid->reset();
    bgMusic->start();
    numMoves = 0;
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
    // Add the GameGrid pointer to the object's container
    objects.push_back(gameGrid);
}
