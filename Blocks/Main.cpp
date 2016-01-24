#include <string>
#include <exception>
#include "Engine/Game.hpp"
#include "Levels/MenuLevel.hpp"
#include "Engine/DialogManager.hpp"
#include "Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

void loadResources(ResourceManager *resMan) {
	// Load all game resources
	resMan->loadImage("icon.png", "IM_ICON");
	resMan->loadTexture("button_select.png", "TX_BUTTON_HOVER");
	resMan->loadTexture("button.png", "TX_BUTTON_NORMAL");
	resMan->loadTexture("menubg.png", "TX_BACKGROUND_MENU");
	resMan->loadTexture("levelbg.png", "TX_BACKGROUND_GAME");
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
	resMan->loadFont("CooperBlackStd.otf", "FN_COPPER");
}

void setupMenuLevel(String gameTitle, Game *game, ResourceManager *resMan) {
	// Obtain the resources from the ResourceManager
	Texture normal = resMan->getTexture("TX_BUTTON_NORMAL");
	Texture hover = resMan->getTexture("TX_BUTTON_HOVER");
	Texture bg = resMan->getTexture("TX_BACKGROUND_MENU");
	Font font = resMan->getFont("FN_COPPER");
	// Create MenuLevel and add it to the Game
	MenuLevel *menu = new MenuLevel(gameTitle, font, bg, normal, hover);
	game->addLevel(menu);
}

void setupLevels(String gameTitle, Game *game, ResourceManager *resMan) {
	// Setup all LevelObjects for the Game
	setupMenuLevel(gameTitle, game, resMan);
}

void freeResourceManager(ResourceManager *resMan) {
	// Delete and NULL the ResourceManager pointer and free memory
	delete resMan;
	resMan = NULL;
}

void configWindow(RenderWindow *window, ResourceManager *resMan) {
	// Add icon to window
	Image icon = resMan->getImage("IM_ICON");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

int main() {
	// Game variables
	const string resourceArchive = "Data.7z";
	const string gameTitle = "Blocks";
	const int winWidth = 600;
	const int winHeight = 700;
	const int FPS = 60;
	// Initialize Game, DialogManager and ResourceManager
	Game game(gameTitle, winWidth, winHeight, FPS);
    DialogManager dialogMan(gameTitle, game.getWindow());
	ResourceManager *resMan;
    try {
		resMan = new ResourceManager(resourceArchive);
		// Load resources and setup all LevelObjects
		loadResources(resMan);
		setupLevels(gameTitle, &game, resMan);
    } catch (exception &ex) {
		// If exception was thrown show error message and exit game
        dialogMan.error(ex.what());
        return 1;
    }
	// Configure game window
	configWindow(game.getWindow(), resMan);
	// Run the game
    game.runLoop();
	// Free memory used by ResourceManager
	freeResourceManager(resMan);
    return 0; // Exit success
}
