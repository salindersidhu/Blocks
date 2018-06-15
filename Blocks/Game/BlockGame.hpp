#ifndef BLOCKGAME_HPP
#define BLOCKGAME_HPP

#include <string>
#include <exception>
#include "../Engine/Game.hpp"
#include "Levels/WinLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Levels/MenuLevel.hpp"
#include "Objects/GameGrid.hpp"

#include "Assets/bh21.c"
#include "Assets/bh22.c"
#include "Assets/bh23.c"
#include "Assets/bh24.c"
#include "Assets/bh25.c"
#include "Assets/bh26.c"
#include "Assets/bh31.c"
#include "Assets/bh32.c"
#include "Assets/button_normal.c"
#include "Assets/button_select.c"
#include "Assets/bv21.c"
#include "Assets/bv22.c"
#include "Assets/bv23.c"
#include "Assets/bv24.c"
#include "Assets/bv25.c"
#include "Assets/bv26.c"
#include "Assets/bv31.c"
#include "Assets/bv32.c"
#include "Assets/CooperBlackStd.c"
#include "Assets/icon.c"
#include "Assets/levelbg.c"
#include "Assets/menubg.c"
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
