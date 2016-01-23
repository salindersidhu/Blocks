#include "Grid.hpp"

Grid::Grid(float _x, float _y, float _width, float _height, float _completeX, float _completeY, float _tileGap) {
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
    // Add Block to the Grid
    blocks.push_back(block);
}

void Grid::selectBlock(float mX, float mY) {
    isBlockMoved = false;
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        float bX = blocks[i].getX();
        float bY = blocks[i].getY();
        float bW = blocks[i].getWidth();
        float bH = blocks[i].getHeight();
        // Determine if mouse is over the Block
        if (isHovering(mX, mY, bX, bY, bW, bH)) {
            blocks[i].select();
            // Set the current values of x and y used for positional alignment
            prevX = bX - x;
            prevY = bY - y;
            // Set the distances for sliding movement
            distX = fabs(bX - mX);
            distY = fabs(bY - mY);
        }
    }
}

void Grid::releaseBlock(int &numMoves) {
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
    if (isBlockMoved) {
        numMoves++;
        isBlockMoved = false;
    }
}

void Grid::moveBlock(float mX, float mY) {
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        // Find the currently selected Block
        if (blocks[i].getSelected() && isBlockFree) {
            float endX = width + x;
            float endY = height + y;
            float bW = blocks[i].getWidth();
            float bH = blocks[i].getHeight();
            float currX = mX - distX;
            float currY = mY - distY;
            // Move the Block with the mouse in the correct orientation
            if (blocks[i].getVertical()) {
                if (isBounded(currY, bH, y, endY) && isNotCollision(blocks[i], 0, currY)) {
                    blocks[i].setY(currY);
                    isBlockMoved = true;
                }
            } else {
                if (isBounded(currX, bW, x, endX) && isNotCollision(blocks[i], currX, 0)) {
                    blocks[i].setX(currX);
                    isBlockMoved = true;
                }
            }
        }
    }
}

void Grid::clear() {
    // Remove all Blocks from the Grid
    blocks.clear();
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

bool Grid::isNotCollision(Block block, float _x, float _y) {
    // Iterate through all the Blocks on the Grid
    for (unsigned int i = 0; i < blocks.size(); i++) {
        // Default collision boundry values
        float startX = blocks[i].getX();
        float endX = blocks[i].getX();
        float startY = blocks[i].getY();
        float endY = blocks[i].getY();
        float checkX = _x;   // Default for moving left
        float checkY = _y;   // Default for moving up
        if (blocks[i].getVertical()) {
            endY += blocks[i].getHeight();
        } else {
            endX += blocks[i].getWidth();
        }
        // Check for horizontal and vertical Blocks
        if (blocks[i].getX() != block.getX() && _x > 0) {
            endX += tileGap;
            // Calculate for moving right
            if ((prevX + x) - _x < 0) {
                checkX += block.getWidth();
            }
            // Check if collision will occur
            if ((checkX >= startX && checkX <= endX) && (block.getY() >= startY && block.getY() <= endY)) {
                isBlockFree = false;
                return false;
            }
        } else if (blocks[i].getY() != block.getY() && _y > 0) {
            endY += tileGap;
            // Calculate for moving down
            if ((prevY + y) - _y < 0) {
                checkY += block.getHeight();
            }
            // Check if collision will occur
            if ((checkY >= startY && checkY <= endY) && (block.getX() >= startX && block.getX() <= endX)) {
                isBlockFree = false;
                return false;
            }
        }
    }
    return true;    // No collision detected
}

bool Grid::isBounded(float posVal, float length, float uBound, float lBound) {
    return (posVal >= uBound) && (posVal + length <= lBound);
}
