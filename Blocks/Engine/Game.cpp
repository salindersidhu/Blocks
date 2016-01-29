#include "Game.hpp"

Game::Game(string title, int length, int width, int FPS) {
    // Initialize and configure the main game window pointer
    window = new RenderWindow(VideoMode(length, width, 32), title, Style::Close);
    window->setFramerateLimit(FPS);
    // Initialize and configure the DialogManager pointer
    dialogMan = new DialogManager(title, window);
    // Initialize game variables
    currentLevel = 0;
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

RenderWindow* Game::getWindow() {
    // Return the RenderWindow pointer
    return window;
}

DialogManager* Game::getDialogMan() {
    // Return the DialogManager pointer
    return dialogMan;
}

void Game::addLevel(LevelObject *level) {
    // Add LevelObject pointer to the collection of LevelObject pointers
	levels.push_back(level);
}

void Game::processLevelComplete() {
    // Handle level completed
    if (levels[currentLevel]->getComplete()) {
        // Check if the next level exists
        if (currentLevel + 1 >= levels.size()) {
            // throw EngineException
            throw EngineException("Error: Level content was not found");
        } else {
            // Increment currentLevel
            currentLevel++;
            // Wrap currentLevel so that it resets back to 0 if > total levels
            currentLevel = currentLevel % (levels.size() - 1);
        }
    }
}

void Game::checkLevelExist() {
    // Check if any LevelObject exist
    if (levels.size() < 1) {
        // throw EngineException
        throw EngineException("Error: Level content was not found");
    }
}

void Game::runLoop() {
    try {
        // Sanity check existence of LevelObject
        checkLevelExist();
        // Game loop
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
                levels[currentLevel]->processEvents(&event, mousePosition);
            }
            // Process all update events for the current LevelObject
            levels[currentLevel]->update();
            processLevelComplete();
            // Process all rendering events for the current LevelObject
            window->clear();
            levels[currentLevel]->draw(window);
            window->display();
        }
    } catch(exception &ex) {
        // If something went wrong, display an error message and exit game
        dialogMan->error(ex.what());
        window->close();
    }
}
