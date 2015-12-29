#include "LevelManager.hpp"

LevelManager::LevelManager(sf::RenderWindow *window) {

	// Initalize windows dialogs
	dialog = new WindowsDialogs(window->getSystemHandle(), WINDOW_TITLE);
	// Initalize drawing manager
	try {
		dm = new DrawManager(window, &string(GAME_RESOURCE_ARCHIVE));
	} catch (exception &ex) {
		dialog->showErrorDialog(ex.what());
		window->close();
	}
	canvasWindow = window;

	// Load all of the game's resources
	try {
		// Load sprites
		dm->loadSpriteTexture(SPRITE::LEVELBG, IMAGE_BACKGROUND);
		dm->loadSpriteTexture(SPRITE::BUTTON_RESET_NORMAL, IMAGE_BUTTON);
		dm->loadSpriteTexture(SPRITE::BUTTON_RESET_SELECTED, IMAGE_BUTTON_SELECTED);
		dm->loadSpriteTexture(SPRITE::BUTTON_QUIT_NORMAL, IMAGE_BUTTON);
		dm->loadSpriteTexture(SPRITE::BUTTON_QUIT_SELECTED, IMAGE_BUTTON_SELECTED);
		dm->loadSpriteTexture(SPRITE::BH21, IMAGE_BH21);
		dm->loadSpriteTexture(SPRITE::BH22, IMAGE_BH22);
		dm->loadSpriteTexture(SPRITE::BH23, IMAGE_BH23);
		dm->loadSpriteTexture(SPRITE::BH24, IMAGE_BH24);
		dm->loadSpriteTexture(SPRITE::BH25, IMAGE_BH25);
		dm->loadSpriteTexture(SPRITE::BH26, IMAGE_BH26);
		dm->loadSpriteTexture(SPRITE::BV21, IMAGE_BV21);
		dm->loadSpriteTexture(SPRITE::BV22, IMAGE_BV22);
		dm->loadSpriteTexture(SPRITE::BV23, IMAGE_BV23);
		dm->loadSpriteTexture(SPRITE::BV24, IMAGE_BV24);
		dm->loadSpriteTexture(SPRITE::BV25, IMAGE_BV25);
		dm->loadSpriteTexture(SPRITE::BV26, IMAGE_BV26);
		dm->loadSpriteTexture(SPRITE::BH31, IMAGE_BH31);
		dm->loadSpriteTexture(SPRITE::BH32, IMAGE_BH32);
		dm->loadSpriteTexture(SPRITE::BV31, IMAGE_BV31);
		dm->loadSpriteTexture(SPRITE::BV32, IMAGE_BV32);
		// Load duplicate sprites to have the same coloured blocks on a level
		dm->loadSpriteTexture(SPRITE::BV22_2, IMAGE_BV22);
		dm->loadSpriteTexture(SPRITE::BV25_2, IMAGE_BV25);
		dm->loadSpriteTexture(SPRITE::BV32_2, IMAGE_BV32);
		dm->loadSpriteTexture(SPRITE::BH32_2, IMAGE_BH32);
		dm->loadSpriteTexture(SPRITE::BH23_2, IMAGE_BH23);
		// Load text fonts
		dm->loadTextFont(TEXTS::HEADER, FONT_COOPER_BLACK_STD);
		dm->loadTextFont(TEXTS::INFO, FONT_COOPER_BLACK_STD);
		dm->loadTextFont(TEXTS::BUTTON_RESET, FONT_COOPER_BLACK_STD);
		dm->loadTextFont(TEXTS::BUTTON_QUIT, FONT_COOPER_BLACK_STD);
	} catch (exception &ex) {
		dialog->showErrorDialog(ex.what());
		window->close();
	}

	// Setup the game's buttons
	buttons.push_back(ButtonGUI(RESET_BUTTON_TEXT, TEXTS::BUTTON_RESET, 171, 39, 111, 107, SPRITE::BUTTON_RESET_NORMAL, SPRITE::BUTTON_RESET_SELECTED));
	buttons.push_back(ButtonGUI(QUIT_BUTTON_TEXT, TEXTS::BUTTON_QUIT, 171, 39, 321, 107, SPRITE::BUTTON_QUIT_NORMAL, SPRITE::BUTTON_QUIT_SELECTED));

	// Initalize the level
	currentLevel = 1;
	numberOfMoves = 0;
	buildLevel();
}

