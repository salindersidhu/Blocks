#ifndef BUTTONGUI_HPP
#define BUTTONGUI_HPP

#include <string>
#include "Constants.hpp"
#include "DrawManager.hpp"
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