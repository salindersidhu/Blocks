#include "Button.hpp"

Button::Button(string text, unsigned int textSize, float x, float y, Color _colNormal, Color _colHover, TextAsset *_buttonText, SpriteAsset *_spriteNormal, SpriteAsset *_spriteHover) {
    // Set instance variables based on constructor arguments
    buttonText = _buttonText;
    spriteNormal = _spriteNormal;
    spriteHover = _spriteHover;
    colNormal = _colNormal;
    colHover = _colHover;
    // Configure the SpriteAssets
    spriteNormal->getSprite().setPosition(x, y);
    spriteHover->getSprite().setPosition(x, y);
    // Configure the TextAsset
    FloatRect dims = spriteNormal->getSprite().getGlobalBounds();
    buttonText->getText().setString(text);
    buttonText->getText().setCharacterSize(textSize);
    buttonText->getText().setColor(colNormal);
    buttonText->setCentered(x, y, x + dims.width, y + dims.height);
    // Set remaining instance variables
    isMouseOver = false;
}

void Button::onMouseClick(Vector2i mousePosition) {
    if (isMouseOver) {
    }
}

void Button::onMouseMove(Vector2i mousePosition) {
    isMouseOver = isHovering(mousePosition.x, mousePosition.y);
}

void Button::draw(RenderWindow *window) {
    if (isMouseOver) {
        // Draw the hover Sprite
        window->draw(spriteNormal->getSprite());
        // Set text with hover colour
        buttonText->getText().setColor(colHover);
    } else {
        // Draw the normal Sprite
        window->draw(spriteHover->getSprite());
        // Set text with normal colour
        buttonText->getText().setColor(colNormal);
    }
    // Draw the Text
    window->draw(buttonText->getText());
}

bool Button::isHovering(int mX, int mY) {
    // Obtain the positions dimensions of the Button's Sprite
    FloatRect dims = spriteNormal->getSprite().getGlobalBounds();
    Vector2f pos = spriteNormal->getSprite().getPosition();
    // Return if mouse is hovering over the Button's Sprite
    return (mX >= pos.x && mX <= pos.x + dims.width) && (mY >= pos.y && mY <= pos.y + dims.height);
}
