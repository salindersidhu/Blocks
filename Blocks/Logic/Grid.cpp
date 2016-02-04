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
    isBlockMoved = false;
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        float bX = blocks[i].getX();
        float bY = blocks[i].getY();
        float bW = blocks[i].getWidth();
        float bH = blocks[i].getHeight();
        // Determine if mouse is over the Block
        if (isHovering(mouseX, mouseY, bX, bY, bW, bH)) {
            blocks[i].select();
            // Set the current values of x and y used for positional alignment
            prevX = bX - x;
            prevY = bY - y;
            // Set the distances for sliding movement
            distX = fabs(bX - mouseX);
            distY = fabs(bY - mouseY);
        }
    }
}

void Grid::releaseBlock() {
    isBlockFree = true;
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        float bX = blocks[i].getX();
        float bY = blocks[i].getY();
        // If the Block is selected then unselect it
        if (blocks[i].getSelected()) {
            blocks[i].unselect();
            distX = distY = 0;
            // Align the Block correctly to the Grid
            if (!blocks[i].getVertical()) {
                blocks[i].setX(align(x, bX, prevX));
            } else {
                blocks[i].setY(align(y, bY, prevY));
            }
        }
    }
    // If the Block moved then increment the number of moves by 1
    /*if (isBlockMoved) {
        numMoves++;
        isBlockMoved = false;
    }*/
}

void Grid::moveBlock(float mouseX, float mouseY) {
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        // Find the currently selected Block
        if (blocks[i].getSelected() && isBlockFree) {
            float eX = width + x;
            float eY = height + y;
            float bW = blocks[i].getWidth();
            float bH = blocks[i].getHeight();
            float cX = mouseX - distX;
            float cY = mouseY - distY;
            // Move the Block with the mouse in the correct orientation
            if (blocks[i].getVertical()) {
                if (isBounded(cY, bH, y, eY) && isNotCol(blocks[i], 0, cY)) {
                    blocks[i].setY(cY);
                    isBlockMoved = true;
                }
            } else {
                if (isBounded(cX, bW, x, eX) && isNotCol(blocks[i], cX, 0)) {
                    blocks[i].setX(cX);
                    isBlockMoved = true;
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
    return blocks;
}

bool Grid::isComplete() {
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        float x = blocks[i].getX();
        float y = blocks[i].getY();
        // Check if the flagged Block is aligned with Grid complete position
        if (blocks[i].getFlagged() && (x == completeX) && (y == completeY)) {
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
        float sX = blocks[i].getX();
        float eX = blocks[i].getX();
        float sY = blocks[i].getY();
        float eY = blocks[i].getY();
        float cX = _x;   // Default for moving left
        float cY = _y;   // Default for moving up
        if (blocks[i].getVertical()) {
            eY += blocks[i].getHeight();
        } else {
            eX += blocks[i].getWidth();
        }
        // Check for horizontal and vertical Blocks
        if (blocks[i].getX() != block.getX() && _x > 0) {
            eX += tileGap;
            // Calculate for moving right
            if ((prevX + x) - _x < 0) {
                cX += block.getWidth();
            }
            // Check if collision will occur
            if (cX >= sX && cX <= eX) {
                if (block.getY() >= sY && block.getY() <= eY) {
                    isBlockFree = false;
                    return false;
                }
            }
        } else if (blocks[i].getY() != block.getY() && _y > 0) {
            eY += tileGap;
            // Calculate for moving down
            if ((prevY + y) - _y < 0) {
                cY += block.getHeight();
            }
            // Check if collision will occur
            if (cY >= sY && cY <= eY) {
                if (block.getX() >= sX && block.getX() <= eY) {
                    isBlockFree = false;
                    return false;
                }
            }
        }
    }
    return true;    // No collision detected
}

bool Grid::isBounded(float posVal, float length, float uBound, float lBound) {
    return (posVal >= uBound) && (posVal + length <= lBound);
}
