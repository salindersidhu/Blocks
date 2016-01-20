#include "Game.hpp"

Game::Game(string title, int length, int width, int FPS) {
    // Initialize and configure the main game window
    window = new RenderWindow(VideoMode(length, width, 32), title, Style::Close);
    window->setFramerateLimit(FPS);
    // Initialize and configure the DialogManager
    dialogMan = new DialogManager(title, window);
    // Initialize game variables
    currentLevel = 0;
}

RenderWindow* Game::getWindow() {
    // Return the RenderWindow object
    return window;
}

void Game::addLevel(LevelObject *level) {
    // Add LevelObject to level map with the specified name
	levels.push_back(level);
}

void Game::processLevelComplete() {
    // Handle level completed
    if (levels[currentLevel]->isComplete()) {
        // increment currentLevel
        currentLevel++;
        // Wrap currentLevel so that it resets back to 0 if > total levels
        currentLevel = currentLevel % (levels.size() - 1);
    }
}

void Game::checkLevelExist() {
    // Check if any LevelObject exist
    if (levels.size() < 1) {
        // throw GameException
        throw GameException("Cannot find any level content");
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
                levels[currentLevel]->processEvents(&event);
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
