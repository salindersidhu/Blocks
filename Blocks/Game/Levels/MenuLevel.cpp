#include "MenuLevel.hpp"

MenuLevel::MenuLevel(string title, ResourceManager *resMan,
    RenderWindow *window, SaveObject *saveObj) :
    CoreLevel(title, resMan, window, saveObj) {
    // Obtain the game's resources for this level
    Font font = resMan->getFont("FN_COPPER");
    SoundBuffer bgMusic = resMan->getSound("MS_BACKGROUND");
    SoundBuffer hoverSound = resMan->getSound("SN_BUTTON_HOVER");
    SoundBuffer clickSound = resMan->getSound("SN_BUTTON_CLICK");
    Texture background = resMan->getTexture("TX_BACKGROUND_MENU");
    Texture buttonHover = resMan->getTexture("TX_BUTTON_HOVER");
    Texture buttonNormal = resMan->getTexture("TX_BUTTON_NORMAL");
    // Create and configure new Button objects
    startButton = new Button("Start", 30, font, buttonNormal, buttonHover);
    quitButton = new Button("Quit", 30, font, buttonNormal, buttonHover);
    startButton->setPosition(220, 330);
    quitButton->setPosition(220, 410);
    startButton->setSounds(hoverSound, clickSound);
    quitButton->setSounds(hoverSound, clickSound);
    startButton->setColours(white, red);
    quitButton->setColours(white, red);
    // Set the background texture, HUD font and background music
    setHUD(background, font);
    setBackgroundMusic(bgMusic, 19.5, true);
    // Add the GameObject pointers to the object's container
    objects.push_back(startButton);
    objects.push_back(quitButton);
}

void MenuLevel::transitionTriggerEvents() {
    // Set fade out transition if any button was clicked
    if (startButton->isClicked()) {
        setTransitionTriggerEvent("BUTTON_START");
    }
    if (quitButton->isClicked()) {
        setTransitionTriggerEvent("BUTTON_QUIT");
    }
}

void MenuLevel::transitionEventHandler() {
    // Process transition events
    if (transitionEventName == "BUTTON_START") {
        // Start button clicked, go to next level
        isFinishedVar = true;
    } else {
        // Quit button clicked, terminate the game
        window->close();
    }
}
