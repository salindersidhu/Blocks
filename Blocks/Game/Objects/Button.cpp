#include "Button.hpp"

Button::Button(string title, int size, Font font, Texture normalTexture,
	Texture hoverTexture) {
	// Configure the Sprites
	buttonNormalTexture = normalTexture;
	buttonHoverTexture = hoverTexture;
	buttonNormalSprite.setTexture(buttonNormalTexture);
	buttonHoverSprite.setTexture(buttonHoverTexture);
	// Configure the Text
	textFont = font;
	buttonText.setFont(textFont);
	buttonText.setString(title);
	buttonText.setCharacterSize((unsigned int)size);
	// Set remaining instance variables
	isMouseOverVar = false;
	isPlayHoverSoundVar = true;
	isClickedVar = false;
	isSelectedVar = false;
}

void Button::setSounds(SoundBuffer hover, SoundBuffer click) {
	// Set the hover and click Sounds
	hoverBuffer = hover;
	clickBuffer = click;
	clickSound.setBuffer(clickBuffer);
	hoverSound.setBuffer(hoverBuffer);
}

void Button::setColours(Color normal, Color hover) {
	// Set the normal and hover colours
	normalColour = normal;
	hoverColour = hover;
	// Set buttonText color to normal
	buttonText.setColor(normal);
}

void Button::setPosition(float x, float y) {
	// Set the position of the button sprites and button text
	buttonNormalSprite.setPosition(x, y);
	buttonHoverSprite.setPosition(x, y);
	// Configure the text to the new position
	FloatRect dims = buttonNormalSprite.getGlobalBounds();
	centerText(&buttonText, x, y, x + dims.width, y + dims.height);
}

void Button::onMouseLeftClick(Vector2i mousePosition) {
	// Play click sound effect if left button clicked
	if (isMouseOverVar && !isSelectedVar) {
		clickSound.play();
		isSelectedVar = true;
	}
}

void Button::onMouseMove(Vector2i mousePosition) {
	// Set isMouseOver to true if mouse is hovering over the Button
	isMouseOverVar = isHovering(mousePosition.x, mousePosition.y);
	// Play hover sound effect only once if button is hovered
	if (isMouseOverVar) {
		if (isPlayHoverSoundVar) {
			hoverSound.play();
			isPlayHoverSoundVar = false;
		}
	} else {
		// Reset isPlayHoverSound to true if mouse isn't hovering over button
		isPlayHoverSoundVar = true;
	}
}

void Button::update() {
	if (isSelectedVar &&
		clickSound.getStatus() == SoundSource::Status::Stopped) {
		isClickedVar = true;
		isSelectedVar = false;
	}
}

void Button::draw(RenderWindow *window) {
	if (isMouseOverVar) {
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

bool Button::isClicked() {
	// If the button is clicked return true and set isClicked to false
	if (isClickedVar) {
		isClickedVar = false;
		return true;
	}
	return false;
}

bool Button::isHovering(int mouseX, int mouseY) {
	// Obtain the positions dimensions of the Button's Sprite
	FloatRect dims = buttonNormalSprite.getGlobalBounds();
	Vector2f pos = buttonNormalSprite.getPosition();
	// Return if mouse is hovering over the Button's Sprite
	bool widthHover(mouseX >= pos.x && mouseX <= pos.x + dims.width);
	bool heightHover(mouseY >= pos.y && mouseY <= pos.y + dims.height);
	return widthHover && heightHover;
}
