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
        void update();
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
		bool isSelected;
		bool isPlayHoverSound;
		Texture buttonNormalTexture;
		Texture buttonHoverTexture;
        Sprite buttonNormalSprite;
        Sprite buttonHoverSprite;
        Font textFont;
        Text buttonText;
        Color normalColour;
        Color hoverColour;
		SoundBuffer hoverBuffer;
		SoundBuffer clickBuffer;
		Sound hoverSound;
		Sound clickSound;
};

#endif // BUTTON_HPP
