#include "SpriteAsset.hpp"

SpriteAsset::SpriteAsset(string _name, Texture _texture) {
    name = _name;
    sprite.setTexture(_texture);
}

Sprite SpriteAsset::getSprite() {
    return sprite;
}

void SpriteAsset::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void SpriteAsset::draw(RenderWindow *window) {
    window->draw(sprite);
}
