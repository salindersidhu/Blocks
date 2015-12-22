/*
FILENAME:		Grid.cpp
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Implementation for Grid.h.
UPDATE DATE:	10/27/2013
*/

#include "Grid.h"

/* BLOCK class */

Block::Block(ORIENTATION _orientation, int _size, int _x, int _y, SPRITE _image, bool _isRedBlock) {
	orientation = _orientation;
	size = _size;
	x = GAME_INIT_X + (_x * GAME_POS_INCR);
	y = GAME_INIT_Y + (_y * GAME_POS_INCR);
	blockSelected = false;
	image = _image;
	isRedBlock = _isRedBlock;
}

/* Grid class */

Grid::Grid() {
	blockFree = true;
}

void Grid::configure(DrawManager *dm) {

	// Cycle through the container
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		// Configure the block image positions prior to drawing
		dm->configSpritePosition(blockContainer[i].image, (float) blockContainer[i].x, (float) blockContainer[i].y);
	}
}

void Grid::draw(DrawManager *dm) {

	// Cycle through the container
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		// Draw the block to the screen
		dm->drawSprite(blockContainer[i].image);
	}
}

void Grid::addBlock(Block block) {

	// Add block to container
	blockContainer.push_back(block);
}

bool Grid::isHovering(int x, int y, int a, int b, int c, int d) {

	return ((x >= a && x <= a + c) && (y >= b && y <= b + d));
}

bool Grid::isBounded(int blockPosition, int blockSize, int upperBound, int lowerBound) {

	return ((blockPosition >= upperBound) && (blockPosition + (blockSize * GAME_POS_INCR) <= lowerBound));
}

bool Grid::isVictory() {

	// Cycle through all the blocks
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		Block block = blockContainer[i];
		// Check if the red block is aligned in the victory position
		if (block.isRedBlock && block.x == BLOCK_VICTORY_POS) {
			return true;
		}
	}
	return false;
}

void Grid::selectBlock(int mouseX, int mouseY) {

	blockMoved = false;
	// Cycle through all the blocks
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		int blockX = blockContainer[i].x;
		int blockY = blockContainer[i].y;
		// Physical size (pixel length) of block
		int blockSize = -49 + (90 * blockContainer[i].size);
		ORIENTATION blockOrientation = blockContainer[i].orientation;
		// Determine if mouse is over a block
		if ((blockOrientation == ORIENTATION::V && isHovering(mouseX, mouseY, blockX, blockY, 58, blockSize)) || (blockOrientation == ORIENTATION::H && isHovering(mouseX, mouseY, blockX, blockY, blockSize, 57))) {
			blockContainer[i].blockSelected = true;
			// Set the current values of x and y used for the alignment system
			previousX = blockX - GAME_INIT_X;
			previousY = blockY - GAME_INIT_Y;
			// Set the distances for sliding movement
			distanceX = (int) fabs((float) blockContainer[i].x - mouseX); // Type casting required to solve issue with ambigous fabs call
			distanceY = (int) fabs((float) blockContainer[i].y - mouseY);
		}
	}
}

void Grid::alignBlock(int initalPosition, int &positionValue, int previousPosition) {

	// Get modulus for distance to cover and current position of positionValue
	int currentPosition = positionValue - initalPosition;
	int mod = currentPosition % GAME_POS_INCR;
	// Find and set the closest positional alignment
	if (mod != 0) {
		if ((positionValue - mod) % GAME_POS_INCR != 0) {
			positionValue -= mod;
		} else {
			positionValue += mod;
		}
		// Align to the correct direction
		if ((currentPosition > previousPosition) && (mod <= currentPosition)) {
			positionValue += GAME_POS_INCR;
		}
	}
}

void Grid::releaseBlock(int &numberOfMoves) {

	blockFree = true;
	// Cycle through all the blocks
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		// If a block is selected then unselect it
		if (blockContainer[i].blockSelected) {
			blockContainer[i].blockSelected = false;
			distanceX = 0;
			distanceY = 0;
			// Align the block correctly to the grid
			if (blockContainer[i].orientation == ORIENTATION::H) {
				alignBlock(GAME_INIT_X, blockContainer[i].x, previousX);
			} else {
				alignBlock(GAME_INIT_Y, blockContainer[i].y, previousY);
			}
		}
	}
	// If block moved GAME_POS_INCRease number of moves
	if (blockMoved) {
		numberOfMoves++;
		blockMoved = false;
	}
}

void Grid::moveBlock(int mouseX, int mouseY) {

	// Cycle though all the blocks
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		// Find the currently selected block
		if (blockContainer[i].blockSelected && blockFree) {
			int size = blockContainer[i].size;
			// Move the block with the mouse in the correct orientation
			if (blockContainer[i].orientation == V) {
				int currentY = mouseY - distanceY;
				if (isBounded(currentY, size, GAME_INIT_Y, 637) && notCollision(blockContainer[i], 0, currentY)) {
					blockContainer[i].y = currentY;
					blockMoved = true;
				}
			}
			else
			{
				int currentX = mouseX - distanceX;
				if (isBounded(currentX, size, GAME_INIT_X, 535) && notCollision(blockContainer[i], currentX, 0)) {
					blockContainer[i].x = currentX;
					blockMoved = true;
				}
			}
		}
	}
}

bool Grid::notCollision(Block block, int currentX, int currentY)
{
	for (unsigned int i = 0; i < blockContainer.size(); i++) {
		// Default collision boundry values
		int startX = blockContainer[i].x;
		int endX = blockContainer[i].x;
		int startY = blockContainer[i].y;
		int endY = blockContainer[i].y;
		int checkX = currentX; // Default for left movement
		int checkY = currentY; // Default for moving up
		if (blockContainer[i].orientation == V) {
			endY += ((blockContainer[i].size - 1) * GAME_POS_INCR);
		} else {
			endX += ((blockContainer[i].size - 1) * GAME_POS_INCR);
		}
		// Checking for horizontal blocks
		if (blockContainer[i].x != block.x && currentX > 0) {
			endX += GAME_POS_INCR;
			// Calculate for right (-->) movement
			if ((previousX + GAME_INIT_X) - currentX < 0) {
				checkX += block.size * GAME_POS_INCR;
			}
			// Check if collision will occur
			if ((checkX >= startX && checkX <= endX) && (block.y >= startY && block.y <= endY)) {
				blockFree = false;
				return false;
			}
		} else if (blockContainer[i].y != block.y && currentY > 0) { // Checking for verticle blocks
			endY += GAME_POS_INCR;
			// Calculate for down movement
			if ((previousY + GAME_INIT_Y) - currentY < 0) {
				checkY += block.size * GAME_POS_INCR;
			}
			// Check if collision will occur
			if ((checkY >= startY && checkY <= endY) && (block.x >= startX && block.x <= endX)) {
				blockFree = false;
				return false;
			}
		}
	}
	return true; // No collision detected
}

void Grid::clear() {

	// Clear the block container
	blockContainer.clear();
}