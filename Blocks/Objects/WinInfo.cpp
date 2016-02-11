#include "WinInfo.hpp"

WinInfo::WinInfo(SaveObject *_saveObj, Font font, Color col, float winWidth) {
    // Set the instance variables
    textColor = col;
    textFont = font;
    saveObj = _saveObj;
    isUpdateOnce = true;
    // Configure the congrats text
    congratsText.setFont(textFont);
    congratsText.setString("CONGRATULATIONS!");
    congratsText.setCharacterSize(37);
    congratsText.setColor(col);
    centerText(&congratsText, winWidth, 280);
    // Configure the level complete text
    levelCompleteText.setFont(textFont);
    levelCompleteText.setString("LEVEL COMPLETE!");
    levelCompleteText.setCharacterSize(37);
    levelCompleteText.setColor(col);
    centerText(&levelCompleteText, winWidth, 320);
    // Configure the total time text
    totalTimeText.setFont(textFont);
    totalTimeText.setCharacterSize(25);
    totalTimeText.setColor(col);
    totalTimeText.setPosition(140, 400);
    // Configure the total moves text
    totalMovesText.setFont(textFont);
    totalMovesText.setCharacterSize(25);
    totalMovesText.setColor(col);
    totalMovesText.setPosition(140, 425);
}

void WinInfo::reset() {
    // Reset the update variable
    isUpdateOnce = true;
}

void WinInfo::update() {
    // Update the total time and total move strings only once
    if (isUpdateOnce) {
        totalTimeText.setString("Total Time:        " +
            saveObj->getData("TIME"));
        totalMovesText.setString("Total Moves:      " +
            saveObj->getData("MOVES"));
        isUpdateOnce = false;
    }
}

void WinInfo::draw(RenderWindow *window) {
    // Draw all of the text objects
    window->draw(congratsText);
    window->draw(levelCompleteText);
    window->draw(totalTimeText);
    window->draw(totalMovesText);
}
