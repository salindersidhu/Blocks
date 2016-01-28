#ifndef MENULEVEL_HPP
#define MENULEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/Button.hpp"
#include "../Objects/FadeTrans.hpp"
#include "../Engine/LevelObject.hpp"
using namespace sf;
using namespace std;

class MenuLevel : public LevelObject {
    public:
        // Constructor and destructor
        MenuLevel(String, Font, Texture, Texture, Texture, SoundBuffer, SoundBuffer);
        virtual ~MenuLevel() {};
    private:
        // MenuLevel variables
        Button *startButton;
        Button *loadButton;
        Button *aboutButton;
        Button *quitButton;
        HUD *displayHUD;
        FadeTrans *fadeEffect;
};

#endif // MENULEVEL_HPP
