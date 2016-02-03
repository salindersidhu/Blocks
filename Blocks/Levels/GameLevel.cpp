#include "GameLevel.hpp"

GameLevel::GameLevel(String title, Font font, Texture bg, Texture normal, Texture hover, SoundBuffer hoverBuffer, SoundBuffer clickBuffer, SoundBuffer bgMusic, RenderWindow *window) : CoreLevel(title, font, bg, bgMusic, 19.5, window) {
    // Create new Button object pointers
    resetButton = new Button("Reset", 30, 111, 107, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    quitButton = new Button("Quit", 30, 321, 107, white, red, font, normal, hover, hoverBuffer, clickBuffer);
    // Create a new GameClock pointer
    gameInfo = new GameInfo(600, 640, 30, white, font);
    // Add the GameObject pointers to the object's container
    objects.push_back(resetButton);
    objects.push_back(quitButton);
    objects.push_back(gameInfo);
}

void GameLevel::update() {
    // Call parent update function
    CoreLevel::update();
}
