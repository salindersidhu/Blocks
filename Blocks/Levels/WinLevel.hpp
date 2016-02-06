#ifndef WINLEVEL_HPP
#define WINLEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/WinInfo.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class WinLevel : public CoreLevel {
    public:
        // Constructor and destructor
        WinLevel(string, ResourceManager*, RenderWindow*);
        virtual ~WinLevel() {};
    private:
        // MenuLevel functions
        void transitionEventHandler();
        void transitionTriggerEvents();
        // MenuLevel variables
        Button *nextButton;
        Button *quitButton;
        WinInfo *winInfo;
};

#endif // WINLEVEL_HPP
