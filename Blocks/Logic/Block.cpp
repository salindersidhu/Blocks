#include "Block.hpp"

Block::Block(string _textureName, float _size, float _x, float _y,
    float _width, float _height, bool _isVertical) {
    // Set instance variables
    textureName = _textureName;
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    size = _size;
    isVertical = _isVertical;
    isFlagged = false;
    isSelected = false;
}

string Block::getTextureName() {
    // Return the Block's associated texture name
    return textureName;
}

float Block::getX() {
    // Return the Block's x position
    return x;
}

float Block::getY() {
    // Return the Block's y position
    return y;
}

float Block::getWidth() {
    // Return the Block's width
    return width;
}

float Block::getHeight() {
    // Return the Block's height
    return height;
}

float Block::getSize() {
    // Return the Block's orientation based size (length or width)
    return size;
}

void Block::setX(float _x) {
    // Set the Block's x position
    x = _x;
}

void Block::setY(float _y) {
    // Set the Block's y position
    y = _y;
}

void Block::setDefaultX(float x) {
    // Set the Block's default starting x position
    defaultX = x;
}

void Block::setDefaultY(float y) {
    // Set the Block's default starting y position
    defaultY = y;
}

void Block::select() {
    // Select the Block
    isSelected = true;
}

void Block::unselect() {
    // Unselect the Block
    isSelected = false;
}

void Block::flag() {
    // Flag the Block
    isFlagged = true;
}

void Block::resetPosition() {
    // Set the current position to the default starting position
    x = defaultX;
    y = defaultY;
}

bool Block::getIsSelected() {
    // Return true if the Block is selected, false otherwise
    return isSelected;
}

bool Block::getIsFlagged() {
    // Return true if the Block is flagged, false otherwise
    return isFlagged;
}

bool Block::getIsVertical() {
    // Return true if the Block is vertical, false otherwise
    return isVertical;
}
