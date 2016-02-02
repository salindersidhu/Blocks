#include "Game.hpp"

Game::Game(string title, int length, int width, int FPS) {
    // Initialize and configure the main game window pointer
    window = new RenderWindow(VideoMode(length, width, 32), title, Style::Close);
    window->setFramerateLimit(FPS);
    // Initialize and configure the DialogManager pointer
    dialogMan = new DialogManager(title, window);
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

void Game::start() {
    // Check if any LevelObject exist
    if (levels.size() > 0) {
        // Set the currentLevel to the first LevelObject pointer
        currentLevel = levels[0];
        gameLoop();
    } else {
        // throw EngineException
        throw EngineException("Error: Level content was not found");
    }
}

void Game::gameLoop() {
    try {
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
            currentLevel->draw(window);
            window->display();
        }
    } catch(exception &ex) {
        // If something went wrong, display an error message and terminate
        dialogMan->error(ex.what());
        window->close();
    }
}

void Game::processLevelComplete() {
    // Process level completed event
    if (currentLevel->getComplete()) {
        // Delete the current level and remove from Levels vector
        delete currentLevel;
        currentLevel = NULL;
        levels.erase(levels.begin());
        // Check if the next level exists
        if (levels.size() > 0) {
            currentLevel = levels[0];
        } else {
            // throw EngineException
            throw EngineException("Error: Level content was not found");
        }
    }
}
