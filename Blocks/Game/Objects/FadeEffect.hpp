#ifndef FADEEFFECT_HPP
#define FADEEFFECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreObject.hpp"
using namespace sf;
using namespace std;

class FadeEffect : public CoreObject {
    public:
        // Constructor and destructor
        FadeEffect(int, int, int, Color);
        ~FadeEffect();
        // FadeEffect functions
        void start();
        bool isDone();
        void update();
        void reset() {};
        void draw(RenderWindow*);
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
    private:
        // FadeEffect private variables
        void fade(bool, int);
        void resetFade();
        // FadeEffect private variables
        RectangleShape *cover;  // The fade efect rectangle
        Color fadeColour;       // The fade effect colour
        int speed;              // Fade transition speed
        int alpha;              // Value between 0 and 255
        bool isComplete;        // Is the fade transition complete
};

#endif // FADEEFFECT_HPP
