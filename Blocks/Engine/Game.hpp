#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <SFML/Graphics.hpp>
#include "LevelObject.hpp"
#include "DialogManager.hpp"
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class Game {
    public:
        // Constructor and destructor
        Game(string, int, int, int);
        ~Game();
        // Game attribute functions
        RenderWindow* getWindow();
        DialogManager* getDialogMan();
        // Game functions
        void addLevel(LevelObject*);
        void start();
    private:
        // Game variables
        RenderWindow *window;
        DialogManager *dialogMan;
        vector<LevelObject*> levels;
        LevelObject* currentLevel;
        // Game functions
        void gameLoop();
        void processLevelComplete();
};

#endif // GAME_HPP
