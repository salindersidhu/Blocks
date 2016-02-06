#include "WinLevel.hpp"

WinLevel::WinLevel(string title, ResourceManager *resMan,
    RenderWindow *window) : CoreLevel(title, resMan, window) {
    // Obtain the game's resources for this level
    Font font = resMan->getFont("FN_COPPER");
    SoundBuffer bgMusic = resMan->getSound("SN_VICTORY");
    SoundBuffer hoverSound = resMan->getSound("SN_BUTTON_HOVER");
    SoundBuffer clickSound = resMan->getSound("SN_BUTTON_CLICK");
    Texture background = resMan->getTexture("TX_BACKGROUND_MENU");
    Texture buttonHover = resMan->getTexture("TX_BUTTON_HOVER");
    Texture buttonNormal = resMan->getTexture("TX_BUTTON_NORMAL");
    // Create and set new Button objects
    nextButton = new Button("Next", 30, font, buttonNormal, buttonHover);
    quitButton = new Button("Quit", 30, font, buttonNormal, buttonHover);
    nextButton->setPosition(110, 555);
    quitButton->setPosition(340, 555);
    nextButton->setSounds(hoverSound, clickSound);
    quitButton->setSounds(hoverSound, clickSound);
    nextButton->setColours(white, red);
    quitButton->setColours(white, red);
    // Create and set the Win info object
    winInfo = new WinInfo(font, white, (float)window->getSize().x);
    // Set the background texture, HUD font and background music
    setHUD(background, font);
    setBackgroundMusic(bgMusic, 0, false);
    // Add the GameObject pointers to the object's container
    objects.push_back(nextButton);
    objects.push_back(quitButton);
    objects.push_back(winInfo);
}

void WinLevel::transitionTriggerEvents() {
    // Set fade out transition if any button was clicked
    if (nextButton->getIsClicked()) {
        setTransitionTriggerEvent("BUTTON_NEXT");
    }
    if (quitButton->getIsClicked()) {
        setTransitionTriggerEvent("BUTTON_QUIT");
    }
}

void WinLevel::transitionEventHandler() {
    // Process transition events
    if (transitionEventName == "BUTTON_NEXT") {
        // Next button clicked, go to next level
        isFinished = true;
    } else {
        // Quit button clicked, terminate the game
        window->close();
    }
}
