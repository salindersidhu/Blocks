#include "CoreLevel.hpp"

CoreLevel::CoreLevel(String _title) {
    // Create basic colour objects
    black = Color(0, 0, 0);
    white = Color(255, 255, 255);
    red = Color(255, 51, 82);
    // Set the remaining variables
    title = _title;
    isFinished = false;
    isTransition = false;
    isStarted = false;
}

void CoreLevel::update() {
    // Call parent update function
    LevelObject::update();
    // Execute events only once per LevelObject
    if (!isStarted) {
        // Ensure FadeTrans is the last object in the list to draw
        objects.push_back(fadeEffect);
        // Start the background music only once
        bgMusic->start();
        isStarted = true;
    }
    // Stop the bgMusic if level is transitoning
    if (isTransition) {
        bgMusic->stop();
    }
}

void CoreLevel::setTransition() {
    fadeEffect->start();
    isTransition = true;
}

void CoreLevel::setBackgroundMusic(SoundBuffer musicBuffer, float loopTime,
    bool isLoop) {
    // Delete and null the bgMusic pointer if one already exists
    if (bgMusic) {
        bgMusic->stop(); // Safely stop the music prior to deleting
        delete bgMusic;
        bgMusic = NULL;
    }
    // Create a new BGMusic object pointer
    bgMusic = new BGMusic(musicBuffer, loopTime, isLoop);
    // Add the GameObject pointers to the object's container
    objects.push_back(bgMusic);
}

void CoreLevel::setBackgroundAndFont(Texture background, Font font) {
    Vector2u dims = background.getSize();
    // Create a new HUD object pointer
    displayHUD = new HUD(title, (float)dims.x, 15, 60, white, font,
		background);
    // Create a new FadeTrans object
    fadeEffect = new FadeEffect(7, dims.x, dims.y, black);
    // Add the GameObject pointers to the object's container
    objects.push_back(displayHUD);
}
