#include "HUD.hpp"

HUD::HUD(string t, float w, float y, int s, Color col, Font font, Texture tX) {
    // Configure the Sprites
    bgTexture = tX;
    bgSprite.setTexture(bgTexture);
	bgSprite.setPosition(0, 0);
    // Configure the Text
    textFont = font;
    titleText.setFont(textFont);
    titleText.setString(t);
    titleText.setCharacterSize((unsigned int)s);
    titleText.setColor(col);
    centerText(w, y);
}

void HUD::draw(RenderWindow *window) {
    // Draw the main background
    window->draw(bgSprite);
    // Draw the title of the level
    window->draw(titleText);
}

void HUD::centerText(float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = titleText.getLocalBounds();
    titleText.setOrigin((rect.left + rect.width) / 2, 0);
    titleText.setPosition(winWidth / 2, y);
}
