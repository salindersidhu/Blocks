#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreLevel.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/FadeTrans.hpp"
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
        void processGameStartEvent();
        // MenuLevel variables
        FadeTrans *fadeEffect;
        Button *startButton;
        Button *quitButton;
};

#endif // MENULEVEL_HPP
