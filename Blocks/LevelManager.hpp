#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "DrawManager.hpp"
#include "Grid.hpp"
#include "Button.hpp"
#include "Clock.hpp"
#include "DialogManager.hpp"
using namespace std;

class LevelManager {
	public:
        // Constructor and destructor
		LevelManager(sf::RenderWindow*, DrawManager*, DialogManager*, map<int, vector<Block>>);
		virtual ~LevelManager() {};
		void drawLevel();
        void handleInputEvents(sf::Event*);
        void handlePassiveEvents();
	private:
        void createLevel();
        void handleLevelcleared();
		void buttonClickEvents(int, int);
		void buttonHoverEvents(int, int);
		int currentLevel;
		int numMoves;
        sf::RenderWindow *window;
		DrawManager *drawMan;
		DialogManager *dialog;
		Clock clock;
		Grid *grid;
		vector<Button> buttons;
        map<int, vector<Block>> levels;
};

#endif
