#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP

#include <map>
#include <string>
#include <exception>
#include <SFML\Graphics.hpp>
#include <PHYSFS\physfs.h>
#include "Constants.hpp"
#include "PhyfsStream.hpp"
using namespace std;

/* PhyfsStreamException class */
class PhyfsStreamException : public exception {
	public:
		PhyfsStreamException(string);
		virtual ~PhyfsStreamException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

/* ResourceNotLoadedException class */
class ResourceNotLoadedException : public exception {
	public:
		ResourceNotLoadedException(string, string);
		virtual ~ResourceNotLoadedException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

/* ResourceNotFoundException class */
class ResourceNotFoundException : public exception {
	public:
		ResourceNotFoundException(string, int);
		virtual ~ResourceNotFoundException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

/* DrawManager class */
class DrawManager {
	public:
		DrawManager(sf::RenderWindow*, string*); // Constructor
		virtual ~DrawManager(); // Destructor
		void loadSpriteTexture(SPRITE, string);
		void loadTextFont(TEXTS, string);
		void configSpritePosition(SPRITE, float, float);
		void configText(TEXTS, unsigned int, sf::Color, string, float, float);
		void configTextCenterHorizontal(TEXTS, unsigned int, sf::Color, string, float);
		void configTextCenterRectangle(TEXTS, unsigned int, sf::Color, string, float, float, float, float);
		void drawSprite(SPRITE);
		void drawText(TEXTS);
	private:
		// Store raw resource data objects
		map<SPRITE, sf::Texture> texturesMap;
		map<TEXTS, sf::Font> fontsMap;
		// Store sprite, text and image objects
		map<SPRITE, sf::Sprite> spritesMap;
		map<TEXTS, sf::Text> textsMap;
		map<IMAGE, sf::Image> imageMap;
		// Window to draw on
		sf::RenderWindow *canvasWindow;
		// The PHYSFS custom input stream
		PhyfsStream archiveStream;
};

#endif