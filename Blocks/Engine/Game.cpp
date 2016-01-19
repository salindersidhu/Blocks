#include "Game.hpp"

Game::Game(string title, int length, int width, int FPS, Image icon) {
    // Initialize and configure the main game window
    RenderWindow window(VideoMode(length, width, 32), title, Style::Close);
    window.setFramerateLimit(FPS);
    window.setIcon(32, 32, icon.getPixelsPtr());
    // Initialize and configure the DialogManager
    dialogMan = new DialogManager(title, &window);
    // Initialize game variables
    currentLevel = 0;
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

void Game::runLoop() {
    try {
        // Game loop
        while(window.isOpen()) {
            // Process all input events for the current LevelObject
            Event event;
            while(window.pollEvent(event)) {
                levels[currentLevel]->processEvents(&event);
            }
            // Process all update events for the current LevelObject
            levels[currentLevel]->update();
            processLevelComplete();
            // Process all rendering events for the current LevelObject
            window.clear();
            levels[currentLevel]->draw(&window);
            window.display();
        }
    } catch(exception &ex) {
        // If something went wrong, display an error message and exit game
        dialogMan->error(ex.what());
        window.close();
    }
}
