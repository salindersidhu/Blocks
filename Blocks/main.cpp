#include <string>
#include <exception>
#include "Engine/Game.hpp"
#include "Levels/MenuLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Objects/GameGrid.hpp"
#include "Engine/DialogManager.hpp"
#include "Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

void loadResources(ResourceManager *res) {
	// Load all of the game's Images, Textures, Sounds and Fonts
	res->loadImage("icon.png", "IM_ICON");
	res->loadTexture("bh21.png", "TX_BH21");
	res->loadTexture("bh22.png", "TX_BH22");
	res->loadTexture("bh23.png", "TX_BH23");
	res->loadTexture("bh24.png", "TX_BH24");
	res->loadTexture("bh25.png", "TX_BH25");
	res->loadTexture("bh26.png", "TX_BH26");
	res->loadTexture("bh31.png", "TX_BH31");
	res->loadTexture("bh32.png", "TX_BH32");
	res->loadTexture("bv21.png", "TX_BV21");
	res->loadTexture("bv22.png", "TX_BV22");
	res->loadTexture("bv23.png", "TX_BV23");
	res->loadTexture("bv24.png", "TX_BV24");
	res->loadTexture("bv25.png", "TX_BV25");
	res->loadTexture("bv26.png", "TX_BV26");
	res->loadTexture("bv31.png", "TX_BV31");
	res->loadTexture("bv32.png", "TX_BV32");
	res->loadSound("victory.ogg", "SN_VICTORY");
	res->loadSound("hover.ogg", "SN_BUTTON_HOVER");
	res->loadSound("click.ogg", "SN_BUTTON_CLICK");
	res->loadSound("musicbg.ogg", "MS_BACKGROUND");
	res->loadTexture("button.png", "TX_BUTTON_NORMAL");
	res->loadTexture("menubg.png", "TX_BACKGROUND_MENU");
	res->loadTexture("levelbg.png", "TX_BACKGROUND_GAME");
	res->loadTexture("button_select.png", "TX_BUTTON_HOVER");
	// Fonts must be loaded last because stream must remain open
	res->loadFont("CooperBlackStd.otf", "FN_COPPER");
}

void setupLevels(Game *game, ResourceManager *res, RenderWindow *win) {
	// Initialize MenuLevel and add it to the Game
	MenuLevel *ml = new MenuLevel(game->getTitle(), res, win);
	game->addLevel(ml);
	// Initialize GameLevel one and add it to the Game
	GameLevel *gl = new GameLevel("Level 1", res, win);
	// Initalize GameGrid and Blocks
	GameGrid *gameGrid = new GameGrid(55, 167, 480, 470, 375, 407, 80, res);
	gameGrid->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
	gameGrid->addBlock("TX_BH26", 2, 4, 0, 131, 57, false, false);
	gameGrid->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
	gameGrid->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
	gameGrid->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
	// Set the GameGrid to the GameLevel
	gl->setGameGrid(gameGrid);
	game->addLevel(gl);
}

int main() {
	// Game variables
	const string resourceArchive = "data.7z";
	const string title = "Blocks";
	const int winWidth = 600;
	const int winHeight = 700;
	const int bits = 32;
	const int FPS = 60;
	// Initialize Game, RenderWindow and ResourceManager
	Game game(title, winWidth, winHeight, bits, FPS);
	ResourceManager *res;
	RenderWindow *win = game.getWindow();
    try {
		res = new ResourceManager(resourceArchive);
		// Load resources and setup all Levels
		loadResources(res);
		setupLevels(&game, res, win);
		// Add an icon to the Game's window
		Image icon = res->getImage("IM_ICON");
		win->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    } catch (exception &ex) {
		// If exception was thrown show error message and exit game
		game.getDialog()->error(ex.what());
        return 1;
    }
	// Start the game
    game.start();
	// Delete the ResourceManager pointer and free memory
	delete res;
	res = NULL;
    return 0; // Exit success
}
