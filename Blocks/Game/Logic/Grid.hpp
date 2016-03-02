#ifndef GRID_HPP
#define GRID_HPP

#include <cmath>
#include <string>
#include <vector>
#include "Block.hpp"
using namespace std;

class Grid {
public:
    // Constructor and destructor
    Grid(float, float, float, float, float, float, float);
    virtual ~Grid() {};
    // Grid functions
    void addBlock(Block);
    void selectBlock(float, float);
    void releaseBlock(unsigned int&);
    void moveBlock(float, float);
    void reset();
    bool isComplete();
    vector<Block> getBlocks();
private:
    // Grid private functions
    float align(float, float, float);
    bool isHovering(float, float, float, float, float, float);
    bool isNotCol(Block, float, float);
    bool isBounded(float, float, float, float);
    // Grid private variables
    vector<Block> blocks;       // List of all of the Grid's Blocks
    float x;                    // Grid's x position
    float y;                    // Grid's y position
    float width;                // Grid's width
    float height;               // Grid's height
    float completeX;            // Grid's victory x position
    float completeY;            // Grid's victory y position
    float tileGap;              // Grid's length of gap between Blocks
    float prevX;                // Grid's Block's previous X position
    float prevY;                // Gird's Block's previous Y position
    float distX;                // Grid's Block's distance X positon
    float distY;                // Grid's Block's distance Y position
    bool isBlockMovedVar;       // If a Block on the Grid was moved
    bool isBlockFreeVar;        // If a Block on the Grid is free to move
};

#endif // GRID_HPP
