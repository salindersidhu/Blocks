#ifndef GAMELEVEL_HPP
#define GAMELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/GameGrid.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class GameLevel : public CoreLevel {
public:
    // Constructor and destructor
    GameLevel(string, ResourceManager*, RenderWindow*, SaveObject*);
    virtual ~GameLevel() {};
    // GameLevel functions
    void setGameGrid(GameGrid*);
private:
    // GameLevel functions
    void transitionEventHandler();
    void transitionTriggerEvents();
    // GameLevel variables
    Button *resetButton;    // Button pointer for reset button
    Button *quitButton;     // Button pointer for quit button
    GameGrid *gameGrid;     // GameGrid pointer
};

#endif // GAMELEVEL_HPP
