#include "TextAsset.hpp"

TextAsset::TextAsset(string _name, Font _font) {
    name = _name;
    text.setFont(_font);
}

Text TextAsset::getText() {
    return text;
}

void TextAsset::setSize(unsigned int size) {
    text.setCharacterSize(size);
}

void TextAsset::setPosition(float x, float y) {
    text.setPosition(x, y);
}

void TextAsset::setValue(string value) {
    text.setString(value);
}

void TextAsset::setColour(Color colour) {
    text.setColor(colour);
}

void TextAsset::setCentered(float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = text.getLocalBounds();
    text.setOrigin((rect.left + rect.width) / 2, 0);
    text.setPosition(winWidth / 2, y);
}

void TextAsset::setCentered(float sX, float sY, float eX, float eY) {
    FloatRect rect;
    // Center the text in the rectangular area
    rect = text.getLocalBounds();
    text.setOrigin((rect.left + rect.width) / 2, (rect.top + rect.height) / 2);
    text.setPosition(sX + ((eX - sX) / 2), (sY - 5) + ((eY - sY) / 2));
}

void TextAsset::draw(RenderWindow *window) {
    window->draw(text);
}
