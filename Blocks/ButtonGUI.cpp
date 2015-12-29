#include "ButtonGUI.hpp"

ButtonGUI::ButtonGUI(string text, TEXTS font, float width, float height, float positionX, float positionY, SPRITE normal, SPRITE selected) {
	buttonText = text;
	buttonFont = font;
	buttonWidth = width;
	buttonHeight = height;
	buttonPositionX = positionX;
	buttonPositionY = positionY;
	imageNormal = normal;
	imageSelected = selected;
	mouseHovering = false;
}

bool ButtonGUI::hovering(int mouseX, int mouseY) {
	mouseHovering = ((mouseX >= buttonPositionX && mouseX <= buttonPositionX + buttonWidth) && (mouseY >= buttonPositionY && mouseY <= buttonPositionY + buttonHeight));
	return mouseHovering;
}

bool ButtonGUI::selected(int mouseX, int mouseY, SPRITE indicateSelected) {
	return (hovering(mouseX, mouseY) && imageSelected == indicateSelected);
}

void ButtonGUI::configure(DrawManager *dm) {
	if (mouseHovering) {
		dm->configSpritePosition(imageSelected, buttonPositionX, buttonPositionY);
		dm->configTextCenterRectangle(buttonFont, 30, LIGHT_RED, buttonText, buttonPositionX, buttonPositionY, buttonPositionX + buttonWidth, buttonPositionY + buttonHeight);
	} else {
		dm->configSpritePosition(imageNormal, buttonPositionX, buttonPositionY);
		dm->configTextCenterRectangle(buttonFont, 30, WHITE, buttonText, buttonPositionX, buttonPositionY, buttonPositionX + buttonWidth, buttonPositionY + buttonHeight);
	}
}

void ButtonGUI::draw(DrawManager *dm) {
	if (mouseHovering) {
		dm->drawSprite(imageSelected); 
	} else {
		dm->drawSprite(imageNormal);
	}
	dm->drawText(buttonFont);
}