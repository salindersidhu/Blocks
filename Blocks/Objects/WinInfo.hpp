#ifndef WININFO_HPP
#define WININFO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "CoreObject.hpp"
using namespace sf;
using namespace std;

class WinInfo : public CoreObject {
    public:
        // Constructor and destructor
        WinInfo(SaveObject*, Font, Color, float);
        virtual ~WinInfo() {};
        // WinInfo function
        void reset();
        void update();
        void draw(RenderWindow*);
        void onMouseMove(Vector2i) {};
        void onMouseLeftClick(Vector2i) {};
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i) {};
        void onMouseRightRelease(Vector2i) {};
    private:
        // WinInfo private variables
        Font textFont;              // Text Font
        Text congratsText;          // Congratulations display Text
        Text levelCompleteText;     // Level complete display Text
        Text totalTimeText;         // Total time display Text
        Text totalMovesText;        // Total moves display Text
        Color textColor;            // Text colour
        SaveObject *saveObj;        // SaveObject pointer to read save data
        bool isUpdateOnce;          // Is WinInfo only updated once
};

#endif // WININFO_HPP
