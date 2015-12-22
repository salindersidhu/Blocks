/*
FILENAME:		ButtonGUI.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	The framework for a simple GUI button interface.
UPDATE DATE:	10/27/2013
*/

#ifndef BUTTONGUI_H
#define BUTTONGUI_H

#include <string>
#include "Constants.h"
#include "DrawManager.h"
using namespace std;

class ButtonGUI {
public:
	ButtonGUI(string, TEXTS, float, float, float, float, SPRITE, SPRITE); // Constructor
	virtual ~ButtonGUI() {}; // Destructor
	bool hovering(int, int);
	bool selected(int, int, SPRITE);
	void configure(DrawManager*);
	void draw(DrawManager*);
private:
	string buttonText;
	TEXTS buttonFont;
	float buttonWidth;
	float buttonHeight;
	float buttonPositionX;
	float buttonPositionY;
	bool mouseHovering;
	SPRITE imageNormal;
	SPRITE imageSelected;
};

#endif