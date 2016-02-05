#include "Game.hpp"

Game::Game(string title, int width, int height, int bits, int FPS,
    string iconName, string resArchive) {
    // Initialize and setup the game RenderWindow
    window = new RenderWindow(VideoMode(width, height, bits), title,
		Style::Close);
    window->setFramerateLimit(FPS);
    // Initialize and setup the DialogManager
    dialogMan = new DialogManager(title, window);
    // Initialize and setup the ResourceManager
    resMan = new ResourceManager(resArchive);
    // Set remaining instance variables
    currentLevelCount = 0;
}

Game::~Game() {
    // Free memory used by the instance pointers
    delete window;
    window = NULL;
    delete dialogMan;
    dialogMan = NULL;
    // Free memory used by all the LevelObject pointers
    vector<LevelObject*>::iterator iter;
    for(iter = levels.begin(); iter != levels.end(); iter++) {
        delete (*iter);
        (*iter) = NULL;
    }
}

ResourceManager *Game::getResourceManager() {
    // Return the ResourceManager
    return resMan;
}

RenderWindow *Game::getWindow() {
    // Return the game RenderWindow
    return window;
}

DialogManager *Game::getDialog() {
    // Return the DialogManager pointer
    return dialogMan;
}

void Game::addLevel(LevelObject *level) {
    level->setRenderWindow(window);
    level->setResourceManager(resMan);
    // Add LevelObject pointer to the collection of LevelObject pointers
	levels.push_back(level);
}

void Game::start() {
    // Check if any LevelObject exist
    if (levels.size() > 0) {
        // Set the currentLevel to the first LevelObject pointer
        currentLevel = levels[0];
        gameLoop();
    } else {
        // throw EngineException
        throw EngineException("Error: Cannot load Level, does not exist");
    }
}

void Game::gameLoop() {
    while(window->isOpen()) {
        // Process all input events for the current LevelObject
        Event event;
        while(window->pollEvent(event)) {
            // Default window close event
            if (event.type == Event::Closed) {
                window->close();
            }
            // Get the position of the mouse relative to the window
            Vector2i mousePosition = Mouse::getPosition(*window);
            currentLevel->processEvents(&event, mousePosition);
        }
        // Process all update events for the current LevelObject
        currentLevel->update();
        processLevelComplete();
        // Process all drawing events for the current LevelObject
        window->clear();
        currentLevel->draw();
        window->display();
    }
}

void Game::processLevelComplete() {
    // Process level completed event
    if (currentLevel->getisFinished()) {
        // NULL the currentLevel pointer
        currentLevel = NULL;
        // Increment currentLevelCount
        if (currentLevelCount + 1 < levels.size()) {
            currentLevelCount++;
        } else {
            // If currentLevel is the last level then reset currentLevelCount
            currentLevelCount = 0;
        }
        currentLevel = levels[currentLevelCount];
    }
}
