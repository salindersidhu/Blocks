#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
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
        void processTransition();
        // GameLevel variables
        Button *resetButton;
        Button *quitButton;
        GameGrid *gameGrid;
        string transitionEventName;
};

#endif // GAMELEVEL_HPP
