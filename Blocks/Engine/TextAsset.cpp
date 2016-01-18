#include "TextAsset.hpp"

TextAsset::TextAsset(string _name, Font _font) {
    name = _name;
    text.setFont(_font);
}

Text TextAsset::getText() {
    // Check if Text exists
    if (text.getFont()) {
        return text;
    } else {
        // Throw AssetException
        throw AssetException("Cannot get Text");
    }
}

void TextAsset::setSize(unsigned int size) {
    // Check if Text exists
    if (text.getFont()) {
        text.setCharacterSize(size);
    } else {
        // Throw AssetException
        throw AssetException("Cannot set Text's size");
    }
}

void TextAsset::setPosition(float x, float y) {
    // Check if Text exists
    if (text.getFont()) {
        text.setPosition(x, y);
    } else {
        // Throw AssetException
        throw AssetException("Cannot set Text's position");
    }
}

void TextAsset::setValue(string value) {
    // Check if Text exists
    if (text.getFont()) {
        text.setString(value);
    } else {
        // Throw AssetException
        throw AssetException("Cannot set Text's value");
    }
}

void TextAsset::setColour(Color colour) {
    // Check if Text exists
    if (text.getFont()) {
        text.setColor(colour);
    } else {
        // Throw AssetException
        throw AssetException("Cannot set Text's colour");
    }
}

void TextAsset::setCentered(float winWidth, float y) {
    // Check if Text exists
    if (text.getFont()) {
        FloatRect rect;
        // Center the text horizontally
        rect = text.getLocalBounds();
        text.setOrigin((rect.left + rect.width) / 2, 0);
        text.setPosition(winWidth / 2, y);
    } else {
        // Throw AssetException
        throw AssetException("Cannot center Text");
    }
}

void TextAsset::setCentered(float sX, float sY, float eX, float eY) {
    // Check if Text exists
    if (text.getFont()) {
        FloatRect rct;
        // Center the text in the rectangular area
        rct = text.getLocalBounds();
        text.setOrigin((rct.left + rct.width) / 2, (rct.top + rct.height) / 2);
        text.setPosition(sX + ((eX - sX) / 2), (sY - 5) + ((eY - sY) / 2));
    } else {
        // Throw AssetException
        throw AssetException("Cannot center Text");
    }
}

void TextAsset::draw(RenderWindow *window) {
    // Check if Text exists
    if (text.getFont()) {
        window->draw(text);
    } else {
        // Throw AssetException
        throw AssetException("Cannot draw Text");
    }
}
