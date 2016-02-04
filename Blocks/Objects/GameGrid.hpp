#ifndef GAMEGRID_HPP
#define GAMEGRID_HPP

#include <string>
#include <SFML/Graphics.hpp>
#include "../Logic/Grid.hpp"
#include "../Logic/Block.hpp"
#include "../Engine/GameObject.hpp"
using namespace sf;
using namespace std;

class GameGrid : public GameObject {
    public:
        // Constructor and destructor
        GameGrid(float, float, float, float, float, float, float);
        ~GameGrid();
        // GameGrid functions
        void onMouseClick(Vector2i);
        void onMouseMove(Vector2i);
        void onMouseRelease(Vector2i);
        void update();
        void draw(RenderWindow*);
        void addBlock(Texture, float, float, bool, bool);
    private:
        // GameGrid variables
        Grid *grid;
};

#endif // GAMEGRID_HPP
