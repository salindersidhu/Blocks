#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Dialog.hpp"
#include "SaveObject.hpp"
#include "LevelObject.hpp"
#include "EngineException.hpp"
#include "ResourceManager.hpp"
using namespace sf;
using namespace std;

class Game {
public:
    // Constructor and destructor
    Game(string, int, int, int, int);
    ~Game();
    // Game functions
    ResourceManager *getResourceManager();
    RenderWindow *getWindow();
    Dialog *getDialog();
    SaveObject *getSaveObject();
    void addLevel(LevelObject*);
    void start();
private:
    // Game private functions
    void gameLoop();
    void processLevelComplete();
    void showLoadingScreen(string);
    // Game private variables
    ResourceManager *resMan;            // ResourceManager pointer
    RenderWindow *window;               // RenderWindow pointer
    Dialog *dialog;                     // Dialog pointer
    SaveObject *saveObj;                // SaveObject pointer
    LevelObject* currentLevel;          // Current LevelObject pointer
    vector<LevelObject*> levels;        // List of LevelObject pointers
    unsigned int currentLevelCount;     // level counter
};

#endif // GAME_HPP
