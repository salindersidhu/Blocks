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
    // Add the GameObject pointers to the object's container
    objects.push_back(displayHUD);
    objects.push_back(bgMusic);
    // Set the remaining variables
    window = _window;
    isComplete = false;
    isTransition = false;
}
