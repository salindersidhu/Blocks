#ifndef BLOCKSGAME_HPP
#define BLOCKSGAME_HPP

#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include "LevelManager.hpp"
#include "DrawManager.hpp"
#include "Dialog.hpp"
#include "Block.hpp"
using namespace std;

class BlocksGame {
    public:
        // Constructor and destructor
        BlocksGame();
        virtual ~BlocksGame() {};
    private:
        void setLevels();
        void loadResources();
        LevelManager *levelMan;
        DrawManager *drawMan;
        Dialog *dialog;
        sf::RenderWindow window;
        map<int, vector<Block>> levels;
};

#endif
