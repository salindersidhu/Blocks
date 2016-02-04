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
        // HUD functions
        void onMouseClick(Vector2i) {};
        void onMouseMove(Vector2i) {};
        void onMouseRelease(Vector2i) {};
        void update() {};
        void draw(RenderWindow*);
    private:
        // HUD functions
		void centerText(float, float);
        // HUD variables
        Texture bgTexture;
        Sprite bgSprite;
        Font textFont;
        Text titleText;
        Color textColor;
};

#endif // HUD_HPP
