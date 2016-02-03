#ifndef CORELEVEL_HPP
#define CORELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/BGMusic.hpp"
#include "../Objects/FadeOut.hpp"
#include "../Engine/LevelObject.hpp"
using namespace sf;
using namespace std;

class CoreLevel : public LevelObject {
    public:
        // Constructor and destructor
        CoreLevel(String, Font, Texture, SoundBuffer, float, RenderWindow*);
        virtual ~CoreLevel() {};
        // CoreLevel functions
        virtual void update();
        void setTransition();
    protected:
        // CoreLevel variables
        HUD *displayHUD;
        BGMusic *bgMusic;
        RenderWindow *window;
        FadeOut *fadeOutEffect;
        Color red;
        Color white;
        Color black;
        bool isTransition;              // Is the LevelObject in transition
        bool isStarted;                 // Is the LevelObject started
};

#endif // CORELEVEL_HPP
