#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SaveObject.hpp"
#include "LevelObject.hpp"
#include "ErrorDialog.hpp"
#include "EngineException.hpp"
#include "ResourceManager.hpp"
using namespace sf;
using namespace std;

class Game {
    public:
        // Constructor and destructor
        Game(string, int, int, int, int, string, string);
        ~Game();
        // Game functions
        ResourceManager *getResourceManager();
        RenderWindow *getWindow();
        ErrorDialog *getErrorDialog();
        SaveObject *getSaveObject();
        void addLevel(LevelObject*);
        void start();
    private:
        // Game private functions
        void gameLoop();
        void processLevelComplete();
        // Game private variables
        ResourceManager *resMan;
        RenderWindow *window;
        ErrorDialog *errorDialog;
        SaveObject *saveObj;
        LevelObject* currentLevel;
        vector<LevelObject*> levels;
        unsigned int currentLevelCount;
};

#endif // GAME_HPP
