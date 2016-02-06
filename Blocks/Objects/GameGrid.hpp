#ifndef GAMEGRID_HPP
#define GAMEGRID_HPP

#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "../Logic/Grid.hpp"
#include "../Logic/Block.hpp"
#include "../Logic/MinuteClock.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class GameGrid : public GameObject {
    public:
        // Constructor and destructor
        GameGrid(float, float, float, float, float, float, float, int, int,
            ResourceManager*);
        ~GameGrid();
        // GameGrid functions
        void onMouseMove(Vector2i);
        void onMouseLeftClick(Vector2i);
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i);
        void onMouseRightRelease(Vector2i) {};
        void update();
        void draw(RenderWindow*);
        void addBlock(string, float, float, float, float, float, bool, bool);
        void reset();
        unsigned int getNumMoves();
        string getClockTime();
        bool getIsGridComplete();
    private:
        // GameGrid functions
        void centerInfoText();
        // GameGrid variables
        Font textFont;
        Text infoText;
        Grid *grid;
        MinuteClock clock;
        map<string, Texture> textures;
        int infoTextY;
        int winWidth;
        unsigned int numMoves;
        bool isGridComplete;
};

#endif // GAMEGRID_HPP
