#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/BGMusic.hpp"
#include "../Objects/FadeTrans.hpp"
#include "../Engine/LevelObject.hpp"
using namespace sf;
using namespace std;

class MenuLevel : public LevelObject {
    public:
        // Constructor and destructor
        MenuLevel(String, Font, Texture, Texture, Texture, SoundBuffer, SoundBuffer, SoundBuffer, RenderWindow*);
        virtual ~MenuLevel() {};
    private:
        // MenuLevel functions
        void update();
        void processGameStartEvent();
        // MenuLevel variables
        Button *startButton;
        Button *quitButton;
        HUD *displayHUD;
        FadeTrans *fadeEffect;
        BGMusic *bgMusic;
        RenderWindow *window;
        bool isTransition;              // Is the LevelObject in transition
};

#endif // MENULEVEL_HPP
