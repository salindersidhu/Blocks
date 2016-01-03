#include "BlocksGame.hpp"

BlocksGame::BlocksGame() {
    // Initialize render window and set the framerate
	sf::RenderWindow window(sf::VideoMode(600, 700, 32), "Blocks", sf::Style::Close);
    window.setFramerateLimit(60);
    // Initialize dialog
    dialog = new DialogManager("Blocks");
    try {
		// Initialize the draw manager
		string resourceFile = "Data.7z";
		DrawManager drawMan = DrawManager(&window, &resourceFile);
		// Load all resources and setup the level
		loadResourceData(drawMan);
		loadLevelData(levels);
		// Set window icon
		window.setIcon(32, 32, drawMan.getImage("IMAGE_ICON").getPixelsPtr());
		// Initialize the level manager
		LevelManager levelMan = LevelManager(&window, &drawMan, dialog, levels);
		// Game loop
		while (window.isOpen()) {
			// Process all input events
			sf::Event event;
			while (window.pollEvent(event)) {
				levelMan.handleInputEvents(&event);
			}
			// Process all passive events
			levelMan.handlePassiveEvents();
			// Process all rendering events
			window.clear();
			levelMan.drawLevel();
			window.display();
		}
    } catch (exception &ex) {
		// If something went wrong, display error message and close the window
        dialog->error(ex.what());
        window.close();
    }
}

void BlocksGame::loadResourceData(DrawManager &drawMan) {
    // Load textures
	drawMan.loadTexture("levelbg.png", "TEXTURE_BG");
	drawMan.loadTexture("button.png", "TEXTURE_BUTTON_NORMAL");
	drawMan.loadTexture("button_select.png", "TEXTURE_BUTTON_HOVER");
	drawMan.loadTexture("bh21.png", "TEXTURE_BH21");
	drawMan.loadTexture("bh22.png", "TEXTURE_BH22");
	drawMan.loadTexture("bh23.png", "TEXTURE_BH23");
	drawMan.loadTexture("bh24.png", "TEXTURE_BH24");
	drawMan.loadTexture("bh25.png", "TEXTURE_BH25");
	drawMan.loadTexture("bh26.png", "TEXTURE_BH26");
	drawMan.loadTexture("bv21.png", "TEXTURE_BV21");
	drawMan.loadTexture("bv22.png", "TEXTURE_BV22");
	drawMan.loadTexture("bv23.png", "TEXTURE_BV23");
	drawMan.loadTexture("bv24.png", "TEXTURE_BV24");
	drawMan.loadTexture("bv25.png", "TEXTURE_BV25");
	drawMan.loadTexture("bv26.png", "TEXTURE_BV26");
	drawMan.loadTexture("bh31.png", "TEXTURE_BH31");
	drawMan.loadTexture("bh32.png", "TEXTURE_BH32");
	drawMan.loadTexture("bv31.png", "TEXTURE_BV31");
	drawMan.loadTexture("bv32.png", "TEXTURE_BV32");
	// Load images
	drawMan.loadImage("icon.png", "IMAGE_ICON");
	// Load fonts
	drawMan.loadFont("CooperBlackStd.otf", "FONT_COPPER");
}

