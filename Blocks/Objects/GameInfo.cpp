#include "GameInfo.hpp"

GameInfo::GameInfo(float _winWidth, float y, unsigned int textSize, Color textColor, Font font) {
    // Configure the MinuteClock
    clock = MinuteClock();
    // Configure the MinuteClock text
    textFont = font;
    clockText.setFont(textFont);
    clockText.setCharacterSize(textSize);
    clockText.setColor(textColor);
    clockText.setString("Time: 00:00:00    Moves: 0");
    // Set remaining instance variables
    winWidth = _winWidth;
    numMoves = 0;
    posY = y;
}

void GameInfo::update() {
    // Update the clock
    clock.tick();
    // Update the game info's drawing position
    centerText(winWidth, posY);
    // Set the text for the game info
    clockText.setString("Time: " + clock.getTime() + "    Moves: " + to_string(numMoves));
}

void GameInfo::draw(RenderWindow *window) {
    // Draw the game info
    window->draw(clockText);
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
    rect = clockText.getLocalBounds();
    clockText.setOrigin((rect.left + rect.width) / 2, 0);
    clockText.setPosition(winWidth / 2, y);
}
