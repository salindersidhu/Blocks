#ifndef GAMEGRID_HPP
#define GAMEGRID_HPP

#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "CoreObject.hpp"
#include "../Logic/Grid.hpp"
#include "../Logic/Block.hpp"
#include "../Logic/MinuteClock.hpp"
using namespace sf;
using namespace std;

class GameGrid : public CoreObject {
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
        // GameGrid private variables
        Font textFont;                  // Information text's Font
        Text infoText;                  // Information Text
        Grid *grid;                     // Grid object pointer
        MinuteClock clock;              // MinuteClock object
        map<string, Texture> textures;  // Map of Block's Textures
        int infoTextY;                  // InfoText's y position
        int winWidth;                   // Window's width
        unsigned int numMoves;          // Number of Block moves
        bool isGridComplete;            // Is the Grid complete
};

#endif // GAMEGRID_HPP
