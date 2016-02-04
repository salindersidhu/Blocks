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
        void releaseBlock();
        void moveBlock(float, float);
        void reset();
        bool isComplete();
        vector<Block> getBlocks();
    private:
        // Grid functions
        float align(float, float, float);
        bool isHovering(float, float, float, float, float, float);
        bool isNotCol(Block, float, float);
        bool isBounded(float, float, float, float);
        // Grid variables
        vector<Block> blocks;
        float x;
        float y;
        float width;
        float height;
        float completeX;
        float completeY;
        float tileGap;
        float prevX;
        float prevY;
        float distX;
        float distY;
        bool isBlockMoved;
        bool isBlockFree;
};

#endif // GRID_HPP
