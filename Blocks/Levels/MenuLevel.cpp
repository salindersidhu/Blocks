#include "MenuLevel.hpp"

MenuLevel::MenuLevel(String title, Font font, Texture bg, Texture normal, Texture hover) {
    // Create new Button objects
    Color white = Color(255, 255, 255);
    Color red = Color(255, 51, 82);
    startButton = new Button("Start", 30, 220, 250, white, red, font, normal, hover);
    loadButton = new Button("Load", 30, 220, 330, white, red, font, normal, hover);
    aboutButton = new Button("About", 30, 220, 410, white, red, font, normal, hover);
    quitButton = new Button("Quit", 30, 220, 490, white, red, font, normal, hover);
    // Create a new HUD object
    displayHUD = new HUD(title, 600, 15, 60, white, font, bg);
    // Add the Button objects to the GameObjects container
    objects.push_back(displayHUD);
    objects.push_back(startButton);
    objects.push_back(loadButton);
    objects.push_back(aboutButton);
    objects.push_back(quitButton);
    isComplete = false;
}
