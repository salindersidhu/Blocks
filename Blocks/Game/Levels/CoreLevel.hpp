#ifndef CORELEVEL_HPP
#define CORELEVEL_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Objects/HUD.hpp"
#include "../Objects/BGMusic.hpp"
#include "../Objects/FadeEffect.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/SaveObject.hpp"
#include "../../Engine/LevelObject.hpp"
#include "../../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class CoreLevel : public LevelObject {
public:
    // Constructor and destructor
    CoreLevel(String, ResourceManager*, RenderWindow*, SaveObject*);
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
    Color red;                      // Red Colour object
    Color white;                    // White Colour object
    Color black;                    // Black Colour object
    string title;                   // Title of the current LevelObject
    HUD *displayHUD;                // HUD pointer
    BGMusic *bgMusic;               // BGMusic pointer
    FadeEffect *fadeEffect;         // FadeEffect pointer
    string transitionEventName;     // Name of the transition event
private:
    // CoreLevel private variables
    void defaultVarValues();
    // CoreLevel private variables
    bool isStartedVar;              // If the level has started
    bool isTransitionVar;           // If the level is transitioning
};

#endif // CORELEVEL_HPP
