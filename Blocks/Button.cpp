#include "Button.hpp"

Button::Button(string textName, string text, unsigned int textSize, string sprite, string spriteSelected, sf::Color normalColour, sf::Color hoverColour, float width, float height, float x, float y) {
	// Set button variables
	buttonText = text;
	buttonTextName = textName;
	buttonTextSize = textSize;
	spriteName = sprite;
	spriteSelectedName = spriteSelected;
	buttonNormalColour = normalColour;
	buttonHoverColour = hoverColour;
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

bool Button::isSelected(string spriteSelected, int x, int y) {
	return (isHovering(x, y) && spriteSelectedName == spriteSelected);
}

void Button::set(DrawManager *dm) {
	if (isMouseOver) {
		dm->setSprite(spriteSelectedName, buttonX, buttonY);
		dm->setText(buttonTextName, buttonTextSize, buttonHoverColour, buttonText, buttonX, buttonY);
	} else {
		dm->setSprite(spriteName, buttonX, buttonY);
		dm->setText(buttonTextName, buttonTextSize, buttonNormalColour, buttonText, buttonX, buttonY);
	}
	dm->centerTextRectangle(buttonTextName, buttonX, buttonY, buttonX + buttonWidth, buttonY + buttonHeight);
}

void Button::draw(DrawManager *dm) {
	if (isMouseOver) {
		dm->drawSprite(spriteSelectedName);
	} else {
		dm->drawSprite(spriteName);
	}
	dm->drawText(buttonText);
}
