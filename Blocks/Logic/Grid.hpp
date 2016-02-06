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
        bool getIsComplete();
        vector<Block> getBlocks();
    private:
        // Grid private functions
        float align(float, float, float);
        bool isHovering(float, float, float, float, float, float);
        bool isNotCol(Block, float, float);
        bool isBounded(float, float, float, float);
        // Grid private variables
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
