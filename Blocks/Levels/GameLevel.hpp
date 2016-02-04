#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/GameInfo.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class GameLevel : public CoreLevel {
    public:
        // Constructor and destructor
        GameLevel(string, ResourceManager*, RenderWindow*);
        virtual ~GameLevel() {};
    private:
        // GameLevel functions
        void update();
        void restart();
        void processButtonEvents();
        // GameLevel variables
        Button *resetButton;
        Button *quitButton;
        GameInfo *gameInfo;
        string buttonEventName;
        unsigned int numMoves;
};

#endif // GAMELEVEL_HPP
