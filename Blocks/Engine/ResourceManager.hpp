#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <physfs.h>
#include <exception>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "TextAsset.hpp"
#include "SoundAsset.hpp"
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
		void loadImage(string, string);
		void loadSound(string, string);
		// Get basic elements
		Image getImage(string);
        // Create Assets
        SpriteAsset createSprite(string, string);
        TextAsset createText(string, string);
		SoundAsset createSound(string, string);
    private:
        // Primary resources: Textures, Images, SoundBuffers and Fonts
        map<string, Texture> textures;
        map<string, Font> fonts;
		map<string, SoundBuffer> soundBuffers;
		map<string, Image> images;
        // The Physfs input stream
        PhyfsStream archiveStream;
		void openVerifyStream(string);
};

#endif // RESOURCEMANAGER_HPP
