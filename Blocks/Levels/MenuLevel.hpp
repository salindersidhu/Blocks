#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class MenuLevel : public CoreLevel {
    public:
        // Constructor and destructor
        MenuLevel(string title) : CoreLevel(title) {};
        virtual ~MenuLevel() {};
    private:
        // MenuLevel functions
        void init();
        void update();
        void processButtonEvents();
        // MenuLevel variables
        Button *startButton;
        Button *quitButton;
        string buttonEventName;
};

#endif // MENULEVEL_HPP
