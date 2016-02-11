#ifndef BLOCKGAME_HPP
#define BLOCKGAME_HPP

#include <string>
#include <exception>
#include "../Engine/Game.hpp"
#include "Levels/WinLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Levels/MenuLevel.hpp"
#include "Objects/GameGrid.hpp"
using namespace sf;
using namespace std;

class BlockGame {
    public:
        // Constructor and destructor
        BlockGame();
        virtual ~BlockGame() {};
    private:
        // BlockGame private functions
        void cleanup();
        void setWindowIcon();
        void addGameLevel(string, GameGrid*);
        void setupLevels(string, int);
        void showLoadingScreen();
        void loadGameResources();
        // BlockGame private variables
        Game *game;                 // Pointer for the Engine's Game object
        SaveObject *saveObj;        // SaveObject pointer to save data
        RenderWindow *window;       // RenderWindow pointer
        ResourceManager *resMan;    // ResourceManager pointer
};

#endif // BLOCKGAME_HPP
