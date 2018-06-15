#include "ResourceManager.hpp"

void ResourceManager::loadTexture(const unsigned char* src, int size, string id) {
	Texture texture;
	// Load the Texture from the memory
	if (texture.loadFromMemory(src, size)) {
		// Store the Texture
		textures[id] = texture;
	} else {
		// Throw an EngineException
		throw EngineException("Error: Loading Texture " + id);
	}
}

void ResourceManager::loadFont(const unsigned char* src, int size, string id) {
	Font font;
	// Load the Font from the memory
	if (font.loadFromMemory(src, size)) {
		// Store the Font
		fonts[id] = font;
	} else {
		// Throw an EngineException
		throw EngineException("Error: Loading Font " + id);
	}
}

void ResourceManager::loadImage(const unsigned char* src, int size, string id) {
	Image image;
	// Load the Image from the memory
	if (image.loadFromMemory(src, size)) {
		// Store the Image
		images[id] = image;
	} else {
		// Throw an EngineException
		throw EngineException("Error: Loading Image " + id);
	}
}

Image ResourceManager::getImage(string id) {
	// Check if the Image exists
	if (images.find(id) != images.end()) {
		return images[id];
	} else {
		// Throw an EngineException
		throw EngineException("Error: Getting Image " + id);
	}
}

Texture ResourceManager::getTexture(string id) {
	// Check if the Image exists
	if (textures.find(id) != textures.end()) {
		return textures[id];
	} else {
		// Throw an EngineException
		throw EngineException("Error: Getting Texture " + id);
	}
}

Font ResourceManager::getFont(string id) {
	// Check if the Image exists
	if (fonts.find(id) != fonts.end()) {
		return fonts[id];
	} else {
		// Throw an EngineException
		throw EngineException("Error: Getting Font " + id);
	}
}
