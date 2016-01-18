#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <physfs.h>
#include <exception>
#include <SFML/Graphics.hpp>
#include "TextAsset.hpp"
#include "SpriteAsset.hpp"
#include "PhysfsStream.hpp"
using namespace sf;
using namespace std;

class PhysfsStreamException : public exception {
	public:
		PhysfsStreamException(string);
		virtual ~PhysfsStreamException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

class ResourceException : public exception {
	public:
		ResourceException(string _message) {message = _message;};
		virtual ~ResourceException() throw() {};
		const char *what() const throw() {return message.c_str();};
	private:
		string message;
};

class ResourceManager {
    public:
        // Constructor and destructor
		ResourceManager(string);
        virtual ~ResourceManager();
        // Load basic elements
        void loadTexture(string, string);
        void loadFont(string, string);
        // Create Assets
        SpriteAsset createSprite(string, string);
        TextAsset createText(string, string);
    private:
        // Primary resource, textures and fonts
        map<string, Texture> textures;
        map<string, Font> fonts;
        // The Physfs input stream
        PhyfsStream archiveStream;
};

#endif // RESOURCEMANAGER_HPP
