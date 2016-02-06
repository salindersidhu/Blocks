#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <physfs.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "PhysfsStream.hpp"
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class ResourceManager {
    public:
        // Constructor and destructor
		ResourceManager(string);
        virtual ~ResourceManager();
        // Load basic game elements
        void loadTexture(string, string);
        void loadFont(string, string);
		void loadImage(string, string);
		void loadSound(string, string);
		// Get basic game elements
        Texture getTexture(string);
        Font getFont(string);
		Image getImage(string);
        SoundBuffer getSound(string);
    private:
        // ResourceManager private functions
		void openVerifyStream(string);
        // ResourceManager private variables
        map<string, Texture> textures;
        map<string, Font> fonts;
		map<string, SoundBuffer> soundBuffers;
		map<string, Image> images;
        PhyfsStream archiveStream;
};

#endif // RESOURCEMANAGER_HPP
