#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "Constants.hpp"
#include "DrawManager.hpp"
using namespace std;

class Button {
	public:
		Button(string, TEXTS, float, float, float, float, SPRITE, SPRITE); // Constructor
		virtual ~Button() {}; // Destructor
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