void LevelManager::buildLevel() {

	// Reset the level's grid, clock timer and number of moves
	grid.clear();
	timer.reset();
	numberOfMoves = 0;

	// Configure the background, buttons, heading and display info text
	try {
		dm->configSpritePosition(SPRITE::LEVELBG, 0, 0);
		for (unsigned int i = 0; i < buttons.size(); i++) {
			buttons[i].configure(dm);
		}
		dm->configTextCenterHorizontal(TEXTS::HEADER, 60, WHITE, "Level " + to_string(currentLevel), 15);
		dm->configTextCenterHorizontal(TEXTS::INFO, 30, WHITE, "Time: " + timer.output() + "    Moves: " + to_string(numberOfMoves), 640);
	} catch (exception &ex) {
		dialog->showErrorDialog(ex.what());
		canvasWindow->close();
	}

	// Add blocks to the grid corresponding to the next level
	if (currentLevel == 1) {
		grid.addBlock(Block(ORIENTATION::V, 3, 2, 0, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 0, SPRITE::BH26, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 3, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 3, SPRITE::BV32, false));
	}
	else if (currentLevel == 2) {
		grid.addBlock(Block(ORIENTATION::V, 3, 2, 0, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 3, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 1, SPRITE::BV32, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 3, SPRITE::BH31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 3, 3, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 4, SPRITE::BH23, false));
	}
	else if (currentLevel == 3) {
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 0, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 1, 0, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 2, 0, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 2, 1, SPRITE::BH26, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 4, 0, SPRITE::BV23, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 2, SPRITE::BV25_2, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 4, SPRITE::BV24, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 3, 2, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 4, 3, SPRITE::BV26, false));
	}
	else if (currentLevel == 4) {
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 3, SPRITE::BH31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 1, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 4, SPRITE::BV23, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 1, 4, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 4, SPRITE::BV26, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 4, 1, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 5, 2, SPRITE::BV21, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 4, SPRITE::BH25, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 5, SPRITE::BH23, false));
	}
	else if (currentLevel == 5) {
		grid.addBlock(Block(ORIENTATION::H, 3, 2, 0, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 1, SPRITE::BH31, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 3, SPRITE::BH32_2, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 4, SPRITE::BH24, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 5, SPRITE::BH22, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 4, 1, SPRITE::BV32, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 5, 2, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 4, SPRITE::BV24, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 4, SPRITE::BV23, false));
	}
	else if (currentLevel == 6) {
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::H, 2, 3, 3, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 1, 4, SPRITE::BH26, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 0, 5, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 2, 1, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 5, 1, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 3, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 3, 4, SPRITE::BV23, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 4, 4, SPRITE::BV26, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 3, SPRITE::BV32, false));
	}
	else if (currentLevel == 7) {
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 0, SPRITE::BH25, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 3, 0, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 1, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 1, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::H, 2, 3, 3, SPRITE::BH26, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 4, SPRITE::BH22, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 3, 5, SPRITE::BH31, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 3, 1, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 2, SPRITE::BV24, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 2, 3, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 2, SPRITE::BV32, false));
	}
	else if (currentLevel == 8) {
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 0, SPRITE::BH25, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 5, SPRITE::BH24, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 1, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 0, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 0, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 1, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::V, 3, 0, 2, SPRITE::BV32, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 1, SPRITE::BH26, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 3, 4, SPRITE::BV22_2, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 5, SPRITE::BH22, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 1, 3, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 4, 4, SPRITE::BH23_2, false));
	}
	else if (currentLevel == 9) {
		grid.addBlock(Block(ORIENTATION::H, 2, 2, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::V, 2, 4, 1, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 4, 3, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 3, 0, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 1, 4, SPRITE::BH31, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 2, 3, SPRITE::BH23_2, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 1, 2, SPRITE::BV24, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 0, SPRITE::BV26, false));
	} 
	else if (currentLevel == 10) {
		grid.addBlock(Block(ORIENTATION::H, 2, 1, 2, SPRITE::BH21, true));
		grid.addBlock(Block(ORIENTATION::V, 3, 4, 1, SPRITE::BV31, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 5, 1, SPRITE::BV32, false));
		grid.addBlock(Block(ORIENTATION::V, 3, 3, 2, SPRITE::BV32_2, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 3, 0, SPRITE::BV22, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 2, 3, SPRITE::BV26, false));
		grid.addBlock(Block(ORIENTATION::H, 3, 3, 5, SPRITE::BH32, false));
		grid.addBlock(Block(ORIENTATION::V, 2, 0, 4, SPRITE::BV25, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 3, SPRITE::BH22, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 1, SPRITE::BH23, false));
		grid.addBlock(Block(ORIENTATION::H, 2, 0, 0, SPRITE::BH25, false));
	} else {
		// Display a game victory message at the last level and start over at level 1
		dialog->showInfoDialog(GAME_WON_MESSAGE);
		currentLevel = 1;
		buildLevel();
	}

	// Configure the grid's blocks for drawing
	grid.configure(dm);
}

