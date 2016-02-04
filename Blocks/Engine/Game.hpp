#ifndef GAME_HPP
#define GAME_HPP

#include <string>
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
        // Game functions
        string getTitle();
        RenderWindow* getWindow();
        DialogManager* getDialog();
        void addLevel(LevelObject*);
        void start();
    private:
        // Game variables
        String title;
        RenderWindow *window;
        DialogManager *dialogMan;
        LevelObject* currentLevel;
        vector<LevelObject*> levels;
        // Game functions
        void gameLoop();
        void processLevelComplete();
};

#endif // GAME_HPP
