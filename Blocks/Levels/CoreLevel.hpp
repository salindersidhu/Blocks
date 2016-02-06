#ifndef CORELEVEL_HPP
#define CORELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/BGMusic.hpp"
#include "../Engine/SaveObject.hpp"
#include "../Objects/FadeEffect.hpp"
#include "../Engine/LevelObject.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class CoreLevel : public LevelObject {
    public:
        // Constructor and destructor
        CoreLevel(String, ResourceManager*, RenderWindow*);
        virtual ~CoreLevel() {};
        // CoreLevel functions
        virtual void transitionEventHandler() {};
        virtual void transitionTriggerEvents() {};
        void setTransitionTriggerEvent(string);
        void setBackgroundMusic(SoundBuffer, float, bool);
        void setHUD(Texture, Font);
        void update();
        void reset();
    protected:
        // CoreLevel protected variables
        Color red;
        Color white;
        Color black;
        string title;
        HUD *displayHUD;
        BGMusic *bgMusic;
        FadeEffect *fadeEffect;
        string transitionEventName;
    private:
        // CoreLevel private variables
        void defaultVarValues();
        // CoreLevel private variables
        bool isStarted;
        bool isTransition;
};

#endif // CORELEVEL_HPP
