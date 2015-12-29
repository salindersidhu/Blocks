#ifndef LEVELMANAGER_HPP
#define LEVELMANAGER_HPP

#include <string>
#include <vector>
#include <SFML\Graphics.hpp>
#include "Constants.hpp"
#include "DrawManager.hpp"
#include "Grid.hpp"
#include "ButtonGUI.hpp"
#include "Clock.hpp"
#include "Dialog.hpp"
using namespace std;

class LevelManager {
	public:
		LevelManager(sf::RenderWindow*); // Constructor
		virtual ~LevelManager() {}; // Destructor
		void drawLevel();
		void handleEvents(sf::Event*);
		void handleTimer();
	private:
		void buildLevel();
		void checkLevelCleared();
		void buttonEvent(int, int);
		void buttonHover(int, int);
		int currentLevel;
		int numberOfMoves;
		DrawManager *dm;
		Clock timer;
		Grid grid;
		Dialog *dialog;
		vector<ButtonGUI> buttons;
		sf::RenderWindow *canvasWindow;
};

#endif