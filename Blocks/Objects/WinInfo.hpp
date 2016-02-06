#ifndef WININFO_HPP
#define WININFO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class WinInfo : public GameObject {
    public:
        // Constructor and destructor
        WinInfo(Font, Color, float);
        virtual ~WinInfo() {};
        // WinInfo function
        void reset() {};
        void update() {};
        void draw(RenderWindow*);
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
    private:
        // WinInfo private functions
		void centerText(Text*, float, float);
        // WinInfo private variables
        Font textFont;
        Text congratsText;
        Text levelCompleteText;
        Text totalTimeText;
        Text totalMovesText;
        Color textColor;
};

#endif // WININFO_HPP
