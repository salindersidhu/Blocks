#ifndef DRAWMANAGER_HPP
#define DRAWMANAGER_HPP

#include <map>
#include <string>
#include <exception>
#include <SFML\Graphics.hpp>
#include <PHYSFS\physfs.h>
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
		ResourceNotFoundException(string, string);
		virtual ~ResourceNotFoundException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

/* DrawManager class */
class DrawManager {
	public:
		// Constructor and destructor
		DrawManager(sf::RenderWindow*, string*);
		virtual ~DrawManager();
		// Create drawing element functions
		void createSprite(string, string);
		void createText(string, string);
		void createImage(string, string);
		// Configure drawing element functions
		void setSprite(string, float, float);
		void setText(string, unsigned int, sf::Color, string, float, float);
		void centerTextHorizontal(string, float, float);
		void centerTextRectangle(string, float, float, float, float);
		// Draw functions
		void drawSprite(string);
		void drawText(string);
		// Get drawing element functions
		sf::Sprite getSprite(string);
		sf::Text getText(string);
		sf::Image getImage(string);
	private:
		// Map of sprites, text and images
		map<string, sf::Sprite> sprites;
		map<string, sf::Text> text;
		map<string, sf::Image> images;
		// Pointer to canvas to draw on
		sf::RenderWindow *canvas;
		// The PhySFS input stream
		PhyfsStream archiveStream;
};

#endif
