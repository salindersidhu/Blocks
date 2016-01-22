#include "Grid.hpp"

Grid::Grid(float _x, float _y, float _width, float _height, float _completeX, float _completeY) {
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    completeX = _completeX;
    completeY = _completeY;
}

void Grid::addBlock(Block block) {
    // Add Block to the Grid
    blocks.push_back(block);
}

void Grid::selectBlock(float mX, float mY) {

}

void Grid::releaseBlock(int &numMoves) {

}

void Grid::moveBlock(float mX, float mY) {

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

}

bool Grid::isHovering(float x, float y, float a, float b, float c, float d) {
    return (x >= a && x <= a + c) && (y >= b && y <= b + d);
}

bool Grid::isNotCollision(Block block, float x, float y) {

}

bool Grid::isBounded(float posVal, float length, float uBound, float lBound) {
    return (posVal >= uBound) && (posVal + length <= lBound);
}
