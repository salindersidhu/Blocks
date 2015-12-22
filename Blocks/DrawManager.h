/*
FILENAME:		DrawManager.h
AUTHOR:			Salinder Sidhu
DESCRIPTION:	Handle all drawing functionality for Blocks. This class uses the PHYSFS system to load resources from archives.
UPDATE DATE:	12/22/2015
*/

#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include <map>
#include <string>
#include <exception>
#include <SFML\Graphics.hpp>
#include <PHYSFS\physfs.h>
#include "Constants.h"
#include "PhyfsStream.h"
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
	// Store sprite and text objects
	map<SPRITE, sf::Sprite> spritesMap;
	map<TEXTS, sf::Text> textsMap;
	// Window to draw on
	sf::RenderWindow *canvasWindow;
	// The PHYSFS custom input stream
	PhyfsStream archiveStream;
};

#endif