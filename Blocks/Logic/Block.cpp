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
    return textureName;
}

float Block::getX() {
    return x;
}

float Block::getY() {
    return y;
}

float Block::getWidth() {
    return width;
}

float Block::getHeight() {
    return height;
}

float Block::getSize() {
    return size;
}

void Block::setX(float _x) {
    x = _x;
}

void Block::setY(float _y) {
    y = _y;
}

void Block::setDefaultX(float x) {
    defaultX = x;
}

void Block::setDefaultY(float y) {
    defaultY = y;
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

void Block::resetPosition() {
    x = defaultX;
    y = defaultY;
}

bool Block::getIsSelected() {
    return isSelected;
}

bool Block::getIsFlagged() {
    return isFlagged;
}

bool Block::getIsVertical() {
    return isVertical;
}
