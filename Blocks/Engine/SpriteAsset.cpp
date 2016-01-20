#include "SpriteAsset.hpp"

SpriteAsset::SpriteAsset(string _name, Texture _texture) {
    name = _name;
    sprite.setTexture(_texture);
}

Sprite SpriteAsset::getSprite() {
    // Check if Sprite exists
    if (sprite.getTexture()) {
        return sprite;
    } else {
        // Throw EngineException
        throw EngineException("Error: Getting Sprite");
    }
}

void SpriteAsset::draw(RenderWindow *window) {
    // Check if Sprite exists
    if (sprite.getTexture()) {
        window->draw(sprite);
    } else {
        // Throw EngineException
        throw EngineException("Error: Drawing Sprite");
    }
}
