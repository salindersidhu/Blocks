#ifndef GRID_HPP
#define GRID_HPP

#include <string>
#include <vector>
#include "Block.hpp"
#include "DrawManager.hpp"
using namespace std;

/* Grid class */
class Grid {
	public:
		// Constructor and destructor
		Grid(int, int, int, int, int, int);
		virtual ~Grid() {};
		void set(DrawManager*);
		void draw(DrawManager*);
		void addBlock(Block);
		void selectBlock(int, int);
		void releaseBlock(int&);
		void moveBlock(int, int);
		void clear();
		bool isVictory();
	private:
		void alignBlock(int, int&, int);
		bool isHovering(int, int, int, int, int, int);
		bool isNotCollision(Block, int, int);
		bool isBounded(int, int, int, int);
		bool isBlockMoved;
		bool isBlockFree;
		int distanceX;
		int distanceY;
		int previousX;
		int previousY;
        int gridX;
        int gridY;
        int gridEndX;
        int gridEndY;
        int posIncr;
		int blockVictoryPos;
		vector<Block> blocks;
};

#endif
