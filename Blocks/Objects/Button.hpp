#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class Button : public GameObject {
	public:
		// Constructor and destructor
		Button(string, int, Font, Texture, Texture);
		virtual ~Button() {};
		// ButtonObject functions
		void setSounds(SoundBuffer, SoundBuffer);
		void setColours(Color, Color);
		void setPosition(float, float);
		void onMouseLeftClick(Vector2i);
		void onMouseRightClick(Vector2i) {};
		void onMouseMove(Vector2i);
		void onMouseLeftRelease(Vector2i) {};
		void onMouseRightRelease(Vector2i) {};
		void reset() {};
		void update();
		void draw(RenderWindow*);
		// Get Button attribute functions
		bool getIsClicked();
	private:
		// ButtonObject private functions
		bool isHovering(int, int);
		void centerButtonText(float, float, float, float);
		// ButtonObject private variables
		bool isMouseOver;				// If mouse is over the Button
		bool isClicked;					// If Button is clicked
		bool isSelected;				// If Button is hover selected
		bool isPlayHoverSound;			// If hover sound is played
		Texture buttonNormalTexture;	// Button's normal Texture
		Texture buttonHoverTexture;		// Button's hover Texture
		Sprite buttonNormalSprite;		// Button's normal Sprite
		Sprite buttonHoverSprite;		// Button's hover Sprite
		Font textFont;					// Button's text Font
		Text buttonText;				// Button's Text
		Color normalColour;				// Button's normal text colour
		Color hoverColour;				// Button's hover text colour
		SoundBuffer hoverBuffer;		// Button's hover sound buffer
		SoundBuffer clickBuffer;		// Button's click sound buffer
		Sound hoverSound;				// Button's hover sound
		Sound clickSound;				// Button's click sound
};

#endif // BUTTON_HPP
