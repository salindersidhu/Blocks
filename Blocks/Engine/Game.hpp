#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SaveObject.hpp"
#include "LevelObject.hpp"
#include "DialogManager.hpp"
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
        DialogManager *getDialog();
        void addLevel(LevelObject*);
        void start();
    private:
        // Game variables
        ResourceManager *resMan;
        RenderWindow *window;
        DialogManager *dialogMan;
        LevelObject* currentLevel;
        vector<LevelObject*> levels;
        SaveObject saveObj;
        unsigned int currentLevelCount;
        // Game functions
        void gameLoop();
        void processLevelComplete();
};

#endif // GAME_HPP
