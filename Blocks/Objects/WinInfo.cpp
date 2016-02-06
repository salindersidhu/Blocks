#include "WinInfo.hpp"

WinInfo::WinInfo(Font font, Color col, float winWidth) {
    // Set the instance variables
    textColor = col;
    textFont = font;
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
}

void WinInfo::draw(RenderWindow *window) {
    // Draw all of the text objects
    window->draw(congratsText);
    window->draw(levelCompleteText);
}

void WinInfo::centerText(Text *text, float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = text->getLocalBounds();
    text->setOrigin((rect.left + rect.width) / 2, 0);
    text->setPosition(winWidth / 2, y);
}
