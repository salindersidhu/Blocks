#include "Block.hpp"

Block::Block(string _spriteName, tuple<float, float> _position, int _size, int _orientation) {
    spriteName = _spriteName;
    position = _position;
    dimensions = make_tuple(0, 0);
    size = _size;
    orientation = _orientation;
}

void Block::setPosition(int x, int y) {
    get<0>(position) = x;
    get<1>(position) = y
}

void Block::setSelected(bool _isSelected) {
    isSelected = _isSelected;
}

void Block::flag() {
    isFlagged = true;
}

bool Block::getIsSelected() {
    return isSelected;
}

bool Block::getIsFlagged() {
    return isFlagged;
}

bool Block::getIsVertical() {
    return orientation == 0;
}

string Block::getSpriteName() {
    return getSpriteName;
}

float Block::getSize() {
    return getSize();
}

tuple<float, float> getPosition() {
    return position;
}

tuple<float, float> getDimensions() {
    return dimensions
}
