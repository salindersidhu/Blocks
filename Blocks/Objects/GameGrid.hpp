#ifndef GAMEGRID_HPP
#define GAMEGRID_HPP

#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "../Logic/Grid.hpp"
#include "../Logic/Block.hpp"
#include "../Engine/GameObject.hpp"
#include "../Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

class GameGrid : public GameObject {
    public:
        // Constructor and destructor
        GameGrid(float, float, float, float, float, float, float,
            ResourceManager*);
        ~GameGrid();
        // GameGrid functions
        void onMouseMove(Vector2i);
        void onMouseLeftClick(Vector2i);
        void onMouseRightClick(Vector2i) {};
        void onMouseLeftRelease(Vector2i);
        void onMouseRightRelease(Vector2i) {};
        void update() {};
        void draw(RenderWindow*);
        void addBlock(string, float, float, float, float, float, bool, bool);
        void setNumMoves(unsigned int*);
        void reset();
    private:
        // GameGrid variables
        Grid *grid;
        map<string, Texture> textures;
        unsigned int *numMoves;
};

#endif // GAMEGRID_HPP
