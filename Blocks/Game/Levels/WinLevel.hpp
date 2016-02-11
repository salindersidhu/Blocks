#ifndef WINLEVEL_HPP
#define WINLEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/WinInfo.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class WinLevel : public CoreLevel {
    public:
        // Constructor and destructor
        WinLevel(string, ResourceManager*, RenderWindow*, SaveObject*);
        virtual ~WinLevel() {};
    private:
        // MenuLevel functions
        void transitionEventHandler();
        void transitionTriggerEvents();
        // MenuLevel variables
        Button *nextButton;     // Button pointer for next button
        Button *quitButton;     // Button pointer for quit button
        WinInfo *winInfo;       // WinInfo pointer object
};

#endif // WINLEVEL_HPP
