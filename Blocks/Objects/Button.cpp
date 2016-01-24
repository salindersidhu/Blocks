#include "Button.hpp"

Button::Button(string text, unsigned int textSize, float x, float y, Color normal, Color hover, Font font, Texture normalTexture, Texture hoverTexture) {
	// Set instance variables based on constructor arguments
	normalColour = normal;
	hoverColour = hover;
    // Configure the Sprites
	buttonNormalTexture = normalTexture;
	buttonHoverTexture = hoverTexture;
    buttonNormalSprite.setTexture(buttonNormalTexture);
    buttonHoverSprite.setTexture(buttonHoverTexture);
	buttonNormalSprite.setPosition(x, y);
	buttonHoverSprite.setPosition(x, y);
    // Configure the Text
    FloatRect dims = buttonNormalSprite.getGlobalBounds();
	textFont = font;
	buttonText.setFont(textFont);
    buttonText.setString(text);
    buttonText.setCharacterSize(textSize);
    buttonText.setColor(normalColour);
    centerText(x, y, x + dims.width, y + dims.height);
    // Set remaining instance variables
    isMouseOver = false;
}

void Button::onMouseClick(Vector2i mousePosition) {
    if (isMouseOver) {
		isClicked = true;
    }
}

void Button::onMouseMove(Vector2i mousePosition) {
	// Set isMouseOver to true if mouse is hovering over the Button
    isMouseOver = isHovering(mousePosition.x, mousePosition.y);
	isClicked = false;
}

void Button::draw(RenderWindow *window) {
    if (isMouseOver) {
        // Draw the hover Sprite
		window->draw(buttonHoverSprite);
        // Set text with hover colour
        buttonText.setColor(hoverColour);
    } else {
        // Draw the normal Sprite
		window->draw(buttonNormalSprite);
        // Set text with normal colour
        buttonText.setColor(normalColour);
    }
    // Draw the Text
    window->draw(buttonText);
}

bool Button::isHovering(int mX, int mY) {
    // Obtain the positions dimensions of the Button's Sprite
    FloatRect dims = buttonNormalSprite.getGlobalBounds();
    Vector2f pos = buttonNormalSprite.getPosition();
    // Return if mouse is hovering over the Button's Sprite
    return (mX >= pos.x && mX <= pos.x + dims.width) && (mY >= pos.y && mY <= pos.y + dims.height);
}

void Button::centerText(float sX, float sY, float eX, float eY) {
	FloatRect rct;
	// Center the text in the rectangular area
	rct = buttonText.getLocalBounds();
	buttonText.setOrigin((rct.left + rct.width) / 2, (rct.top + rct.height) / 2);
	buttonText.setPosition(sX + ((eX - sX) / 2), (sY - 5) + ((eY - sY) / 2));
}
