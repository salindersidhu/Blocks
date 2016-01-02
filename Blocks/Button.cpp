#include "Button.hpp"

Button::Button(string text, string fontName, string normalTexture, string hoverTexture, sf::Color normalColour, sf::Color hoverColour, unsigned int fontSize, float width, float height, float x, float y) {
    // Initialize button attributes
    buttonText = text;
    buttonFontName = fontName;
    buttonNormalTexture = normalTexture;
    buttonHoverTexture = hoverTexture;
    buttonNormalColour = normalColour;
    buttonHoverColour = hoverColour;
    // Create new sprite ID names for the button normal and hover textures
    buttonNormalSprite = "S_N_" + buttonText;
    buttonHoverSprite = "S_H_" + buttonText;
    buttonFontSize = fontSize;
    buttonWidth = width;
    buttonHeight = height;
    buttonX = x;
    buttonY = y;
    isMouseOver = false;
}

bool Button::isHovering(int x, int y) {
	isMouseOver = (x >= buttonX && x <= buttonX + buttonWidth) && (y >= buttonY && y <= buttonY + buttonHeight);
	return isMouseOver;
}

bool Button::isSelected(string text, int x, int y) {
	return (isHovering(x, y) && buttonText == text);
}

void Button::set(DrawManager &drawMan) {
	if (isMouseOver) {
		drawMan.createSprite(buttonHoverSprite, buttonHoverTexture, buttonX, buttonY);
		drawMan.createText(buttonText, buttonFontName, buttonFontSize, buttonHoverColour, buttonText, buttonX, buttonY);
	} else {
		drawMan.createSprite(buttonNormalSprite, buttonNormalTexture, buttonX, buttonY);
		drawMan.createText(buttonText, buttonFontName, buttonFontSize, buttonNormalColour, buttonText, buttonX, buttonY);
	}
	drawMan.setTextCentered(buttonText, buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);
}

void Button::draw(DrawManager &drawMan) {
	if (isMouseOver) {
		drawMan.drawSprite(buttonHoverSprite);
	} else {
		drawMan.drawSprite(buttonNormalSprite);
	}
	drawMan.drawText(buttonText);
}
