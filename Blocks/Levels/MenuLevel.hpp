#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
using namespace sf;
using namespace std;

class MenuLevel : public CoreLevel {
    public:
        // Constructor and destructor
        MenuLevel(String, Font, Texture, Texture, Texture, SoundBuffer, SoundBuffer, SoundBuffer, RenderWindow*);
        virtual ~MenuLevel() {};
    private:
        // MenuLevel functions
        void update();
        void processButtonEvents();
        // MenuLevel variables
        Button *startButton;
        Button *quitButton;
        string buttonEventName;
};

#endif // MENULEVEL_HPP
