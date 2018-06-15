#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "EngineException.hpp"
using namespace sf;
using namespace std;

class ResourceManager {
public:
    // Load basic game elements
    void loadTexture(const unsigned char*, int, string);
    void loadFont(const unsigned char*, int, string);
    void loadImage(const unsigned char*, int, string);
    // Get basic game elements
    Texture getTexture(string);
    Font getFont(string);
    Image getImage(string);
private:
    map<string, Texture> textures;          // Map of Textures
    map<string, Font> fonts;                // Map of Fonts
    map<string, Image> images;              // Map of Images
};

#endif // RESOURCEMANAGER_HPP
