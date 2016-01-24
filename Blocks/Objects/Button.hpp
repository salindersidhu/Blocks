#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class Button : public GameObject {
	public:
        // Constructor and destructor
        Button(string, unsigned int, float, float, Color, Color, Font, Texture, Texture);
        virtual ~Button() {};
        // ButtonObject functions
        void onMouseClick(Vector2i);
        void onMouseMove(Vector2i);
        void onMouseRelease(Vector2i) {}
        void update() {};
        void draw(RenderWindow*);
        // Get Button attribute functions
		bool getClicked();
    private:
        // ButtonObject functions
        bool isHovering(int, int);
        void centerText(float, float, float, float);
        // ButtonObject variables
        bool isMouseOver;
		bool isClicked;
		Texture buttonNormalTexture;
		Texture buttonHoverTexture;
        Sprite buttonNormalSprite;
        Sprite buttonHoverSprite;
        Font textFont;
        Text buttonText;
        Color normalColour;
        Color hoverColour;
};

#endif // BUTTON_HPP
