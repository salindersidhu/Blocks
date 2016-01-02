#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "DrawManager.hpp"
using namespace std;

class Button {
	public:
		// Constructor and destructor
        Button(string, string, string, string, sf::Color, sf::Color, unsigned int, float, float, float, float);
		virtual ~Button() {};
		bool isHovering(int, int);
		bool isSelected(string, int, int);
		void set(DrawManager&);
		void draw(DrawManager&);
	private:
		string buttonText;
		string buttonFontName;
		string buttonNormalTexture;
		string buttonHoverTexture;
        string buttonNormalSprite;
        string buttonHoverSprite;
		sf::Color buttonNormalColour;
		sf::Color buttonHoverColour;
		int buttonFontSize;
		float buttonWidth;
		float buttonHeight;
		float buttonX;
		float buttonY;
		bool isMouseOver;
	};

#endif
