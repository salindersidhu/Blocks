/*
FILENAME:		LevelManager.cpp
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Manages the game specific level content and controls for Blocks.
UPDATE DATE:	10/29/2013
*/

#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "DrawManager.h"
#include "Grid.h"
#include "ButtonGUI.h"
#include "WindowsDialogs.h"
#include "MinuteClock.h"
using namespace std;

class LevelManager {
public:
	LevelManager(sf::RenderWindow*); // Constructor
	virtual ~LevelManager() {}; // Destructor
	void drawLevel();
	void handleEvents(sf::Event*);
	void handleTimer();
private:
	void buildLevel();
	void checkLevelCleared();
	void buttonEvent(int, int);
	void buttonHover(int, int);
	int currentLevel;
	int numberOfMoves;
	DrawManager *dm;
	WindowsDialogs *dialog;
	MinuteClock timer;
	Grid grid;
	vector<ButtonGUI> buttons;
	sf::RenderWindow *canvasWindow;
};

#endif