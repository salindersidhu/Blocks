#include "WinLevel.hpp"

WinLevel::WinLevel(string title, ResourceManager *resMan,
    RenderWindow *window, SaveObject *saveObj) :
    CoreLevel(title, resMan, window, saveObj) {
    // Obtain the game's resources for this level
    Font font = resMan->getFont("FN_COPPER");
    Texture background = resMan->getTexture("TX_BACKGROUND_MENU");
    Texture buttonHover = resMan->getTexture("TX_BUTTON_HOVER");
    Texture buttonNormal = resMan->getTexture("TX_BUTTON_NORMAL");
    // Create and set new Button objects
    nextButton = new Button("Next", 30, font, buttonNormal, buttonHover);
    quitButton = new Button("Quit", 30, font, buttonNormal, buttonHover);
    nextButton->setPosition(110, 555);
    quitButton->setPosition(340, 555);
    nextButton->setColours(white, red);
    quitButton->setColours(white, red);
    // Create and set the Win info object
    winInfo = new WinInfo(saveObj, font, white, (float)window->getSize().x);
    // Set the background texture, HUD font
    setHUD(background, font);
    // Add the GameObject pointers to the object's container
    objects.push_back(nextButton);
    objects.push_back(quitButton);
    objects.push_back(winInfo);
}

void WinLevel::transitionTriggerEvents() {
    // Set fade out transition if any button was clicked
    if (nextButton->isClicked()) {
        setTransitionTriggerEvent("BUTTON_NEXT");
    }
    if (quitButton->isClicked()) {
        setTransitionTriggerEvent("BUTTON_QUIT");
    }
}

void WinLevel::transitionEventHandler() {
    // Process transition events
    if (transitionEventName == "BUTTON_NEXT") {
        // Next button clicked, go to next level
        isFinishedVar = true;
    } else {
        // Quit button clicked, terminate the game
        window->close();
    }
}
