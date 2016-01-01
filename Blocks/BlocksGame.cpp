#include "BlocksGame.hpp"

BlocksGame::BlocksGame() {
    // Initialize render window and set the framerate
	sf::RenderWindow window(sf::VideoMode(600, 700, 32), "Blocks", sf::Style::Close);
    window.setFramerateLimit(60);
    // Initialize dialog
    dialog = new Dialog("Blocks");
    // Initialize the draw manager
    try {
        drawMan = new DrawManager(&window, &string("Data.7z"));
    } catch (exception &ex) {
        dialog->errorDialog(ex.what());
        window.close();
    }
    // Load all resources, initialize level manager and set all levels
    loadResources();
    setLevels();
    levelMan = new LevelManager(&window, dialog, levels);
	// Main game loop
	while (window.isOpen()) {
		// Process all input events
		sf::Event event;
		while (window.pollEvent(event)) {
			levelMan->handleInputEvents(&event);
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Process all passive events
		levelMan->handlePassiveEvents();
		// Process all rendering events
		window.clear();
		levelMan->drawLevel();
		window.display();
	}
}

void BlocksGame::loadResources() {
    // Create sprites
    drawMan->createSprite("levelbg.png", "SPRITE_BG");
    drawMan->createSprite("button.png", "SPRITE_BUTTON_RESET_NORMAL");
    drawMan->createSprite("button_select.png", "SPRITE_BUTTON_RESET_SELECTED");
    drawMan->createSprite("button.png", "SPRITE_BUTTON_QUIT_NORMAL");
    drawMan->createSprite("button_select.png", "SPRITE_BUTTON_QUIT_SELECTED");
    drawMan->createSprite("bh21.png", "SPRITE_BH21");
    drawMan->createSprite("bh22.png", "SPRITE_BH22");
    drawMan->createSprite("bh23.png", "SPRITE_BH23");
    drawMan->createSprite("bh24.png", "SPRITE_BH24");
    drawMan->createSprite("bh25.png", "SPRITE_BH25");
    drawMan->createSprite("bh26.png", "SPRITE_BH26");
    drawMan->createSprite("bv21.png", "SPRITE_BV21");
    drawMan->createSprite("bv22.png", "SPRITE_BV22");
    drawMan->createSprite("bv23.png", "SPRITE_BV23");
    drawMan->createSprite("bv24.png", "SPRITE_BV24");
    drawMan->createSprite("bv25.png", "SPRITE_BV25");
    drawMan->createSprite("bv26.png", "SPRITE_BV26");
    drawMan->createSprite("bh31.png", "SPRITE_BH31");
    drawMan->createSprite("bh32.png", "SPRITE_BH32");
    drawMan->createSprite("bv31.png", "SPRITE_BV31");
    drawMan->createSprite("bv32.png", "SPRITE_BV32");
    drawMan->createSprite("bv22.png", "SPRITE_BV22_2");
    drawMan->createSprite("bv25.png", "SPRITE_BV25_2");
    drawMan->createSprite("bv32.png", "SPRITE_BV32_2");
    drawMan->createSprite("bh32.png", "SPRITE_BH32_2");
    drawMan->createSprite("bh23.png", "SPRITE_BH23_2");
    // Create text
    drawMan->createText("CooperBlackStd.otf", "TEXT_HEADER");
    drawMan->createText("CooperBlackStd.otf", "TEXT_INFO");
    drawMan->createText("CooperBlackStd.otf", "TEXT_BUTTON_RESET");
    drawMan->createText("CooperBlackStd.otf", "TEXT_BUTTON_QUIT");
}

void BlocksGame::setLevels() {
    // Level 1
    vector<Block> level1;
    level1.push_back(Block("V", "SPRITE_BV31", 3, 2, 0, 55, 167, 80, false));
    level1.push_back(Block("H", "SPRITE_BH26", 2, 4, 0, 55, 167, 80, false));
    level1.push_back(Block("H", "SPRITE_BH21", 2, 0, 2, 55, 167, 80, true));
    level1.push_back(Block("H", "SPRITE_BH32", 3, 0, 3, 55, 167, 80, false));
    level1.push_back(Block("V", "SPRITE_BV32", 3, 5, 3, 55, 167, 80, false));
    levels[1] = level1;
}
