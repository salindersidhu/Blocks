#include "Block.hpp"

Block::Block(Texture texture, float x, float y, bool _isVertical) {
    // Configure the Block's Sprite
    blockTexture = texture;
    blockSprite.setTexture(blockTexture);
    blockSprite.setPosition(x, y);
    // Set remaining instance variables
    isVertical = _isVertical;
    isFlagged = false;
    isSelected = false;
}

Sprite Block::getSprite() {
    return blockSprite;
}

float Block::getX() {
    return blockSprite.getPosition().x;
}

float Block::getY() {
    return blockSprite.getPosition().y;
}

float Block::getWidth() {
    return blockSprite.getGlobalBounds().width;
}

float Block::getHeight() {
    return blockSprite.getGlobalBounds().height;
}

void Block::setX(float x) {

    blockSprite.setPosition(x, getY());
}

void Block::setY(float y) {
    blockSprite.setPosition(getX(), y);
}

void Block::select() {
    isSelected = true;
}

void Block::unselect() {
    isSelected = false;
}

void Block::flag() {
    isFlagged = true;
}

bool Block::getSelected() {
    return isSelected;
}

bool Block::getFlagged() {
    return isFlagged;
}

bool Block::getVertical() {
    return isVertical;
}
