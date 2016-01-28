#include "MenuLevel.hpp"

MenuLevel::MenuLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer) {
    // Create colour objects
    Color white = Color(255, 255, 255);
    Color red = Color(255, 51, 82);
    Color black = Color(0, 0, 0);
    // Create new Button object pointers
    startButton = new Button("Start", 30, 220, 250, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    loadButton = new Button("Load", 30, 220, 330, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    aboutButton = new Button("About", 30, 220, 410, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 220, 490, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Create a new HUD object pointer
    displayHUD = new HUD(title, 600, 15, 60, white, font, bg);
    // Create a new FadeTrans object pointer
    Vector2u dims = bg.getSize();
    fadeEffect = new FadeTrans(4, dims.x, dims.y, black);
    // Add the Button object ointers to the GameObject pointers container
    objects.push_back(displayHUD);
    objects.push_back(startButton);
    objects.push_back(loadButton);
    objects.push_back(aboutButton);
    objects.push_back(quitButton);
    objects.push_back(fadeEffect);
    // Set level completed to false
    isComplete = false;
}
