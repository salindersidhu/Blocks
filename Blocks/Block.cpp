#include "Block.hpp"

/* Block class */
Block::Block(string orient, string spriteName, int size, int x, int y, int gridX, int gridY, int posIncr, bool isVictory) {
    blockOrient = orient;
    blockSpriteName = spriteName;
    blockSize = size;
    blockX = gridX + (x * posIncr);
    blockY = gridY + (y * posIncr);
    isVictoryBlock = isVictory;
    isBlockSelected = false;
    // Set the width and height of the block
    if (blockOrient == "V") {
        blockWidth = 58;
        blockLength = -49 + (90 * blockSize);
    } else {
        blockWidth = -49 + (90 * blockSize);
        blockLength = 57;
    }
}

string Block::getSpriteName() {
    return blockSpriteName;
}

int Block::getWidth() {
    return blockWidth;
}

int Block::getLength() {
    return blockLength;
}

int Block::getX() {
    return blockX;
}

int Block::getY() {
    return blockY;
}

int Block::getSize() {
    return blockSize;
}

bool Block::isVictory() {
    return isVictoryBlock;
}

bool Block::isSelected() {
    return isBlockSelected;
}

bool Block::isVertical() {
    return blockOrient == "V";
}

void Block::setSelected(bool isSelected) {
    isBlockSelected = isSelected;
}

void Block::setX(int x) {
    blockX = x;
}

void Block::setY(int y) {
    blockY = y;
}
