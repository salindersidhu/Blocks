#ifndef GAME_HPP
#define GAME_HPP

#include <map>
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
        // Game functions
        void addLevel(LevelObject*);
        void runLoop();
    private:
        // Game variables
        int currentLevel;
        RenderWindow *window;
        DialogManager *dialogMan;
        vector<LevelObject*> levels;
        // Game functions
        void processLevelComplete();
        void checkLevelExist();
};

#endif // GAME_HPP
