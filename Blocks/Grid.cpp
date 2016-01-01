#include "Grid.hpp"

/* Grid class */
Grid::Grid(int x, int y, int endX, int endY, int incr, int victoryPos) {
    gridX = x;
    gridY  = y;
    gridEndX = endX;
    gridEndY = endY;
    posIncr = incr;
    blockVictoryPos = victoryPos;
	isBlockFree = true;
}

void Grid::set(DrawManager *dm) {
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Set the block image positions prior to drawing
		dm->setSprite(blocks[i].getSpriteName(), (float)blocks[i].getX(), (float)blocks[i].getY());
	}
}

void Grid::draw(DrawManager *dm) {
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Draw the block to the screen
		dm->drawSprite(blocks[i].getSpriteName());
	}
}

void Grid::addBlock(Block block) {
	// Add block to the grid
	blocks.push_back(block);
}

bool Grid::isHovering(int x, int y, int a, int b, int c, int d) {
	return (x >= a && x <= a + c) && (y >= b && y <= b + d);
}

bool Grid::isBounded(int position, int size, int upBound, int lowBound) {
	return (position >= upBound) && (position + (size * posIncr) <= lowBound);
}

bool Grid::isVictory() {
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
        int x = blocks[i].getX();
		// Check if the victory block is aligned in the victory position
		if (blocks[i].isVictory() && x == blockVictoryPos) {
			return true;
		}
	}
	return false;
}

void Grid::selectBlock(int mX, int mY) {
	isBlockMoved = false;
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		int bX = blocks[i].getX();
		int bY = blocks[i].getY();
		int width = blocks[i].getWidth();
		int height = blocks[i].getLength();
		// Determine if mouse is over a block
		if ((blocks[i].isVertical() && isHovering(mX, mY, bX, bY, width, height)) || (!blocks[i].isVertical() && isHovering(mX, mY, bX, bY, width, height))) {
			blocks[i].setSelected(true);
			// Set the current values of x and y used for the alignment system
			previousX = bX - gridX;
			previousY = bY - gridY;
			// Set the distances for sliding movement
			distanceX = (int)fabs((float)bX - mX);
			distanceY = (int)fabs((float)bY - mY);
		}
	}
}

void Grid::alignBlock(int initPos, int &posVal, int prevPos) {
	// Get modulus for distance to cover and current position
	int currPos = posVal - initPos;
	int mod = currPos % posIncr;
	// Find and set the closest positional alignment
	if (mod) {
		if ((posVal - mod) % posIncr) {
			posVal -= mod;
		} else {
			posVal += mod;
		}
		// Align to the correct direction
		if ((currPos > prevPos) && (mod <= currPos)) {
			posVal += posIncr;
		}
	}
}

void Grid::releaseBlock(int &numMoves) {
	isBlockFree = true;
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
        int bX = blocks[i].getX();
        int bY = blocks[i].getY();
		// If a block is selected then unselect it
		if (blocks[i].isSelected()) {
			blocks[i].setSelected(false);
			distanceX = distanceY = 0;
			// Align the block correctly to the grid
			if (!blocks[i].isVertical()) {
				alignBlock(gridX, bX, previousX);
			} else {
				alignBlock(gridY, bY, previousY);
			}
		}
	}
	// If block moved then increase the number of moves by 1
	if (isBlockMoved) {
		numMoves++;
		isBlockMoved = false;
	}
}

void Grid::moveBlock(int mX, int mY) {
	// Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Find the currently selected block
		if (blocks[i].isSelected() && isBlockFree) {
			int size = blocks[i].getSize();
            int currY = mY - distanceY;
            int currX = mX - distanceX;
			// Move the block with the mouse in the correct orientation
			if (blocks[i].isVertical()) {
				if (isBounded(currY, size, gridY, gridEndY) && isNotCollision(blocks[i], 0, currY)) {
					blocks[i].setY(currY);
					isBlockMoved = true;
				}
			} else {
				if (isBounded(currX, size, gridX, gridEndX) && isNotCollision(blocks[i], currX, 0)) {
					blocks[i].setX(currX);
					isBlockMoved = true;
				}
			}
		}
	}
}

bool Grid::isNotCollision(Block block, int x, int y) {
    // Cycle through all the blocks on the grid
	for (unsigned int i = 0; i < blocks.size(); i++) {
		// Default collision boundry values
		int startX = blocks[i].getX();
		int endX = blocks[i].getX();
		int startY = blocks[i].getY();
		int endY = blocks[i].getY();
		int checkX = x; // Default for left movement
		int checkY = y; // Default for moving up
		if (blocks[i].isVertical()) {
			endY += (blocks[i].getSize() - 1) * posIncr;
		} else {
			endX += (blocks[i].getSize() - 1) * posIncr;
		}
		// Checking for horizontal blocks
		if (blocks[i].getX() != block.getX() && x > 0) {
			endX += posIncr;
			// Calculate for moving right
			if ((previousX + gridX) - x < 0) {
				checkX += block.getSize() * posIncr;
			}
			// Check if collision will occur
			if ((checkX >= startX && checkX <= endX) && (block.getY() >= startY && block.getY() <= endY)) {
				isBlockFree = false;
				return isBlockFree;
			}
		} else if (blocks[i].getY() != block.getY() && y > 0) { // Checking for verticle blocks
			endY += posIncr;
			// Calculate for down movement
			if ((previousY + gridY) - y < 0) {
				checkY += block.getSize() * posIncr;
			}
			// Check if collision will occur
			if ((checkY >= startY && checkY <= endY) && (block.getX() >= startX && block.getX() <= endX)) {
				isBlockFree = false;
				return false;
			}
		}
	}
	return true; // No collision detected
}

void Grid::clear() {
	// Clear the block container
	blocks.clear();
}
