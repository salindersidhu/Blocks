#ifndef FADETRANS_HPP
#define FADETRANS_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class FadeTrans : public GameObject {
    public:
        // Constructor and destructor
        FadeTrans(int, int, int, Color);
        ~FadeTrans();
        // FadeTrans functions
        void onMouseClick(Vector2i) {};
        void onMouseMove(Vector2i) {};
        void onMouseRelease(Vector2i) {}
        void update();
        void draw(RenderWindow*);
        void setFadeIn();
        void setFadeOut();
    private:
        // FreeTrans functions
        void fade(bool, int);
        void setFade(int, int);
        // FadeTrans variables
        RectangleShape *cover;  // The fade transition rectangle
        Color fadeColour;       // The fade transition colour
        int speed;              // Fade transition speed
        int alpha;              // Value between 0 and 255
        int fadeSwitch;         // 0 = Fade in, 1 = Fade out
        bool isComplete;        // Is the fade transition complete
};

#endif // FADETRANS_HPP
