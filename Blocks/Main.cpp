#include <string>
#include <exception>
#include "Engine/Game.hpp"
#include "Engine/DialogManager.hpp"
#include "Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

void loadResources(ResourceManager *resMan) {
	// Load all game resources
	resMan->loadImage("icon.png", "ICON");
}

void configWindow(RenderWindow *window, ResourceManager *resMan) {
	// Add icon to window
	Image icon = resMan->getImage("ICON");
	window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void freePointer(ResourceManager *resMan) {
	// Free memory used by the ResourceManager pointer
	delete resMan;
	resMan = NULL;
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
	// Load resources
    try {
		resMan = new ResourceManager(resourceArchive);
		loadResources(resMan);
    } catch (exception &ex) {
		// If exception was thrown show error message and exit game
        dialogMan.error(ex.what());
        return 1;
    }
	// Configure game window
	configWindow(game.getWindow(), resMan);
	// Run the game
    game.runLoop();
	// Delete and NULL the ResourceManager pointer and free memory
	freePointer(resMan);
    return 0; // Exit success
}
