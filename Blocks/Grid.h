/*
FILENAME:		Grid.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	The main game grid for Blocks, handles all the game control logic.
UPDATE DATE:	10/27/2013
*/

#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>
#include "Constants.h"
#include "DrawManager.h"
using namespace std;

/* BLOCK class */

class Block {
public:
	Block(ORIENTATION, int, int, int, SPRITE, bool); // Constructor
	virtual ~Block() {}; // Destructor
	ORIENTATION orientation;
	int size;
	int x;
	int y;
	bool blockSelected;
	bool isRedBlock;
	SPRITE image;
};

/* Grid class */

class Grid {
public:
	Grid(); // Constructor
	virtual ~Grid() {}; // Destructor
	void configure(DrawManager*);
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
	bool notCollision(Block, int, int);
	bool isBounded(int, int, int, int);
	bool blockMoved;
	bool blockFree;
	int distanceX;
	int distanceY;
	int previousX;
	int previousY;
	vector<Block> blockContainer;
};

#endif