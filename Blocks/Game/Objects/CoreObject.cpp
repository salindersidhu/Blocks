#include "CoreObject.hpp"

void CoreObject::centerText(Text *text, float startX, float startY,
    float endX, float endY) {
	FloatRect rect;
	// Center the text in the rectangular area
	rect = text->getLocalBounds();
	text->setOrigin((rect.left + rect.width) / 2, (rect.top +
		rect.height) / 2);
	text->setPosition(startX + ((endX - startX) / 2), (startY - 5) +
        ((endY - startY) / 2));
}

void CoreObject::centerText(Text *text, float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = text->getLocalBounds();
    text->setOrigin((rect.left + rect.width) / 2, 0);
    text->setPosition(winWidth / 2, y);
}
