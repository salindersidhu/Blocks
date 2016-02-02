#ifndef FADEOUT_HPP
#define FADEOUT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class FadeOut : public GameObject {
    public:
        // Constructor and destructor
        FadeOut(int, int, int, Color);
        ~FadeOut();
        // FadeOut functions
        void onMouseClick(Vector2i) {};
        void onMouseMove(Vector2i) {};
        void onMouseRelease(Vector2i) {}
        void update();
        void draw(RenderWindow*);
        void start();
        bool isDone();
    private:
        // FadeOut variables
        void fade(bool, int);
        // FadeOut variables
        RectangleShape *cover;  // The fade transition rectangle
        Color fadeColour;       // The fade transition colour
        int speed;              // Fade transition speed
        int alpha;              // Value between 0 and 255
        int fadeSwitch;         // 0 = Fade in, 1 = Fade out
        bool isComplete;        // Is the fade transition complete
};

#endif // FADEOUT_HPP
