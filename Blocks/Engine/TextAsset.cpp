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
        // Throw EngineException
        throw EngineException("Error: Getting Text");
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
        // Throw EngineException
        throw EngineException("Error: centering Text");
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
        // Throw EngineException
        throw EngineException("Error: Centering Text");
    }
}

void TextAsset::draw(RenderWindow *window) {
    // Check if Text exists
    if (text.getFont()) {
        window->draw(text);
    } else {
        // Throw EngineException
        throw EngineException("Error: Drawing Text");
    }
}
