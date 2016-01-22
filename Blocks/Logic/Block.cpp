#include "Block.hpp"

Block::Block(string _spriteName, float _x, float _y, float _width, float _height, int _orientation) {
    // Set instance variables based on constructor arguments
    spriteName = _spriteName;
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    orientation = _orientation;
    // Set remaining instance variables
    isFlagged = false;
    isSelected = false;
}

void Block::setX(float _x) {
	x = _x;
}

void Block::setY(float _y) {
    y = _y;
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

bool Block::getSelected() {
    return isSelected;
}

bool Block::getFlagged() {
    return isFlagged;
}

bool Block::getVertical() {
    return orientation == 0;
}

string Block::getSpriteName() {
    return spriteName;
}
