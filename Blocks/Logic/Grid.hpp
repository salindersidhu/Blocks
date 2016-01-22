#ifndef GRID_HPP
#define GRID_HPP

#include <string>
#include <vector>
#include "Block.hpp"
using namespace std;

class Grid {
    public:
        // Constructor and destructor
        Grid(float, float, float, float, float, float);
        virtual ~Grid() {};
        // Configure Grid functions
        void addBlock(Block);
        void selectBlock(float, float);
        void releaseBlock(int&);
        void moveBlock(float, float);
        void clear();
        // Get Grid attribute functions
        vector<Block> getBlocks();
        bool isComplete();
    private:
        // Grid functions
        float align(float, float, float);
        bool isHovering(float, float, float, float, float, float);
        bool isNotCollision(Block, float, float);
        bool isBounded(float, float, float, float);
        // Grid variables
        vector<Block> blocks;
        float x;
        float y;
        float width;
        float height;
        float completeX;
        float completeY;
        // Calculation variables for Blocks
        float prevX;
        float prevY;
        float distX;
        float distY;
        bool isBlockMoved;
        bool isBlockFree;
};

#endif // GRID_HPP
