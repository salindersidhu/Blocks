#include "CoreLevel.hpp"

CoreLevel::CoreLevel(String title, Font font, Texture bg, SoundBuffer _bgMusic, float loopTime, RenderWindow *_window) : LevelObject(){
    // Create basic colour objects
    black = Color(0, 0, 0);
    white = Color(255, 255, 255);
    red = Color(255, 51, 82);
    // Create a new HUD object pointer
    displayHUD = new HUD(title, 600, 15, 60, white, font, bg);
    // Create a new BGMusic object pointer
    bgMusic = new BGMusic(_bgMusic, loopTime);
    // Create a new FadeTrans object pointer
    Vector2u dims = bg.getSize();
    fadeOutEffect = new FadeOut(5, dims.x, dims.y, black);
    // Add the GameObject pointers to the object's container
    objects.push_back(displayHUD);
    objects.push_back(bgMusic);
    // Set the remaining variables
    window = _window;
    isComplete = false;
    isTransition = false;
    isStarted = false;
}

void CoreLevel::update() {
    // Call parent update function
    LevelObject::update();
    // Execute events only once per LevelObject
    if (!isStarted) {
        // Ensure FadeTrans is the last object in the list to draw
        objects.push_back(fadeOutEffect);
        // Start the background music only once
        bgMusic->start();
        isStarted = true;
    }
    // Stop the bgMusic if level is transitoning
    if (isTransition) {
        bgMusic->stop();
    }
}