void BlocksGame::loadLevelData(map<int, vector<Block>> &levels) {
    // Construct blocks for level 1
    vector<Block> level1;
    level1.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 2, 0, false));
    level1.push_back(Block("SPRITE_BH26", "TEXTURE_BH26", "H", 2, 4, 0, false));
    level1.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 0, 2, true));
    level1.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 0, 3, false));
    level1.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 5, 3, false));
    levels[1] = level1;
	// Construct blocks for level 2
	vector<Block> level2;
	level2.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 2, 0, false));
	level2.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 3, 2, true));
	level2.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 5, 1, false));
	level2.push_back(Block("SPRITE_BH31", "TEXTURE_BH31", "H", 3, 0, 3, false));
	level2.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 3, 3, false));
	level2.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 4, 4, false));
	levels[2] = level2;
	// Construct blocks for level 3
	vector<Block> level3;
	level3.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 0, 0, false));
	level3.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 1, 0, false));
	level3.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 2, 0, false));
	level3.push_back(Block("SPRITE_BH26", "TEXTURE_BH26", "H", 2, 2, 1, false));
	level3.push_back(Block("SPRITE_BV23", "TEXTURE_BV23", "V", 2, 4, 0, false));
	level3.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 0, 2, true));
	level3.push_back(Block("SPRITE_BV25_2", "TEXTURE_BV25", "V", 2, 2, 2, false));
	level3.push_back(Block("SPRITE_BV24", "TEXTURE_BV24", "V", 2, 2, 4, false));
	level3.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 3, 2, false));
	level3.push_back(Block("SPRITE_BV26", "TEXTURE_BV26", "V", 2, 4, 3, false));
	levels[3] = level3;
	// Construct blocks for level 4
	vector<Block> level4;
	level4.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 0, 2, true));
	level4.push_back(Block("SPRITE_BH31", "TEXTURE_BH31", "H", 3, 0, 3, false));
	level4.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 2, 1, false));
	level4.push_back(Block("SPRITE_BV23", "TEXTURE_BV23", "V", 2, 0, 4, false));
	level4.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 1, 4, false));
	level4.push_back(Block("SPRITE_BV26", "TEXTURE_BV26", "V", 2, 2, 4, false));
	level4.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 4, 1, false));
	level4.push_back(Block("SPRITE_BV21", "TEXTURE_BV21", "V", 2, 5, 2, false));
	level4.push_back(Block("SPRITE_BH25", "TEXTURE_BH25", "H", 2, 4, 4, false));
	level4.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 4, 5, false));
	levels[4] = level4;
	// Construct blocks for level 5
	vector<Block> level5;
	level5.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 2, 0, false));
	level5.push_back(Block("SPRITE_BH31", "TEXTURE_BH31", "H", 3, 0, 1, false));
	level5.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 0, 2, true));
	level5.push_back(Block("SPRITE_BH32_2", "TEXTURE_BH32", "H", 3, 0, 3, false));
	level5.push_back(Block("SPRITE_BH24", "TEXTURE_BH24", "H", 2, 4, 4, false));
	level5.push_back(Block("SPRITE_BH22", "TEXTURE_BH22", "H", 2, 4, 5, false));
	level5.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 4, 1, false));
	level5.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 5, 2, false));
	level5.push_back(Block("SPRITE_BV24", "TEXTURE_BV24", "V", 2, 0, 4, false));
	level5.push_back(Block("SPRITE_BV23", "TEXTURE_BV23", "V", 2, 2, 4, false));
	levels[5] = level5;
	// Construct blocks for level 6
	vector<Block> level6;
	level6.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 0, 2, true));
	level6.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 3, 3, false));
	level6.push_back(Block("SPRITE_BH26", "TEXTURE_BH26", "H", 2, 1, 4, false));
	level6.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 0, 5, false));
	level6.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 2, 1, false));
	level6.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 5, 1, false));
	level6.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 0, 3, false));
	level6.push_back(Block("SPRITE_BV23", "TEXTURE_BV23", "V", 2, 3, 4, false));
	level6.push_back(Block("SPRITE_BV26", "TEXTURE_BV26", "V", 2, 4, 4, false));
	level6.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 5, 3, false));
	levels[6] = level6;
	// Construct blocks for level 7
	vector<Block> level7;
	level7.push_back(Block("SPRITE_BH25", "TEXTURE_BH25", "H", 2, 0, 0, false));
	level7.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 3, 0, false));
	level7.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 4, 1, false));
	level7.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 1, 2, true));
	level7.push_back(Block("SPRITE_BH26", "TEXTURE_BH26", "H", 2, 3, 3, false));
	level7.push_back(Block("SPRITE_BH22", "TEXTURE_BH22", "H", 2, 0, 4, false));
	level7.push_back(Block("SPRITE_BH31", "TEXTURE_BH31", "H", 3, 3, 5, false));
	level7.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 3, 1, false));
	level7.push_back(Block("SPRITE_BV24", "TEXTURE_BV24", "V", 2, 0, 2, false));
	level7.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 2, 3, false));
	level7.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 5, 2, false));
	levels[7] = level7;
	// Construct blocks for level 8
	vector<Block> level8;
	level8.push_back(Block("SPRITE_BH25", "TEXTURE_BH25", "H", 2, 0, 0, false));
	level8.push_back(Block("SPRITE_BH24", "TEXTURE_BH24", "H", 2, 4, 5, false));
	level8.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 5, 1, false));
	level8.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 4, 0, false));
	level8.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 2, 0, false));
	level8.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 1, 2, true));
	level8.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 0, 2, false));
	level8.push_back(Block("SPRITE_BH26", "TEXTURE_BH26", "H", 2, 0, 1, false));
	level8.push_back(Block("SPRITE_BV22_2", "TEXTURE_BV22", "V", 2, 3, 4, false));
	level8.push_back(Block("SPRITE_BH22", "TEXTURE_BH22", "H", 2, 0, 5, false));
	level8.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 1, 3, false));
	level8.push_back(Block("SPRITE_BH23_2", "TEXTURE_BH23", "H", 2, 4, 4, false));
	levels[8] = level8;
	// Construct blocks for level 9
	vector<Block> level9;
	level9.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 2, 2, true));
	level9.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 4, 1, false));
	level9.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 4, 3, false));
	level9.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 3, 0, false));
	level9.push_back(Block("SPRITE_BH31", "TEXTURE_BH31", "H", 3, 1, 4, false));
	level9.push_back(Block("SPRITE_BH23_2", "TEXTURE_BH23", "H", 2, 2, 3, false));
	level9.push_back(Block("SPRITE_BV24", "TEXTURE_BV24", "V", 2, 1, 2, false));
	level9.push_back(Block("SPRITE_BV26", "TEXTURE_BV26", "V", 2, 2, 0, false));
	levels[9] = level9;
	// Construct blocks for level 10
	vector<Block> level10;
	level10.push_back(Block("SPRITE_BH21", "TEXTURE_BH21", "H", 2, 1, 2, true));
	level10.push_back(Block("SPRITE_BV31", "TEXTURE_BV31", "V", 3, 4, 1, false));
	level10.push_back(Block("SPRITE_BV32", "TEXTURE_BV32", "V", 3, 5, 1, false));
	level10.push_back(Block("SPRITE_BV32_2", "TEXTURE_BV32", "V", 3, 3, 2, false));
	level10.push_back(Block("SPRITE_BV22", "TEXTURE_BV22", "V", 2, 3, 0, false));
	level10.push_back(Block("SPRITE_BV26", "TEXTURE_BV26", "V", 2, 2, 3, false));
	level10.push_back(Block("SPRITE_BH32", "TEXTURE_BH32", "H", 3, 3, 5, false));
	level10.push_back(Block("SPRITE_BV25", "TEXTURE_BV25", "V", 2, 0, 4, false));
	level10.push_back(Block("SPRITE_BH22", "TEXTURE_BH22", "H", 2, 0, 3, false));
	level10.push_back(Block("SPRITE_BH23", "TEXTURE_BH23", "H", 2, 0, 1, false));
	level10.push_back(Block("SPRITE_BH25", "TEXTURE_BH25", "H", 2, 0, 0, false));
	levels[10] = level10;
}
