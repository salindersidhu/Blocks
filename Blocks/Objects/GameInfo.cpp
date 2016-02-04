#include "GameInfo.hpp"

GameInfo::GameInfo(float w, float y, int size, Color col, Font font) {
    // Configure the MinuteClock
    clock = MinuteClock();
    // Configure the MinuteClock text
    textFont = font;
    infoText.setFont(textFont);
    infoText.setCharacterSize((unsigned int)size);
    infoText.setColor(col);
    infoText.setString("Time: 00:00:00    Moves: 0");
    // Set remaining instance variables
    winWidth = w;
    numMoves = 0;
    posY = y;
}

void GameInfo::update() {
    // Update the clock
    clock.tick();
    // Update the game info's drawing position
    centerText(winWidth, posY);
    // Set the text for the game info
    string i("Time: " + clock.getTime() + "    Moves: " + to_string(numMoves));
    infoText.setString(i);
}

void GameInfo::draw(RenderWindow *window) {
    // Draw the game info
    window->draw(infoText);
}

void GameInfo::setNumMoves(unsigned int _numMoves) {
    numMoves = _numMoves;
}

MinuteClock* GameInfo::getClock() {
	return &clock;
}

void GameInfo::centerText(float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = infoText.getLocalBounds();
    infoText.setOrigin((rect.left + rect.width) / 2, 0);
    infoText.setPosition(winWidth / 2, y);
}
