#ifndef GAMEINFO_HPP
#define GAMEINFO_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Engine/GameObject.hpp"
#include "../Logic/MinuteClock.hpp"
using namespace sf;
using namespace std;

class GameInfo : public GameObject {
    public:
        // GameInfo and destructor
        GameInfo(float, float, int, Color, Font);
        virtual ~GameInfo() {};
        // GameInfo functions
        void onMouseClick(Vector2i) {};
        void onMouseMove(Vector2i) {};
        void onMouseRelease(Vector2i) {}
        void update();
        void draw(RenderWindow*);
        void setNumMoves(unsigned int);
		MinuteClock* getClock();
    private:
        // GameInfo functions
		void centerText(float, float);
        // GameInfo variables
        Font textFont;
        Text infoText;
        MinuteClock clock;
        float winWidth;
        float posY;
        unsigned int numMoves;
};

#endif // GAMEINFO_HPP
