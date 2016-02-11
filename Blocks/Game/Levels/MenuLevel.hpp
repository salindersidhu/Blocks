#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class MenuLevel : public CoreLevel {
    public:
        // Constructor and destructor
        MenuLevel(string, ResourceManager*, RenderWindow*, SaveObject*);
        virtual ~MenuLevel() {};
    private:
        // MenuLevel functions
        void transitionEventHandler();
        void transitionTriggerEvents();
        // MenuLevel variables
        Button *startButton;    // Button pointer for start button
        Button *quitButton;     // Button pointer for quit button
};

#endif // MENULEVEL_HPP
