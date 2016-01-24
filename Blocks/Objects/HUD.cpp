#include "HUD.hpp"

HUD::HUD(string title, float winWidth, float y, unsigned int textSize, Color normal, Font font, Texture _bgTexture) {
    // Configure the Sprites
    bgTexture = _bgTexture;
    bgSprite.setTexture(bgTexture);
	bgSprite.setPosition(0, 0);
    // Configure the Text
    textFont = font;
    titleText.setFont(textFont);
    titleText.setString(title);
    titleText.setCharacterSize(textSize);
    titleText.setColor(normal);
    centerText(winWidth, y);
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
