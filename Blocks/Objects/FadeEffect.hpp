#ifndef FADEEFFECT_HPP
#define FADEEFFECT_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class FadeEffect : public GameObject {
    public:
        // Constructor and destructor
        FadeEffect(int, int, int, Color);
        ~FadeEffect();
        // FadeEffect functions
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
        void update();
        void draw(RenderWindow*);
        void start();
        bool isDone();
    private:
        // FadeEffect variables
        void fade(bool, int);
        void resetFade();
        // FadeEffect variables
        RectangleShape *cover;  // The fade efect rectangle
        Color fadeColour;       // The fade effect colour
        int speed;              // Fade transition speed
        int alpha;              // Value between 0 and 255
        bool isComplete;        // Is the fade transition complete
};

#endif // FADEEFFECT_HPP
