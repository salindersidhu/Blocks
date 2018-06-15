#include "BlockGame.hpp"

BlockGame::BlockGame() {
	// Define Game constants
    const string title = "Blocks";
    const int winWidth = 600;
    const int winHeight = 700;
    const int FPS = 60;
    const int bits = 32;
    // Initialize the Game
    game = new Game(title, winWidth, winHeight, bits, FPS);
    // Obtain the ResourceManager, RenderWindow and SaveObject from Game
    resMan = game->getResourceManager();
    window = game->getWindow();
    saveObj = game->getSaveObject();
    try {
        showLoadingScreen();
        loadGameResources();
        setWindowIcon();
        setupLevels(title, winWidth);
        // Start the Game
        game->start();
        // Clean up Game pointer
        cleanup();
    } catch(exception &ex) {
        // Display error message and exit game if an exception was thrown
        game->getDialog()->showError(ex.what());
        window->close();
        // Clean up Game pointer
        cleanup();
    }
}

void BlockGame::cleanup() {
    // Delete and NULL the Game pointer to free up memory
    delete game;
    game = NULL;
}

void BlockGame::setWindowIcon() {
    // Add an icon to the Game's window
    Image icon = resMan->getImage("IM_ICON");
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void BlockGame::addGameLevel(string title, GameGrid *grid) {
    // Create and setup GameLevel and WinLevel objects
    GameLevel *gameLevel = new GameLevel(title, resMan, window, saveObj);
    gameLevel->setGameGrid(grid);
    WinLevel *winLevel = new WinLevel(title, resMan, window, saveObj);
    // Add GameLevel and WinLevel into Game
    game->addLevel(gameLevel);
    game->addLevel(winLevel);
}

void BlockGame::setupLevels(string gameTitle, int winWidth) {
    // Create and MenuLevel and add it into Game
    MenuLevel *menu = new MenuLevel(gameTitle, resMan, window, saveObj);
    game->addLevel(menu);
    // Create Level 1 and setup level 1 GameGrid
    GameGrid *gameGrid1 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid1->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
    gameGrid1->addBlock("TX_BH26", 2, 4, 0, 131, 57, false, false);
    gameGrid1->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid1->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
    gameGrid1->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
    addGameLevel("Level 1", gameGrid1);
    // Create Level 2 and setup level 2 GameGrid
    GameGrid *gameGrid2 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid2->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
    gameGrid2->addBlock("TX_BH21", 2, 3, 2, 131, 57, false, true);
    gameGrid2->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
    gameGrid2->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
    gameGrid2->addBlock("TX_BV25", 2, 3, 3, 58, 131, true, false);
    gameGrid2->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
    addGameLevel("Level 2", gameGrid2);
    // Create Level 3 and setup level 3 GameGrid
    GameGrid *gameGrid3 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid3->addBlock("TX_BV25", 2, 0, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV22", 2, 1, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BH23", 2, 2, 0, 131, 57, false, false);
    gameGrid3->addBlock("TX_BH26", 2, 2, 1, 131, 57, false, false);
    gameGrid3->addBlock("TX_BV23", 2, 4, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid3->addBlock("TX_BV25", 2, 2, 2, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV24", 2, 2, 4, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV31", 3, 3, 2, 58, 221, true, false);
    gameGrid3->addBlock("TX_BV26", 2, 4, 3, 58, 131, true, false);
    addGameLevel("Level 3", gameGrid3);
    // Create Level 4 and setup level 4 GameGrid
    GameGrid *gameGrid4 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid4->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid4->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
    gameGrid4->addBlock("TX_BV25", 2, 2, 1, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV23", 2, 0, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV22", 2, 1, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV26", 2, 2, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV31", 3, 4, 1, 58, 221, true, false);
    gameGrid4->addBlock("TX_BV21", 2, 5, 2, 58, 131, true, false);
    gameGrid4->addBlock("TX_BH25", 2, 4, 4, 131, 57, false, false);
    gameGrid4->addBlock("TX_BH23", 2, 4, 5, 131, 57, false, false);
    addGameLevel("Level 4", gameGrid4);
    // Create Level 5 and setup level 5 GameGrid
    GameGrid *gameGrid5 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid5->addBlock("TX_BH32", 3, 2, 0, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH31", 3, 0, 1, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid5->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH24", 2, 4, 4, 131, 57, false, false);
    gameGrid5->addBlock("TX_BH22", 2, 4, 5, 131, 57, false, false);
    gameGrid5->addBlock("TX_BV32", 3, 4, 1, 58, 221, true, false);
    gameGrid5->addBlock("TX_BV25", 2, 5, 2, 58, 131, true, false);
    gameGrid5->addBlock("TX_BV24", 2, 0, 4, 58, 131, true, false);
    gameGrid5->addBlock("TX_BV23", 2, 2, 4, 58, 131, true, false);
    addGameLevel("Level 5", gameGrid5);
    // Create Level 6 and setup level 6 GameGrid
    GameGrid *gameGrid6 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid6->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid6->addBlock("TX_BH23", 2, 3, 3, 131, 57, false, false);
    gameGrid6->addBlock("TX_BH26", 2, 1, 4, 131, 57, false, false);
    gameGrid6->addBlock("TX_BH32", 3, 0, 5, 221, 57, false, false);
    gameGrid6->addBlock("TX_BV31", 3, 2, 1, 58, 221, true, false);
    gameGrid6->addBlock("TX_BV25", 2, 5, 1, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV22", 2, 0, 3, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV23", 2, 3, 4, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV26", 2, 4, 4, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
    addGameLevel("Level 6", gameGrid6);
    // Create Level 7 and setup level 7 GameGrid
    GameGrid *gameGrid7 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid7->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH32", 3, 3, 0, 221, 57, false, false);
    gameGrid7->addBlock("TX_BH23", 2, 4, 1, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid7->addBlock("TX_BH26", 2, 3, 3, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH22", 2, 0, 4, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH31", 3, 3, 5, 221, 57, false, false);
    gameGrid7->addBlock("TX_BV22", 2, 3, 1, 58, 131, true, false);
    gameGrid7->addBlock("TX_BV24", 2, 0, 2, 58, 131, true, false);
    gameGrid7->addBlock("TX_BV31", 3, 2, 3, 58, 221, true, false);
    gameGrid7->addBlock("TX_BV32", 3, 5, 2, 58, 221, true, false);
    addGameLevel("Level 7", gameGrid7);
    // Create Level 8 and setup level 8 GameGrid
    GameGrid *gameGrid8 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid8->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    gameGrid8->addBlock("TX_BH24", 2, 4, 5, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV31", 3, 5, 1, 58, 221, true, false);
    gameGrid8->addBlock("TX_BH23", 2, 4, 0, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV22", 2, 2, 0, 58, 131, true, false);
    gameGrid8->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid8->addBlock("TX_BV32", 3, 0, 2, 58, 221, true, false);
    gameGrid8->addBlock("TX_BH26", 2, 0, 1, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV22", 2, 3, 4, 58, 131, true, false);
    gameGrid8->addBlock("TX_BH22", 2, 0, 5, 131, 57, false, false);
    gameGrid8->addBlock("TX_BH32", 3, 1, 3, 221, 57, false, false);
    gameGrid8->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
    addGameLevel("Level 8", gameGrid8);
    // Create Level 9 and setup level 9 GameGrid
    GameGrid *gameGrid9 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid9->addBlock("TX_BH21", 2, 2, 2, 131, 57, false, true);
    gameGrid9->addBlock("TX_BV22", 2, 4, 1, 58, 131, true, false);
    gameGrid9->addBlock("TX_BV25", 2, 4, 3, 58, 131, true, false);
    gameGrid9->addBlock("TX_BH23", 2, 3, 0, 131, 57, false, false);
    gameGrid9->addBlock("TX_BH31", 3, 1, 4, 221, 57, false, false);
    gameGrid9->addBlock("TX_BH23", 2, 2, 3, 131, 57, false, false);
    gameGrid9->addBlock("TX_BV24", 2, 1, 2, 58, 131, true, false);
    gameGrid9->addBlock("TX_BV26", 2, 2, 0, 58, 131, true, false);
    addGameLevel("Level 9", gameGrid9);
    // Create Level 10 and setup level 10 GameGrid
    GameGrid *gameGrid10 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid10->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid10->addBlock("TX_BV31", 3, 4, 1, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV32", 3, 3, 2, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV22", 2, 3, 0, 58, 131, true, false);
    gameGrid10->addBlock("TX_BV26", 2, 2, 3, 58, 131, true, false);
    gameGrid10->addBlock("TX_BH32", 3, 3, 5, 221, 57, false, false);
    gameGrid10->addBlock("TX_BV25", 2, 0, 4, 58, 131, true, false);
    gameGrid10->addBlock("TX_BH22", 2, 0, 3, 131, 57, false, false);
    gameGrid10->addBlock("TX_BH23", 2, 0, 1, 131, 57, false, false);
    gameGrid10->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    addGameLevel("Level 10", gameGrid10);
}

void BlockGame::showLoadingScreen() {
    // Load default Font from ResourceManager
    resMan->loadFont(_acCooperBlackStd, sizeof(_acCooperBlackStd), "FN_DEFAULT");
    // Create the loading display text and font
    Text loadingText;
    Font font = resMan->getFont("FN_DEFAULT");
    // Configure the loading display text
    loadingText.setFont(font);
    loadingText.setString("Loading Please Wait...");
    loadingText.setCharacterSize(40);
    loadingText.setColor(Color(38, 38, 38));
    // Center the loading display text on the screen
    FloatRect rect = loadingText.getLocalBounds();
    loadingText.setOrigin((rect.left + rect.width) / 2, (rect.top +
        rect.height) / 2);
    loadingText.setPosition((float)window->getSize().x / 2,
        (float)window->getSize().y / 2);
    // Draw the text
    window->clear(Color(64, 64, 64));
    window->draw(loadingText);
    window->display();
}

void BlockGame::loadGameResources() {
    // Load all of the Game's Images, Textures, Sounds and Fonts
    resMan->loadTexture(_acbh21, sizeof(_acbh21), "TX_BH21");
    resMan->loadTexture(_acbh22, sizeof(_acbh22), "TX_BH22");
    resMan->loadTexture(_acbh23, sizeof(_acbh23), "TX_BH23");
    resMan->loadTexture(_acbh24, sizeof(_acbh24), "TX_BH24"); 
    resMan->loadTexture(_acbh25, sizeof(_acbh25), "TX_BH25");
    resMan->loadTexture(_acbh26, sizeof(_acbh26), "TX_BH26");
    resMan->loadTexture(_acbh31, sizeof(_acbh31), "TX_BH31");
    resMan->loadTexture(_acbh32, sizeof(_acbh32), "TX_BH32");
    resMan->loadTexture(_acbv21, sizeof(_acbv21), "TX_BV21");
    resMan->loadTexture(_acbv22, sizeof(_acbv22), "TX_BV22");
    resMan->loadTexture(_acbv23, sizeof(_acbv23), "TX_BV23");
    resMan->loadTexture(_acbv24, sizeof(_acbv24), "TX_BV24");
    resMan->loadTexture(_acbv25, sizeof(_acbv25), "TX_BV25");
    resMan->loadTexture(_acbv26, sizeof(_acbv26), "TX_BV26");
    resMan->loadTexture(_acbv31, sizeof(_acbv31), "TX_BV31");
    resMan->loadTexture(_acbv32, sizeof(_acbv32), "TX_BV32");
    resMan->loadImage(_acicon, sizeof(_acicon), "IM_ICON");
    resMan->loadFont(_acCooperBlackStd, sizeof(_acCooperBlackStd), "FN_COPPER");
    resMan->loadTexture(_acmenubg, sizeof(_acmenubg), "TX_BACKGROUND_MENU");
    resMan->loadTexture(_aclevelbg, sizeof(_aclevelbg), "TX_BACKGROUND_GAME");
    resMan->loadTexture(_acbutton_select, sizeof(_acbutton_select), "TX_BUTTON_NORMAL");
    resMan->loadTexture(_acbutton_select, sizeof(_acbutton_select), "TX_BUTTON_HOVER");
}
