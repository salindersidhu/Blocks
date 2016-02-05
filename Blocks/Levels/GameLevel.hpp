#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/GameInfo.hpp"
#include "../Objects/GameGrid.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class GameLevel : public CoreLevel {
    public:
        // Constructor and destructor
        GameLevel(string title) : CoreLevel(title) {};
        virtual ~GameLevel() {};
        // GameLevel functions
        void setGameGrid(GameGrid*);
    private:
        // GameLevel functions
        void init();
        void update();
        void restart();
        void processButtonEvents();
        // GameLevel variables
        Button *resetButton;
        Button *quitButton;
        GameInfo *gameInfo;
        GameGrid *gameGrid;
        string buttonEventName;
        unsigned int numMoves = 0;
};

#endif // GAMELEVEL_HPP
