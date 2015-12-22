/*
FILENAME:		Main.cpp
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Blocks logic game main application.
DEPENDENCIES:	SFML (Game library [C++]), PHYSFS (Archive handler [C]), OPENSSL (MD5 file checking [C])
UPDATE DATE:	11/05/2013
*/

#include <SFML\Graphics.hpp>
#include "Constants.h"
#include "LevelManager.h"

int main() {

	// Initalize GUI components
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BITS_PER_PIXEL), WINDOW_TITLE, sf::Style::Close);
	window.setFramerateLimit(FRAMERATE);

	// Initalize game logic components
	LevelManager lm(&window);

	// Main game loop
	while(window.isOpen()) {

		// Process all input events
		sf::Event event;
		while (window.pollEvent(event))
		{
			lm.handleEvents(&event);
		}

		// Process the timer
		lm.handleTimer();

		// Process all drawing events
		window.clear();
		lm.drawLevel();
		window.display();
	}

	return EXIT_SUCCESS;
}