#include "CoreLevel.hpp"

CoreLevel::CoreLevel(String _title, ResourceManager *resMan,
    RenderWindow *window) : LevelObject(resMan, window) {
    // Create basic colour objects
    black = Color(0, 0, 0);
    white = Color(255, 255, 255);
    red = Color(255, 51, 82);
    // Set the remaining variables
    title = _title;
    defaultVarValues();
}

void CoreLevel::reset() {
    // Call parent reset function
    LevelObject::reset();
    // Reset the core level variables
    defaultVarValues();
}

void CoreLevel::defaultVarValues() {
    // Set the default values for the instance variables
    isStarted = false;
    isFinished = false;
    isTransition = false;
    transitionEventName = "";
}

void CoreLevel::update() {
    // Call parent update function
    LevelObject::update();
    // Execute events only once per LevelObject
    if (!isStarted) {
        // Ensure FadeTrans is the last object in the list to draw
        if (find(objects.begin(), objects.end(), fadeEffect) ==
			objects.end()) {
            // Add fadeEffect pointer if it doesn't exist in the objects
            objects.push_back(fadeEffect);
        }
        // Start the background music only once
        bgMusic->start();
        isStarted = true;
    }
    // Process transition events
    if (isTransition) {
        // Stop the bgMusic if level is transitoning
        bgMusic->stop();
    } else {
        // Execute events that trigger a level transition
        transitionTriggerEvents();
    }
    // Process level transition
    if (fadeEffect->isDone() && isTransition) {
        isTransition = false;   // No longer transitioning
        transitionEventHandler();
    }
}

void CoreLevel::setTransitionTriggerEvent(string _transitionEventName) {
    transitionEventName = _transitionEventName;
    fadeEffect->start();
    isTransition = true;
}

void CoreLevel::setBackgroundMusic(SoundBuffer musicBuffer, float loopTime,
    bool isLoop) {
    // Create a new BGMusic object pointer
    bgMusic = new BGMusic(musicBuffer, loopTime, isLoop);
    // Add the GameObject pointers to the object's container
    objects.push_back(bgMusic);
}

void CoreLevel::setHUD(Texture background, Font font) {
    // Create a new HUD object pointer
    displayHUD = new HUD(title, (float)window->getSize().x, 15, 60, white,
		font, background);
    // Create a new FadeTrans object
    fadeEffect = new FadeEffect(7, window->getSize().x, window->getSize().y,
		black);
    // Add the GameObject pointers to the object's container
    objects.push_back(displayHUD);
}