void LevelManager::checkLevelCleared() {
	// Check if the current level is cleared
	if (grid.isVictory()) {
		// Display a level complete message and load the next level
		string head = "LEVEL " + to_string(currentLevel) +  " COMPLETE!\n\n";
		string body = "Your time: " + timer.output() + " with " + to_string(numberOfMoves) + " moves.";
		dialog->showInfoDialog(head + body);
		currentLevel++;
		buildLevel();
	}
}

void LevelManager::buttonEvent(int m_x, int m_y) {
	for (unsigned int i = 0; i < buttons.size(); i++) {
		// Restart the current level if the restart button is pressed
		if (buttons[i].selected(m_x, m_y, SPRITE::BUTTON_RESET_SELECTED)) {
			buildLevel();
		}
		// Quit the game if the quit button is pressed
		if (buttons[i].selected(m_x, m_y, SPRITE::BUTTON_QUIT_SELECTED)) {
			canvasWindow->close();
		}
	}
}

void LevelManager::buttonHover(int m_x, int m_y) {
	// Check if the mouse is hovering over a button
	for (unsigned int i = 0; i < buttons.size(); i++) {
		buttons[i].hovering(m_x, m_y);
		buttons[i].configure(dm);
	}
}

void LevelManager::handleTimer() {

	// Increment the timer by 1 millisecond
	timer.tick();

	// Update the info display text
	try {
		dm->configTextCenterHorizontal(TEXTS::INFO, 30, WHITE, "Time: " + timer.output() + "    Moves: " + to_string(numberOfMoves), 640);
	} catch (exception &ex) {
		dialog->showErrorDialog(ex.what());
		canvasWindow->close();
	}
}

void LevelManager::handleEvents(sf::Event *event) {

	// Get the position of the mouse relative to the window
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*canvasWindow);

	// Handle mouse click events
	if (event->type == sf::Event::MouseButtonPressed) {
		// Button controls
		buttonEvent(mousePosition.x, mousePosition.y);
		// Grid controls
		grid.selectBlock(mousePosition.x, mousePosition.y);
	}
	// Handle mouse click release events
	if (event->type == sf::Event::MouseButtonReleased) {
		// Grid controls
		grid.releaseBlock(numberOfMoves);
		grid.configure(dm);
		checkLevelCleared();
	}
	// Handle mouse movement events
	if (event->type == sf::Event::MouseMoved) {
		// Button controls
		buttonHover(mousePosition.x, mousePosition.y);
		// Grid controls
		grid.moveBlock(mousePosition.x, mousePosition.y);
		grid.configure(dm);
	}
}

void LevelManager::drawLevel() {
	try {
		// Draw the background
		dm->drawSprite(SPRITE::LEVELBG);
		// Draw the buttons
		for (unsigned int i = 0; i < buttons.size(); i++) {
			buttons[i].draw(dm);
		}
		// Draw the text
		dm->drawText(TEXTS::HEADER);
		dm->drawText(TEXTS::INFO);
		// Draw the grid
		grid.draw(dm);
	} catch (exception &ex) {
		dialog->showErrorDialog(ex.what());
		canvasWindow->close();
	}
}