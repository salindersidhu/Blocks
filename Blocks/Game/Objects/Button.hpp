#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "CoreObject.hpp"
using namespace sf;
using namespace std;

class Button : public CoreObject {
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
	bool isClicked();
private:
	// ButtonObject private functions
	bool isHovering(int, int);
	// ButtonObject private variables
	bool isMouseOverVar;			// If mouse is over the Button
	bool isClickedVar;				// If Button is clicked
	bool isSelectedVar;				// If Button is hover selected
	bool isPlayHoverSoundVar;		// If hover sound is played
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
