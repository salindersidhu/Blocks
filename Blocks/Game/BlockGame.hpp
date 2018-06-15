#ifndef BLOCKGAME_HPP
#define BLOCKGAME_HPP

#include <string>
#include <exception>
#include "../Engine/Game.hpp"
#include "Levels/WinLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Levels/MenuLevel.hpp"
#include "Objects/GameGrid.hpp"

#include "Assets/bh21.hpp"
#include "Assets/bh22.hpp"
#include "Assets/bh23.hpp"
#include "Assets/bh24.hpp"
#include "Assets/bh25.hpp"
#include "Assets/bh26.hpp"
#include "Assets/bh31.hpp"
#include "Assets/bh32.hpp"
#include "Assets/bv21.hpp"
#include "Assets/bv22.hpp"
#include "Assets/bv23.hpp"
#include "Assets/bv24.hpp"
#include "Assets/bv25.hpp"
#include "Assets/bv26.hpp"
#include "Assets/bv31.hpp"
#include "Assets/bv32.hpp"
#include "Assets/icon.hpp"
#include "Assets/menuBG.hpp"
#include "Assets/levelBG.hpp"
#include "Assets/btnHover.hpp"
#include "Assets/btnNormal.hpp"
#include "Assets/cooperBlackStd.hpp"
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
