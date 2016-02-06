#include <string>
#include <exception>
#include "Engine/Game.hpp"
#include "Objects/GameGrid.hpp"
#include "Levels/MenuLevel.hpp"
#include "Levels/WinLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

int main() {
	// Game constants
	const string resArchive = "data.7z";
	const string icon = "IM_ICON";
	const string title = "Blocks";
	const int winWidth = 600;
	const int winHeight = 700;
	const int FPS = 60;
	const int bits = 32;
	// Initialize the Game
	Game game = Game(title, winWidth, winHeight, bits, FPS, icon, resArchive);
	// Obtain the ResourceManager and RenderWindow from Game
	ResourceManager *resMan = game.getResourceManager();
	RenderWindow *window = game.getWindow();
	// Try to call functions from ResourceManager
	try {
		// Load all of the Game's Images, Textures, Sounds and Fonts
		resMan->loadImage("icon.png", "IM_ICON");
		resMan->loadTexture("bh21.png", "TX_BH21");
		resMan->loadTexture("bh22.png", "TX_BH22");
		resMan->loadTexture("bh23.png", "TX_BH23");
		resMan->loadTexture("bh24.png", "TX_BH24");
		resMan->loadTexture("bh25.png", "TX_BH25");
		resMan->loadTexture("bh26.png", "TX_BH26");
		resMan->loadTexture("bh31.png", "TX_BH31");
		resMan->loadTexture("bh32.png", "TX_BH32");
		resMan->loadTexture("bv21.png", "TX_BV21");
		resMan->loadTexture("bv22.png", "TX_BV22");
		resMan->loadTexture("bv23.png", "TX_BV23");
		resMan->loadTexture("bv24.png", "TX_BV24");
		resMan->loadTexture("bv25.png", "TX_BV25");
		resMan->loadTexture("bv26.png", "TX_BV26");
		resMan->loadTexture("bv31.png", "TX_BV31");
		resMan->loadTexture("bv32.png", "TX_BV32");
		resMan->loadSound("victory.ogg", "SN_VICTORY");
		resMan->loadSound("hover.ogg", "SN_BUTTON_HOVER");
		resMan->loadSound("click.ogg", "SN_BUTTON_CLICK");
		resMan->loadSound("musicbg.ogg", "MS_BACKGROUND");
		resMan->loadTexture("button.png", "TX_BUTTON_NORMAL");
		resMan->loadTexture("menubg.png", "TX_BACKGROUND_MENU");
		resMan->loadTexture("levelbg.png", "TX_BACKGROUND_GAME");
		resMan->loadTexture("button_select.png", "TX_BUTTON_HOVER");
		resMan->loadFont("CooperBlackStd.otf", "FN_COPPER"); // Must load last
		// Add an icon to the Game's window
		Image icon = resMan->getImage("IM_ICON");
		window->setIcon(icon.getSize().x, icon.getSize().y,
			icon.getPixelsPtr());
		// Create and setup the main menu level
		MenuLevel *mainMenuLevel = new MenuLevel(title, resMan, window);
		// Create Level 1 and setup level 1 GameGrid
		GameGrid *gameGrid1 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid1->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
		gameGrid1->addBlock("TX_BH26", 2, 4, 0, 131, 57, false, false);
		gameGrid1->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
		gameGrid1->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
		gameGrid1->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
		GameLevel *gameLevel1 = new GameLevel("Level 1", resMan, window);
		gameLevel1->setGameGrid(gameGrid1);
		WinLevel *winLevel1 = new WinLevel("Level 1", resMan, window);
		// Create Level 2 and setup level 2 GameGrid
		GameGrid *gameGrid2 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid2->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
		gameGrid2->addBlock("TX_BH21", 2, 3, 2, 131, 57, false, true);
		gameGrid2->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
		gameGrid2->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
		gameGrid2->addBlock("TX_BV25", 2, 3, 3, 58, 131, true, false);
		gameGrid2->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
		GameLevel *gameLevel2 = new GameLevel("Level 2", resMan, window);
		gameLevel2->setGameGrid(gameGrid2);
		WinLevel *winLevel2 = new WinLevel("Level 2", resMan, window);
		GameGrid *gameGrid3 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid3->addBlock("TX_BV25", 2, 0, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BV22", 2, 1, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BH23", 2, 2, 0, 131, 57, false, false);
		gameGrid3->addBlock("TX_BH26", 2, 2, 1, 131, 57, false, false);
		gameGrid3->addBlock("TX_BV23", 2, 4, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
		gameGrid3->addBlock("TX_BV25", 2, 2, 2, 131, 57, true, false);
		gameGrid3->addBlock("TX_BV24", 2, 2, 4, 58, 131, true, false);
		gameGrid3->addBlock("TX_BV31", 3, 3, 2, 58, 221, true, false);
		gameGrid3->addBlock("TX_BV26", 2, 4, 3, 58, 131, true, false);
		GameLevel *gameLevel3 = new GameLevel("Level 3", resMan, window);
		gameLevel3->setGameGrid(gameGrid3);
		WinLevel *winLevel3 = new WinLevel("Level 3", resMan, window);
		// Add levels to the Game
		game.addLevel(mainMenuLevel);
		game.addLevel(gameLevel1);
		game.addLevel(winLevel1);
		game.addLevel(gameLevel2);
		game.addLevel(winLevel2);
		game.addLevel(gameLevel3);
		game.addLevel(winLevel3);
		// Start the Game
		game.start();
	} catch(exception &ex) {
		// Display error message and exit game if an exception was thrown
		game.getErrorDialog()->showMessage(ex.what());
		window->close();
		// Exit with failure
		return 1;
	}
	// Exit with success
	return 0;
}
