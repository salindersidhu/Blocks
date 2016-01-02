#ifndef BLOCKSGAME_HPP
#define BLOCKSGAME_HPP

#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include "LevelManager.hpp"
#include "DrawManager.hpp"
#include "DialogManager.hpp"
using namespace std;

class BlocksGame {
    public:
        // Constructor and destructor
        BlocksGame();
        virtual ~BlocksGame() {};
    private:
        void loadLevelData(map<int, vector<Block>>&);
        void loadResourceData(DrawManager&);
        sf::RenderWindow window;
		DialogManager *dialog;
        map<int, vector<Block>> levels;
};

#endif
