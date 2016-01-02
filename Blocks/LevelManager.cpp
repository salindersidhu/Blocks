#include "LevelManager.hpp"

LevelManager::LevelManager(sf::RenderWindow *_window, DrawManager *draw, DialogManager *_dialog, map<int, vector<Block>> _levels) {
    // Set render window, draw manager and dialog components for the level
	window = _window;
	drawMan = draw;
    dialog = _dialog;
	grid = new Grid(55, 167, 535, 637, 80, 375);
    // Setup the game's buttons
	buttons.push_back(Button("Restart", "FONT_COPPER", "TEXTURE_BUTTON_NORMAL", "TEXTURE_BUTTON_HOVER", sf::Color(255, 255, 255), sf::Color(255, 51, 82), 30, 171, 39, 111, 107));
	buttons.push_back(Button("Quit", "FONT_COPPER", "TEXTURE_BUTTON_NORMAL", "TEXTURE_BUTTON_HOVER", sf::Color(255, 255, 255), sf::Color(255, 51, 82), 30, 171, 39, 321, 107));
	// Initalize the level
	currentLevel = 1;
	numMoves = 0;
    levels = _levels;
	createLevel();
}

void LevelManager::createLevel() {
	// Reset the level's grid, clock timer and number of moves
	grid->clear();
	clock.reset();
	numMoves = 0;
	// Configure the background, buttons, heading and display info text
	try {
		drawMan->createSprite("SPRITE_BG", "TEXTURE_BG", 0, 0);
		for (unsigned int i = 0; i < buttons.size(); i++) {
			buttons[i].set(*drawMan);
		}
		drawMan->createText("TEXT_HEADER", "FONT_COPPER", 60, sf::Color(255, 255, 255), "Level " + to_string(currentLevel), 0, 15);
        drawMan->setTextCentered("TEXT_HEADER", 600, 15);
	} catch (exception &ex) {
		dialog->error(ex.what());
		window->close();
	}
    // If there are still levels left
    if (currentLevel <= (int)levels.size()) {
        // Iterate through all the blocks of the current level
        for (unsigned int i = 0; i < levels[currentLevel].size(); i++) {
            grid->addBlock(levels[currentLevel][i]);
        }
    } else {
		// Display a game victory message at the last level and start over at level 1
		dialog->message("Congratulations!\nYou have completed all the levels!");
		currentLevel = 1;
		createLevel();
	}
	// Set the grid's blocks for drawing
	grid->set(*drawMan);
}

void LevelManager::handleLevelcleared() {
	// Check if the current level is cleared
	if (grid->isVictory()) {
		// Display a level complete message and load the next level
		string head = "LEVEL " + to_string(currentLevel) +  " COMPLETE!\n\n";
		string body = "Your time: " + clock.output() + " with " + to_string(numMoves) + " moves.";
		dialog->message(head + body);
		currentLevel++;
		createLevel();
	}
}

void LevelManager::buttonClickEvents(int mX, int mY) {
	for (unsigned int i = 0; i < buttons.size(); i++) {
		// Restart the current level if the restart button is pressed
		if (buttons[i].isSelected("Restart", mX, mY)) {
			createLevel();
		}
		// Quit the game if the quit button is pressed
		if (buttons[i].isSelected("Quit", mX, mY)) {
			window->close();
		}
	}
}

void LevelManager::buttonHoverEvents(int mX, int mY) {
	// Check if the mouse is hovering over a button
	for (unsigned int i = 0; i < buttons.size(); i++) {
		buttons[i].isHovering(mX, mY);
		buttons[i].set(*drawMan);
	}
}

void LevelManager::handlePassiveEvents() {
	// Increment the clock by 1 millisecond
	clock.tick();
	// Update the info display text
	try {
        drawMan->createText("TEXT_INFO", "FONT_COPPER", 30, sf::Color(255, 255, 255), "Time: " + clock.output() + "    Moves: " + to_string(numMoves), 0, 640);
		drawMan->setTextCentered("TEXT_INFO", 600, 640);
	} catch (exception &ex) {
		dialog->error(ex.what());
		window->close();
	}
}

void LevelManager::handleInputEvents(sf::Event *event) {
	// Get the position of the mouse relative to the window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
	// Handle mouse click events
	if (event->type == sf::Event::MouseButtonPressed) {
		// Button controls
		buttonClickEvents(mousePosition.x, mousePosition.y);
		// Grid controls
		grid->selectBlock(mousePosition.x, mousePosition.y);
	}
	// Handle mouse click release events
	if (event->type == sf::Event::MouseButtonReleased) {
		// Grid controls
		grid->releaseBlock(numMoves);
		grid->set(*drawMan);
		handleLevelcleared();
	}
	// Handle mouse movement events
	if (event->type == sf::Event::MouseMoved) {
		// Button controls
		buttonHoverEvents(mousePosition.x, mousePosition.y);
		// Grid controls
		grid->moveBlock(mousePosition.x, mousePosition.y);
		grid->set(*drawMan);
	}
}

void LevelManager::drawLevel() {
	try {
		// Draw the background
		drawMan->drawSprite("SPRITE_BG");
		// Draw the buttons
		for (unsigned int i = 0; i < buttons.size(); i++) {
			buttons[i].draw(*drawMan);
		}
		// Draw the text
		drawMan->drawText("TEXT_HEADER");
		drawMan->drawText("TEXT_INFO");
		// Draw the grid
		grid->draw(*drawMan);
	} catch (exception &ex) {
		dialog->error(ex.what());
		window->close();
	}
}
