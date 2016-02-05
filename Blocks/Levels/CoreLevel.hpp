#ifndef CORELEVEL_HPP
#define CORELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/BGMusic.hpp"
#include "../Objects/FadeEffect.hpp"
#include "../Engine/LevelObject.hpp"
using namespace sf;
using namespace std;

class CoreLevel : public LevelObject {
    public:
        // Constructor and destructor
        CoreLevel(String);
        virtual ~CoreLevel() {};
        // CoreLevel functions
        virtual void update();
        void setTransition();
        void setBackgroundMusic(SoundBuffer, float);
        void setBackgroundAndFont(Texture, Font);
    protected:
        // CoreLevel variables
        string title;
        HUD *displayHUD;
        BGMusic *bgMusic;
        FadeEffect *fadeEffect;
        Color red;
        Color white;
        Color black;
        bool isTransition;  // Is the LevelObject in transition
        bool isStarted;     // Is the LevelObject started
};

#endif // CORELEVEL_HPP
