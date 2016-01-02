#include "Block.hpp"

/* Block class */
Block::Block(string spriteName, string textureName, string orient, int size, int x, int y, bool isVictory) {
    blockOrient = orient;
	blockTextureName = textureName;
	blockSpriteName = spriteName;
    blockSize = size;
	blockX = x;
    blockY = y;
    isVictoryBlock = isVictory;
    isBlockSelected = false;
}

void Block::gridSet(int x, int y, int posIncr) {
	// Update the block's position
	blockX = x + (blockX * posIncr);
	blockY = y + (blockY * posIncr);
	// Set the width and height of the block
	if (blockOrient == "V") {
		blockWidth = 58;
		blockLength = -49 + (90 * blockSize);
	}
	else {
		blockWidth = -49 + (90 * blockSize);
		blockLength = 57;
	}
}

string Block::getSpriteName() {
    return blockSpriteName;
}

string Block::getTextureName() {
	return blockTextureName;
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
