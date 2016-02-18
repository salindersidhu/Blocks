#include "Grid.hpp"

Grid::Grid(float _x, float _y, float _width, float _height, float _completeX,
	float _completeY, float _tileGap) {
	// Set instance variables based on constructor arguments
	x = _x;
	y = _y;
	width = _width;
	height = _height;
	completeX = _completeX;
	completeY = _completeY;
	tileGap = _tileGap;
}

void Grid::addBlock(Block block) {
	// Adjust the position of the block
	block.setX(x + (block.getX() * tileGap));
	block.setY(y + (block.getY() * tileGap));
	block.setDefaultX(block.getX());
	block.setDefaultY(block.getY());
	// Add Block to the Grid
	blocks.push_back(block);
}

void Grid::selectBlock(float mouseX, float mouseY) {
	isBlockMovedVar = false;
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		float blockX = blocks[i].getX();
		float blockY = blocks[i].getY();
		float blockWidth = blocks[i].getWidth();
		float blockHeight = blocks[i].getHeight();
		// Determine if mouse is over the Block
		if (isHovering(mouseX, mouseY, blockX, blockY, blockWidth,
			blockHeight)) {
			blocks[i].select();
			// Set the current values of x and y used for positional alignment
			prevX = blockX - x;
			prevY = blockY - y;
			// Set the distances for sliding movement
			distX = fabs(blockX - mouseX);
			distY = fabs(blockY - mouseY);
		}
	}
}

void Grid::releaseBlock(unsigned int &numMoves) {
	isBlockFreeVar = true;
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		float blockX = blocks[i].getX();
		float blockY = blocks[i].getY();
		// If the Block is selected then unselect it
		if (blocks[i].isSelected()) {
			blocks[i].unselect();
			distX = distY = 0;
			// Align the Block correctly to the Grid
			if (!blocks[i].isVertical()) {
				blocks[i].setX(align(x, blockX, prevX));
			} else {
				blocks[i].setY(align(y, blockY, prevY));
			}
		}
	}
	// If the Block moved then increment the number of moves by 1
	if (isBlockMovedVar) {
		numMoves++;
		isBlockMovedVar = false;
	}
}

void Grid::moveBlock(float mouseX, float mouseY) {
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Find the currently selected Block
		if (blocks[i].isSelected() && isBlockFreeVar) {
			float gridEndX = width + x;
			float gridEndY = height + y;
			float size = blocks[i].getSize() * tileGap;
			float currentX = mouseX - distX;
			float currentY = mouseY - distY;
			// Move the Block with the mouse in the correct orientation
			if (blocks[i].isVertical()) {
				if (isBounded(currentY, size, y, gridEndY) &&
					isNotCol(blocks[i], 0, currentY)) {
					blocks[i].setY(currentY);
					isBlockMovedVar = true;
				}
			} else {
				if (isBounded(currentX, size, x, gridEndX) &&
					isNotCol(blocks[i], currentX, 0)) {
					blocks[i].setX(currentX);
					isBlockMovedVar = true;
				}
			}
		}
	}
}

void Grid::reset() {
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Reset the position of the Block
		blocks[i].resetPosition();
	}
}

vector<Block> Grid::getBlocks() {
	// Return all the Blocks on the Grid
	return blocks;
}

bool Grid::isComplete() {
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		float blockX = blocks[i].getX();
		float blockY = blocks[i].getY();
		// Check if the flagged Block is aligned with Grid complete position
		if (blocks[i].isFlagged() && (blockX == completeX) &&
			(blockY == completeY)) {
			return true;
		}
	}
	return false;
}

float Grid::align(float initPos, float pos, float prevPos) {
	// Get modulus for distance to cover and current position
	float currPos = pos - initPos;
	float mod = fmod(currPos, tileGap);
	// Find and set the closest positional alignment
	if (mod != 0) {
		if (fmod((pos - mod), tileGap) != 0) {
			pos -= mod;
		} else {
			pos += mod;
		}
		// Align to the correct direction
		if ((currPos > prevPos) && (mod <= currPos)) {
			pos += tileGap;
		}
	}
	return pos;
}

bool Grid::isHovering(float x, float y, float a, float b, float c, float d) {
	return (x >= a && x <= a + c) && (y >= b && y <= b + d);
}

bool Grid::isNotCol(Block block, float _x, float _y) {
	// Iterate through all the Blocks on the Grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Default collision boundry values
		float startX = blocks[i].getX();
		float endX = blocks[i].getX();
		float startY = blocks[i].getY();
		float endY = blocks[i].getY();
		float currentX = _x;   // Default for moving left
		float currentY = _y;   // Default for moving up
		if (blocks[i].isVertical()) {
			endY += (blocks[i].getSize() - 1) * tileGap;
		} else {
			endX += (blocks[i].getSize() - 1) * tileGap;
		}
		// Check for horizontal and vertical Blocks
		if (blocks[i].getX() != block.getX() && _x > 0) {
			endX += tileGap;
			// Calculate for moving right
			if ((prevX + x) - _x < 0) {
				currentX += block.getSize() * tileGap;
			}
			// Check if collision will occur
			if (currentX >= startX && currentX <= endX) {
				if (block.getY() >= startY && block.getY() <= endY) {
					isBlockFreeVar = false;
					return false;
				}
			}
		} else if (blocks[i].getY() != block.getY() && _y > 0) {
			endY += tileGap;
			// Calculate for moving down
			if ((prevY + y) - _y < 0) {
				currentY += block.getSize() * tileGap;
			}
			// Check if collision will occur
			if (currentY >= startY && currentY <= endY) {
				if (block.getX() >= startX && block.getX() <= endX) {
					isBlockFreeVar = false;
					return false;
				}
			}
		}
	}
	return true; // No collision detected
}

bool Grid::isBounded(float posVal, float length, float uBound, float lBound) {
	return (posVal >= uBound) && (posVal + length <= lBound);
}
