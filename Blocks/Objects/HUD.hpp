#ifndef HUD_HPP
#define HUD_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class HUD : public GameObject {
    public:
        // Constructor and destructor
        HUD(string, float, float, int, Color, Font, Texture);
        virtual ~HUD() {};
        // HUD function
        void reset() {};
        void update() {};
        void draw(RenderWindow*);
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
    private:
        // HUD private functions
		void centerTitleText(float, float);
        // HUD private variables
        Texture bgTexture;
        Sprite bgSprite;
        Font textFont;
        Text titleText;
        Color textColor;
};

#endif // HUD_HPP
