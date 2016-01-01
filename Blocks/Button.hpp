#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "DrawManager.hpp"
using namespace std;

class Button {
	public:
		// Constructor and destructor
		Button(DrawManager*, string, string, unsigned int, string, string, string, sf::Color, sf::Color, float, float, float, float);
		virtual ~Button() {};
		bool isHovering(int, int);
		bool isSelected(string, int, int);
		void set(DrawManager*);
		void draw(DrawManager*);
	private:
		string buttonText;
		string buttonTextName;
		string spriteName;
		string spriteSelectedName;
		sf::Color buttonNormalColour;
		sf::Color buttonHoverColour;
		int buttonTextSize;
		float buttonWidth;
		float buttonHeight;
		float buttonX;
		float buttonY;
		bool isMouseOver;
	};

#endif
